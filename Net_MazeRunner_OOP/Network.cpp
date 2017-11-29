#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include "Network.h"
#include "resource.h"
#include "GetNetwork.h"
#include "SetNetwork.h"

SOCKET sock; // ����
char buf[BUFSIZE2 + 1]; // ������ �ۼ��� ����
ForPingPong S_Get_Data;
HANDLE hWrite_Event, hRead_Event;

void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

// ���� �Լ� ���� ���
void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] % s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

// ����� ���� ������ ���� �Լ�
int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0) {
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}

DWORD WINAPI Network(LPVOID arg) {

	printf("��Ʈ��ũ�� ���� �մϴ�. (������ ���� ������ ��� �մϴ�.)");
	int retval;

	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	// socket()
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");

	// connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");
	

	
	int struct_len = sizeof(ForPingPong);
	//////////////////////////////////////////////
	//											//
	//		Ŭ�� to ���� �ڵ� ������ �κ�		//

	Bool_PlayGame = true;
	Bool_Network = true;

	Level_HP += 1;
	player.SetPosition();
	while (1)
	{

		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player recvn()");
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = recvn(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);

				if (retval == SOCKET_ERROR)
					err_quit("maze recvn()");
			}
		}

		for (int i = 0; i < GHOSTMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.GhostArray[i],
				sizeof(S_Get_Data.GhostArray[i]), 0);

			if (retval == SOCKET_ERROR)
				err_quit("ghost recvn()");
		}


		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = send(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player send()");
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = send(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);

				if (retval == SOCKET_ERROR)
					err_quit("maze send()");
			}
		}

		
		//üũ�� ���� ���� �������� Ȯ���ϴ� ��

		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				printf("%d ", S_Get_Data.MazeArray[i][j].iStatus);
			}
			printf("\n");
		}
			
		for (int i = 0; i < B_SIZE; i++)
		{
			for (int j = 0; j < B_SIZE; j++)
			{
				MazeBoard[i][j] = S_Get_Data.MazeArray[i][j].iStatus;
			}
		}
	

	}

	//		--> �÷��̾��� ��ǥ					//
	//											//
	//		���� to Ŭ�� �ڵ� ������ �κ�		//
	//		--> PingPong (��, ��Ʈ, ����)		//
	//											//
	//////////////////////////////////////////////

	// ��Ʈ, ����÷��̾� ��ġ ��ǥ�� �������� �޾ƿ;����ٵ�.

	///////////////////////////////////////////////////////////

	//CSendtoServer(); // �÷��̾� ������ ��ǥ ������.

	///////////////////////////////////////////////////////////



	//closesocket()
	closesocket(sock);

	//���� ����
	WSACleanup();
}

void network()
{
	printf("��Ʈ��ũ�� ���� �մϴ�. (������ ���� ������ ��� �մϴ�.)");
	int retval;

	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return;

	// socket()
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");

	// connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");



	int struct_len = sizeof(ForPingPong);
	//////////////////////////////////////////////
	//											//
	//		Ŭ�� to ���� �ڵ� ������ �κ�		//

	while (1)
	{

		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player recvn()");
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = recvn(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);

				if (retval == SOCKET_ERROR)
					err_quit("maze recvn()");
			}
		}

		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = send(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player send()");
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = send(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);

				if (retval == SOCKET_ERROR)
					err_quit("maze send()");
			}
		}

	/*	for (int j = 0; j < 30; ++j)
		{
			for (int i = 0; i < 30; ++i)
			{
				printf("%d ", S_Get_Data.MazeArray[j][i].iStatus);
			}
			printf("\n");
		}*/

	}

	//		--> �÷��̾��� ��ǥ					//
	//											//
	//		���� to Ŭ�� �ڵ� ������ �κ�		//
	//		--> PingPong (��, ��Ʈ, ����)		//
	//											//
	////////////////////////////////////////////////
	//ForPingPong getServer; // �������� PingPong ��������.

	//for (int i = 0; i < B_SIZE; i++)
	//{
	//	for (int j = 0; j < B_SIZE; j++)
	//	{
	//		MazeBoard[i][j] = getServer.MazeArray[i][j].iStatus;
	//	}
	//} // �� �����.

	//  Bool_PlayGame = true;
	//  Bool_Network = true;

	//  Level_HP += 1;
	//  player.SetPosition();
	//  // ��Ʈ, ����÷��̾� ��ġ ��ǥ�� �������� �޾ƿ;����ٵ�.

	  ///////////////////////////////////////////////////////////

	  //CSendtoServer(); // �÷��̾� ������ ��ǥ ������.

	  ///////////////////////////////////////////////////////////



	  //closesocket()
	closesocket(sock);

	//���� ����
	WSACleanup();
}