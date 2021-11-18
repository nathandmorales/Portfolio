/* 
Name: Nathan Morales 
Course#: 14930
*/
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
    {
        //Getting the hostname
        char hostbuffer[256];
        int hostname;
        hostname = gethostname(hostbuffer, sizeof(hostbuffer));

        //Obtaining server host name and variable intialization
        int PORT;
        string testCode, birthDate;
        string hostName;
        cout << "Enter Server Host Name: " << endl;
        cin >> hostName;

        //Make sure host name is valid
        while ((hostName != hostbuffer) && (hostName.compare("localhost") != 0))
        {
            cout << "This user does not have access, please enter a valid host name..." << endl;
            cout << "Enter Server Host Name: " << endl;
            cin >> hostName;
        }
        
        //Obtaining port number to connect to 
        cout << "Enter Port Number: " << endl;
        cin >> PORT;

        //Make sure port number is valid 
        while (PORT < 1024)
        {
            cout << "Please Enter a valid Port Number: " << endl;
            cin >> PORT;
        }

    //Establish socket and connect to server
    int sock = 0;
    int server_Message;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error Creating Socket...\n");
        return -1;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
     if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) 
    {
        printf("\nInvalid Address...\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nConnection Failed...\n");
        return -1;
    }

    //User Input for test code and birthday 
    cout << "Enter a Test Code: " << endl;
    cin >> testCode;
    cout << "Enter a Birthdate in MMDDYYYY format: " << endl;
    cin >> birthDate;

    //Combine both strings to make one message to send both values to server
    string clientMessage = testCode + " " + birthDate;

    //Send message to server
    send(sock, clientMessage.c_str(), clientMessage.length(), 0);
    //printf("Message Sent to server\n");
    server_Message = read(sock, buffer, 1024);
    printf("%s\n",buffer);

    return 0;
    
    }