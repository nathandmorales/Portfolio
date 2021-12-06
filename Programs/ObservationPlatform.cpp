/*
Nathan Morales 
PSID: 1873615
HOMEWORK ASSIGNMENT 3 
COSC 3360
Simulates a small observation platform that monitors visitor behavior.
*/
#include <pthread.h>
#include <thread>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <chrono> 
#include <mutex> 
#include <signal.h>
using namespace std;

//Shared Variables
static int nVisitorsOnPlatform = 0;
static int nVisitors = 0;
static int nHadToWait = 0; 
static pthread_mutex_t ladder;
static pthread_cond_t clear = PTHREAD_COND_INITIALIZER;
static int nLadder = 0;

//Struct for Visitors
struct Visitor
{
    string name; //Nickaname for visitor
    int aTime; //Arrival Time delay
    int cTime; //Climb up time
    int pTime; //Platform time
    int dTime; //Climb down time
};

//Simple sleep function to make calling sleep easier and quicker.
void sleep(int i)
{
    std::this_thread::sleep_for (std::chrono::seconds(i));
}

//Thread Function for making child threads. 
void *visitor(void *arg)
{
    //Copies Visitor data
    struct Visitor *vData = (struct Visitor* ) arg;
    cout << vData->name << " arrives at the platform." << endl;
    pthread_mutex_lock(&ladder);

    //Checks for max number of people on ladder and platform.
    if (nVisitorsOnPlatform == 3)
    {
        nHadToWait += 1;
        while(nVisitorsOnPlatform == 3 || nLadder == 1)
        {
            pthread_cond_wait(&clear, &ladder);
        }
    }

    //Visitors climbing up the ladder
    cout << vData->name << " climbs the ladder." << endl;
    nLadder += 1;
    sleep(vData->cTime);
    nLadder -= 1;
    cout << vData->name << " is on the platform." << endl;
    nVisitorsOnPlatform += 1;
    pthread_mutex_unlock(&ladder);
    pthread_cond_signal(&clear);
    sleep(vData->pTime);
    pthread_mutex_lock(&ladder);
    //Visitors deciding to leave and climbing down the ladder. 
    cout << vData->name << " decides to leave." << endl;
    nVisitorsOnPlatform -= 1;
     while (nLadder == 1)
    {
        pthread_cond_wait(&clear, &ladder);
    }

    //Visitors leaving and going down the ladder
    nLadder += 1;
    cout << vData->name << " goes down the ladder." << endl;
    sleep(vData->dTime);
    nLadder -= 1;
    pthread_mutex_unlock(&ladder);
    pthread_cond_signal(&clear);
    cout << vData->name << " leaves." << endl;
    pthread_exit((void*) 0);
}


int main()
{
    //Intialize variables for new visitors
    string name;
    int aTime, cTime, pTime, dTime;
    pthread_mutex_init(&ladder, NULL);
    vector<pthread_t*> vtid;

    //I/O redirection
    while (cin >> name >> aTime >> cTime >> pTime >> dTime)
    {
        Visitor* curVis = new Visitor();
        curVis->name = name;
        curVis->aTime = aTime;
        curVis->cTime = cTime;
        curVis->pTime = pTime;
        curVis->dTime = dTime;
        sleep(curVis->aTime);
        pthread_t* tid = new pthread_t;
        vtid.push_back(tid);
        pthread_create(tid, NULL, visitor,(void *) curVis);
        nVisitors += 1;
    }

    for (int i = 0; i < nVisitors; i++)
    {
        pthread_join(*vtid[i], NULL);
    }

    //Outputting final results. 
    cout << "Total Visitors: " << nVisitors << endl;
    cout << "Visitors that had to wait: " << nHadToWait << endl;

    return 0; 
}