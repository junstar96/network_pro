#pragma comment(lib, "ws2_32")
#include "stdafx.h"
#include <WinSock2.h>
#include <stdlib.h>
#include <stdio.h>

#define SERVERPORT	9000

//제공 코드 사용
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

void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int main(int argc, char *argv[])
{
	//윈속 초기화

	//listen socket()

	//bind()

	//listen()

	//데이터 통신에 사용할 변수
	//SOCKET 클라소켓
	//SOCKET_IN 클라ADDR
	//INT ADDRLEN
	//우리의 경우엔 플레이어array+맵array+유령좌표array+조명각도 한 정보... 하나의 구조체로 표현 >> 아직 미제작

	while (0/*1*/)
	{
		//accept()

		//접속 클라 정보 출력

		while (0/*1*/)	// while조건문 내부에 bool문으로 처리해도 될 것 같은데, game start나 end같은
		{
			//예제코드에선 데이터 받기였는데. >> 보내기로 해야 하지 않을까? : 맵 정보와 귀신 정보 등은 서버가 가지고 있기 때문에
		
			//충돌처리 및 시간경과 처리

			//데이터 받기?
		}

		//클라소켓 close

	}

	//listen소켓 close

	//윈속 종료

    return 0;
}

