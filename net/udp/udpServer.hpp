#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

class udpServer
{
private:
	std::string _ip;
	short _port;
	int _sock;
public:
	udpServer(std::string ip = "127.0.0.1", short port = 8080)
	{
		_ip = ip;
		_port = port;
	}

	void initServer()
	{
		_sock = socket(AF_INET, SOCK_DGRAM, 0);
		std::cout << "sock: " << _sock << std::endl;	
		struct sockaddr_in local; 
		local.sin_family = AF_INET;
		local.sin_port = htons(_port);
		local.sin_addr.s_addr = inet_addr(_ip.c_str());
		if(bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0)
		{
			std::cerr << "bind error" << std::endl;
			exit(-1);
		}
	}

	void start()
	{
		char buf[64];
		for(;;)
		{
			buf[0] = '\0';
			struct sockaddr_in end_point;
			socklen_t len = sizeof(end_point);
			ssize_t s = recvfrom(_sock, buf, sizeof(buf)-1, 0,(struct sockaddr*)&end_point, &len);
			if(s > 0)
			{
				buf[s] = '\0';
				std::cout << "client# " << buf << std::endl;
				sendto(_sock, buf, s, 0, (struct sockaddr*)&end_point, len);
			}
		}
	}

	~udpServer()
	{
		close(_sock);
	}
};
