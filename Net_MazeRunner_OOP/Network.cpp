#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include "Network.h"
#include "resource.h"
#include "GetNetwork.h"
#include "SetNetwork.h"

SOCKET sock; // 소켓
char buf[BUFSIZE2 + 1]; // 데이터 송수신 버퍼
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

// 소켓 함수 오류 출력
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

// 사용자 정의 데이터 수신 함수
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

	printf("네트워크에 접속 합니다. (상대방이 들어올 때까지 대기 합니다.)");
	int retval;

	// 윈속 초기화
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
	//		클라 to 서버 코드 들어가야할 부분		//
	
	while (1)
	{

		retval = send(sock, (char*)&struct_len, 4, 0);
		if (retval == SOCKET_ERROR)
			err_quit("int send()");

		retval = send(sock, (char*)&S_Get_Data, struct_len, 0);
		if (retval == SOCKET_ERROR) {
			err_quit("struct send()");
		}



		retval = recvn(sock, (char*)&struct_len, 4, 0);
		if (retval == SOCKET_ERROR)
			err_quit("int send()");


		retval = recvn(sock, (char*)&S_Get_Data, struct_len, 0);
		if (retval == SOCKET_ERROR) {
			err_quit("struct recvn()");
		}

	}

	//		--> 플레이어의 좌표					//
	//											//
	//		서버 to 클라 코드 들어가야할 부분		//
	//		--> PingPong (맵, 고스트, 상대방)		//
	//											//
	//////////////////////////////////////////////
	//ForPingPong getServer; // 서버에서 PingPong 가져오기.

	//for (int i = 0; i < B_SIZE; i++)
	//{
	//	for (int j = 0; j < B_SIZE; j++)
	//	{
	//		MazeBoard[i][j] = getServer.MazeArray[i][j].iStatus;
	//	}
	//} // 맵 만들기.

	//Bool_PlayGame = true;
	//Bool_Network = true;

	//Level_HP += 1;
	//player.SetPosition();
	// 고스트, 상대플레이어 위치 좌표는 랜더에서 받아와야할텐데.

	///////////////////////////////////////////////////////////

	//CSendtoServer(); // 플레이어 포지션 좌표 보내기.

	///////////////////////////////////////////////////////////



	//closesocket()
	closesocket(sock);

	//윈속 종료
	WSACleanup();
}