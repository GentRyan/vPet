#include <iostream>
#define ROUNDTIME 100
#include "daemonize.h"
using namespace std;

int main(int argc, char* argv[])
{
    VirtualPet demon;
    std::cout << "Starting Virtual Pet Daemon" << endl;
    daemon(0,0);
    chdir(getenv("HOME"));
  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

    while ( true )
	{
      demon.modifyStats(0,0);
	  ServerSocket new_sock;
	  server.accept ( new_sock );
	  try
	    {
            while ( true )
                {
                std::string commands;
                new_sock >> commands;
                cout << commands << endl;
                demon.parseCommands(commands);
                new_sock << demon.stringReturn();
                }
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
