#pragma comment(lib, "ws2_32")
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include"CSendTo.h"
#include"CRecvFrom.h"

ForPingPong S_Main_Data;
CSendTo* Send_Test = NULL;// 송신을 하기 위한 테스트
CRecvFrom* Recv_Test = NULL; //수신을 하기 위한 테스트



//DWORD WINAPI ProcessClient(LPVOID arg)
//{
//	SOCKET client_sock = (SOCKET)arg;
//	int retval;
//	SOCKADDR_IN clientaddr;
//	int addrlen;
////	char buf[BUFSIZE2 + 1];
//	
//
//
//	//클라이언트 정보 얻기
//	addrlen = sizeof(clientaddr);
//	getpeername(client_sock, (SOCKADDR *)&clientaddr, &addrlen);
//
//	printf("\r\n[TCP 서버] 클라이언트 접속: IP주소=%s, 포트번호=%d\r\n",
//		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
//
//	int struct_len = sizeof(ForPingPong);
//	while (1) {
//		 
//		    retval = recvn(client_sock, (char*)&struct_len, 4, 0);
//			if (retval == SOCKET_ERROR) {
//				printf("int 문제");
//				err_quit("server recvn()");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}
//
//
//		
//			/*retval = recvn(client_sock, (char*)&S_Main_Data, struct_len, 0);
//			if (retval == SOCKET_ERROR) {
//				err_quit("server recvn()");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}
//	
//
//		
//		
//			retval = send(client_sock, (char*)&struct_len, 4, 0);
//			if (retval == SOCKET_ERROR) {
//				printf("int 문제");
//				err_quit("server send()");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}*/
//	
//			retval = send(client_sock, (char*)&S_Main_Data, struct_len, 0);
//			if (retval == SOCKET_ERROR) {
//				err_quit("server send()");
//				break;
//			}
//			else if (retval == 0) {
//				break;
//			}
//		
//
//		
//
//		
//
//	}
//
//	// closesocket()
//	closesocket(client_sock);
//
//	return 0;
//}



//제공 코드 사용



void serverdata()
{
	int retval;

	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return;
	}

	//socket()
	SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET) err_quit("socket()");

	//bind()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = bind(listen_sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("bind()");

	//listen()
	retval = listen(listen_sock, SOMAXCONN);
	if (retval == SOCKET_ERROR) err_quit("listen()");

	//데이터 통신에 사용할 변수
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	HANDLE hThread;
	int struct_len = sizeof(ForPingPong);


	while (1)
	{
		addrlen = sizeof(clientaddr);
		client_sock = accept(listen_sock, (SOCKADDR*)&clientaddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			err_display("accept()");
			break;
		}

		printf("\r\n[TCP 서버] 클라이언트 접속: IP주소=%s, 포트번호=%d\r\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		////접속 클라 정보 출력
		//hThread = CreateThread(NULL, 0, ProcessClient,
		//	(LPVOID)client_sock, 0, NULL);
		//if (hThread == NULL) { closesocket(client_sock); }
		//else { CloseHandle(hThread); }


		////while (0/*1*/)	// while조건문 내부에 bool문으로 처리해도 될 것 같은데, game start나 end같은
		////{
		////	//예제코드에선 데이터 받기였는데. >> 보내기로 해야 하지 않을까? : 맵 정보와 귀신 정보 등은 서버가 가지고 있기 때문에
		////
		////	//충돌처리 및 시간경과 처리

		////	//데이터 받기?
		////}

		while (1) {
			/*retval = recvn(client_sock, (char*)&struct_len, 4, 0);
			if (retval == SOCKET_ERROR) {
				printf("int 문제");
				err_quit("server recvn()");
				break;
			}
			else if (retval == 0) {
				break;
			}
			
			retval = recvn(client_sock, (char*)&S_Main_Data, struct_len, 0);
			if (retval == SOCKET_ERROR) {
				err_quit("server recvn()");
				break;
			}
			else if (retval == 0) {
				break;
			}

			retval = send(client_sock, (char*)&struct_len, 4, 0);
			if (retval == SOCKET_ERROR) {
				printf("int 문제");
				err_quit("server send()");
				break;
			}
			else if (retval == 0) {
				break;
			}

			retval = send(client_sock, (char*)&S_Main_Data, struct_len, 0);
			if (retval == SOCKET_ERROR) {
				err_quit("server send()");
				break;
			}
			else if (retval == 0) {
				break;
			}*/

			if (!Recv_Test->RecvPlayerInfo(client_sock))
			{
				break;
			}
			
			if (!Recv_Test->RecvMapInfo(client_sock))
			{
				break;
			}

			if (!Send_Test->SendMapInfo(client_sock))
			{
				break;
			}
			if (!Send_Test->SendMapInfo(client_sock))
			{
				break;
			}

			printf("\n%d\n", struct_len);
		}

		closesocket(client_sock);
	}



	//윈속 종료
	closesocket(listen_sock);
	WSACleanup();
}

int main(int argc, char *argv[])
{
	Send_Test = new CSendTo;
	Recv_Test = new CRecvFrom;
	serverdata();

	delete Send_Test;
    return 0;
}

