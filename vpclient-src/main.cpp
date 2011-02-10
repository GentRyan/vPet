#include "../Sockets/ClientSocket.h"
#include "../Sockets/SocketException.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROUNDTIME 1000

using namespace std;

int stats[4];

void parser(std::string message);

int main()
{

    ClientSocket client_socket ( "localhost", 30000 );
    daemon(0,0);
    chdir("/home/bit");
    std::string reply;
    srand(time(NULL));
    int ageTimeout= 0;
    int year = 0;
    while (true)
        {
            if (year > 43200) {client_socket << "m 3 1";} //Test to see if pet is one year(half day) older
            client_socket << "d";
            client_socket >> reply;
            parser(reply);
            //insert food time

            ((ageTimeout = stats[3] * 15) > 7200) ? (ageTimeout = 7200 + (rand() % 10 + 5)) : ageTimeout = stats[3] * 599 + (rand() % 10 + 5);
            sleep(ageTimeout);
            client_socket << "m 0 -1";
            client_socket >> reply;
            parser(reply);
            year += ageTimeout;

            if (year > 43200) {client_socket << "m 3 1";}
            sleep(ageTimeout-(ageTimeout/2));
            client_socket << "m 1 -1";
            client_socket >> reply;
            parser(reply);
            year += ageTimeout;

            if (year > 43200) {client_socket << "m 3 1";}

        }
    return 0;
}

void parser(std::string message)
{
    const char * newMessage = message.c_str();
    stats[0] = newMessage[0] - '0';
    stats[1] = newMessage[1] - '0';
    stats[2] = newMessage[2] - '0';
    stats[3] = newMessage[3] - '0';

}
