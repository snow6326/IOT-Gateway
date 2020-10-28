#include <iostream>
#include <string>
#include "Network.h"

using namespace std;

// Network parameter
#define INTERFACE AF_INET
#define PROTOCOL SOCK_STREAM
#define IP_ADDRESS "0.0.0.0"
#define PORT 7777

int main (void)
{
	// Setup smarthome TCP data exchanging server
	string ip_addr(IP_ADDRESS);
	Network network = Network(INTERFACE, PROTOCOL, 0, ip_addr, PORT);
	network.socket_init();
	return 0;
}
