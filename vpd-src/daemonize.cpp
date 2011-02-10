#include "daemonize.h"
#include <fstream>
void VirtualPet::dataRead()
{
    char * pHome;
    pHome = getenv ("HOME");
    std::ifstream indat("vpet.txt");
    indat >> stats[0];
    indat >> stats[1];
    indat >> stats[2];
    indat >> stats[3];
    indat.close();
}

void VirtualPet::dataWrite()
{
    char * pHome;
    pHome = getenv ("HOME");
    std::ofstream outdat("vpet.txt");
    outdat << stats[0] << std::endl;
    outdat << stats[1] << std::endl;
    outdat << stats[2] << std::endl;
    outdat << stats[3];
    outdat.close();
}

VirtualPet::VirtualPet()
{
    dataRead();
    (stats[3] != 0) ? ageTimeout= stats[3] * 15 : ageTimeout = 10;
    returnThings = {0,0};

}

void VirtualPet::modifyStats(int statType, int adjustment)
{
    dataRead();
    stats[statType] += adjustment;
    if (stats[2] < 5) stats[2] = 5;
    if (stats[0] > 9) stats[0] = 9;
    if (stats[1] > 9) stats[1] = 9;
    if (stats[0] > 99) stats[3] = 99;
    if (stats[2] > 99) stats[2] = 99;

    dataWrite();
}

void VirtualPet::parseCommands(std::string commands)
{

    dataRead();
    const char * newCommands = commands.c_str();
    for (int i = 0; i < 6; i++)
    {
        if (newCommands[i] == 'm')
        {
            int a,b;
            char junk = 'a';
            sscanf(newCommands,"%c %d %d",&junk,&a,&b);
            modifyStats(a,b);
        }
        if (newCommands[i] == 'd')
        {
            *dStats = *stats;

        }
    }
}

int VirtualPet::thingReturn(int thing)
{
    int a = returnThings[thing];
    returnThings[thing] = 0;
    return a;
}

std::string VirtualPet::stringReturn()
{
    char agra[9];
    sprintf(agra,"%d %d %d %d",stats[0],stats[1],stats[2],stats[3]);
    std::string raga(agra);
    return raga;
}
