#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <winsock2.h>
#include <windows.h>

#define PORT 2009
#define IP4 "127.0.0.1"

void initSock()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD (2,2), &wsaData);
}

int msgRecv()
{
	int bound = 0;
	short i = 0;
	char packet_data[1024];
	int max_packet_size = sizeof ( packet_data );

	SOCKET sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(sock)
		{
			printf("Create socket... \tok\tnum: %d\n\r", sock);
		}
		else
		{
			printf("Socket failed\n\r");
			getch();
			return 1;
		}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(IP4);
	addr.sin_port = htons(PORT);

	bound = bind(sock, (const sockaddr *)&addr, sizeof (sockaddr_in));
		if(bound >= 0)
		{
			printf("Bind socket... \t\tok\n\r");
			printf("Adress: \t\t%s\n\r", inet_ntoa(addr.sin_addr));
			printf("Port: \t\t\t%d\n\r", PORT);
		}

		while(1)
		{

			if(!i)
			{
			printf("\n\rWaiting Mode ON:");
			}
			i++;

			struct sockaddr_in from;
			int fromLength = sizeof (from);

			recvfrom(sock, (char *)packet_data, max_packet_size, 0, (struct sockaddr *)&from, &fromLength);

			printf("\n\rIP>%s:MSG:%s", inet_ntoa(from.sin_addr), packet_data);

		}
}

int main() {



	initSock();

	msgRecv();

	return 0;
}
