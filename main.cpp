
#include <winsock2.h>
#include <stdio.h>
#include <tchar.h>

int main() {

	int server_port = 8080;

	WSADATA wsaData;
	WSAStartup(0x0202, &wsaData);

	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons((u_short) server_port);

	int clientSock = socket(PF_INET, SOCK_DGRAM, 0);
	std::string message = "hello.";
	sendto(clientSock, message.c_str(), message.length(), 0, (LPSOCKADDR) &serverAddr, sizeof(struct sockaddr));
	closesocket(clientSock);

	WSACleanup();

	return 0;
}
