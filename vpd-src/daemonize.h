#ifndef DAEMONIZE_H_INCLUDED
#define DAEMONIZE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include "../Sockets/ServerSocket.h"
#include "../Sockets/SocketException.h"


class VirtualPet
{
    public:
        void modifyStats(int statType,int amountChanged);
        int ageTimeout;
        int statGet(int statType) {return stats[statType];}
        void parseCommands(std::string);
        int thingReturn(int);
        std::string stringReturn();
        VirtualPet();
    private:
        void dataRead();
        void dataWrite();
        void dataCheck();
        void mainLoop();
        int returnThings[2];
        int stats[5];
        int dStats[4];

};

int daemonize();

#endif // DAEMONIZE_H_INCLUDED
