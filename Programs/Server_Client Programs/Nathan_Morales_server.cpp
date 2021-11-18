/* 
Name: Nathan Morales 
Course#: 14930
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int PORT;
    //Reading test Results file and creating a vectors to store the data in
    string fileText;
    vector<string> results;
    vector<string> testCodeList;
    vector<string> birthDateList;
    vector<char> testResultList;
    ifstream resultsFile("testResults20.txt");
    //cout << "Getting Input from file..." << endl;
    while (getline (resultsFile, fileText))
    {
        testCodeList.push_back(fileText.substr(0, fileText.find_first_of(' ')));
        fileText.erase(0, 10);
        birthDateList.push_back(fileText.substr(0, fileText.find_first_of(' ')));
        testResultList.push_back(fileText.back());
        results.push_back(fileText);
    }

    //Add blank space to everyelement in birthdateList because changing the blank space in the message causes issues and we dont like those 
    for (int i = 0; i < birthDateList.size(); i++)
    {
        birthDateList[i].insert(0, " ");
    }

    /*
    for (string i : birthDateList)
    {
        cout << i << endl;
    }
    */
    resultsFile.close();
    /* //Test output to make sure the input is being stored properly
    cout << "Outputing Test Codes..." << endl;
    for (string i : testCodeList)
    {
        cout << i << endl;
    }

    cout << "Outputing Birth dates..." << endl;
    for (string i : birthDateList)
    {
        cout << i << endl;
    }

    cout << "Outputing Test Results..." << endl;
    for (char i : testResultList)
    {
        cout << i << endl;
    }

    cout << "Outputing file content..." << endl;
    for (string i : results)
    {
        cout << i << endl;
    }
    */

    //Obtaining port number from user for server
    cout << "Enter the Server Port Number: " << endl;
    cin >> PORT;

    //Make sure port number is valid
    while (PORT < 1024)
        {
            cout << "Please Enter a valid Port Number: " << endl;
            cin >> PORT;
        }

    //Server Setup
    int serverFileDesc;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    
    //Creating socket
    if ((serverFileDesc = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Error creating Socket...");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    //Attach socket to port
    if (bind(serverFileDesc, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Couldn't Bind to Port...");
        return -1;
    }
    
    if (listen(serverFileDesc, 1) < 0)
    {
        perror("Error Listening");
        return -1;
    }
    
    while(true)
    {
        //Wait for message from client
        string result;
        int socket = accept(serverFileDesc, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (socket < 0)
        {
            perror("Incoming Connection Request Failed");
            return -1;
        }

        char b[1024];
        int message = read(socket, b, 1024);
        //printf("%s\n", b);

        //Break message into 2 parts
        string client_message(b);
        string testCode = client_message.substr(0, client_message.find_first_of(' '));
        string birthDate = client_message.substr(client_message.find_first_of(' '), client_message.find_last_of(' '));

        //Output Messages Recieved
        //cout << "Client_Message: " << client_message << endl;
        cout << "Test Code Recieved: " << testCode << endl;
        cout << "Birthday Recieved: " << birthDate << endl;

        //Check to see if recieved info is in database
        int resultIndex;
        char testResult;
        bool testCodeMatch = false;
        bool birthDateMatch = false;
        bool match = false;

        for (int i = 0; i < testCodeList.size(); i++)
        {
            //cout << "Test Code" << testCodeList[i] << endl;
            if (testCodeList[i].compare(testCode) == 0)
            {
                //cout << "Test Code Match" << endl;
                resultIndex = i;
                //testResult = testResultList[resultIndex];
                testCodeMatch = true;
                break;
            }else 
            {   
                testCodeMatch = false;
                //testResult = 'T';
            }

        }

        for (int i = 0; i < birthDateList.size(); i++)
        {
            //cout << "Checking birthdate:" << birthDateList[i] << " from database " << endl; 
            if (birthDateList[i].compare(birthDate) == 0)
            {
                //cout << "Birth Date Match" << endl;
                birthDateMatch = true;
                break;
            }else 
            {
                birthDateMatch = false;
            }
        }

        if ((birthDateMatch == true) && (testCodeMatch == true))
        {
            testResult = testResultList[resultIndex];
        }else 
        {
            testResult = 'X';
        }

        //Send Message Back to Client
        cout << "Test Result: " << testResult << endl;
        string server_message;


        if (testResult == 'N')
        {
            server_message = "Your test result was NEGATIVE.";
            send(socket, server_message.c_str(), server_message.length(), 0);
        }else if (testResult == 'P')
        {
            server_message = "Your test result was POSITIVE.";
            send(socket, server_message.c_str(), server_message.length(), 0);
        }else 
        {
            server_message = "The Test result you requested is not in our database.";
            send(socket, server_message.c_str(), server_message.length(), 0);
        }
       
    }
    
    return 0;
    
}
