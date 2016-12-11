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

void msgSend()
{
	char packet_data[1024];
	int packet_size = 0;

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(IP4);
	addr.sin_port = htons(PORT);

	bind(sock,(sockaddr*)&addr,sizeof(sockaddr_in));

	while(1)
	{
	printf(">");
	gets(packet_data);
	packet_size = sizeof (packet_data);
	sendto(sock, packet_data, packet_size, 0, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
	}
	closesocket( sock );
}

int main() {

	initSock();

	msgSend();

	return 0;
}
