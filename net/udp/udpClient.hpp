#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

class udpClient
{
private:
	std::string _ip;
	short _port;
	int _sock;
public:
	udpClient(std::string ip = "127.0.0.1", short port = 8080)
	{
		_ip = ip;
		_port = port;
	}

	void initServer()
	{
		_sock = socket(AF_INET, SOCK_DGRAM, 0);
		std::cout << "sock: " << _sock << std::endl;	
	}

	void start()
	{
		struct sockaddr_in peer;
		peer.sin_family = AF_INET;
		peer.sin_port = htons(_port);
		peer.sin_addr.s_addr = inet_addr(_ip.c_str());
		std::string msg;	
		for(;;)
		{
			std::cout << "Please Enter: ";
			std::cin >> msg;
			sendto(_sock, msg.c_str(), msg.size(), 0, (struct sockaddr*)&peer,  sizeof(peer));	
			char recvMsg[64];
			ssize_t s = recvfrom(_sock, recvMsg, sizeof(recvMsg)-1, 0, NULL, NULL);
			if(s > 0)
			{
				recvMsg[s] = '\0';
				std::cout << "Server# " << recvMsg << std::endl;
			}
		}
	}

	~udpClient()
	{
		close(_sock);
	}
};
