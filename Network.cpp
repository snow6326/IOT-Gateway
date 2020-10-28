#include "Network.h"

// Network constructor
Network::Network(int domain, int type, int protocol, string &ip, int port)
{
	this->domain = domain;
	this->type = type;
	this->protocol = protocol;
	this->address.sin_family = domain;

	// Convert the port number to the network byte order (Big-Endian)
	this->address.sin_port = htons(port);

	// Convert the string address to the network address in binary form
	if (ip.compare("0.0.0.0") == 0)
		this->address.sin_addr.s_addr = INADDR_ANY;
	else
	{
		// Convert the string type to char array
		char cstr[ip.size() + 1];
		strcpy(cstr, ip.c_str());
		inet_pton(domain, cstr, &this->address.sin_addr);
	}
}

// Network member function
void Network::socket_init(void)
{
	this->sockfd = socket(this->domain, this->type, this->protocol);

	cout << this->address.sin_addr.s_addr << endl;
	if (this->sockfd == 0)
	{
		cout << "Fail to create a socket." << endl;
		exit(EXIT_FAILURE);
	}

	int opt = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) != 0)
	{
		cout << "socket option error" << endl;
		exit(EXIT_FAILURE);
	}

	if (bind(sockfd, (struct sockaddr *)&this->address, sizeof(this->address) < 0))
	{
		cout << "bind error" << endl;
		exit(EXIT_FAILURE);
	}
}
