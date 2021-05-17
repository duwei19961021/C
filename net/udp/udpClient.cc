#include "udpClient.hpp"

int main()
{
	udpClient *uc = new udpClient();

	uc->initServer();
	
	uc->start();	

	return 0;	
}
