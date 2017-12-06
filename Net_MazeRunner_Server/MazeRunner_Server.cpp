#pragma comment(lib, "ws2_32")
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include"CSendTo.h"
#include"CRecvFrom.h"

#define NET_MAP "MAP_TEST.txt"


ForPingPong S_Main_Data;
CSendTo* Send_Test = NULL;// 송신을 하기 위한 테스트
CRecvFrom* Recv_Test = NULL; //수신을 하기 위한 테스트

FILE * fp = NULL;//서버용으로 

DWORD g_fPrevTime = 0;
float g_fElapsedTime = 0.f;

HANDLE H_Read_Event;
HANDLE H_Write_Event;
HANDLE Main_Server;

DWORD WINAPI ProcessClient(LPVOID arg)
{
	SOCKET client_sock = (SOCKET)arg;
	int retval;
	SOCKADDR_IN clientaddr;
	int addrlen;
//	char buf[BUFSIZE2 + 1];
	


	//클라이언트 정보 얻기
	addrlen = sizeof(clientaddr);
	getpeername(client_sock, (SOCKADDR *)&clientaddr, &addrlen);

	printf("\r\n[TCP 서버] 클라이언트 접속: IP주소=%s, 포트번호=%d\r\n",
		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));




	int struct_len = sizeof(ForPingPong);
	while (1) {
		 
		CForServer* ServerInfo = new CForServer;


		while (1) {

			if (!Recv_Test->RecvPlayerInfo(client_sock))
			{
				break;
			}
			if (!Send_Test->SendMapInfo(client_sock))
			{
				break;
			}
			if (!Send_Test->SendGhostInfo(client_sock))
			{
				break;
			}

			
			if (!Send_Test->SendPlayerInfo(client_sock))
			{
				break;
			}

			/*if (!Recv_Test->RecvMapInfo(client_sock))
			{
				break;
			}
			*/


			ServerInfo->SetElapsedTime(g_fElapsedTime);
			g_fPrevTime = timeGetTime();

			for (int i = 0; i < PLAYERMAX; ++i)
			{
				ServerInfo->SetPlayer(Recv_Test->Get_Player(i), i);
			}

			for (int i = 0; i < B_SIZE; ++i)
			{
				for (int j = 0; j < B_SIZE; ++j)
				{
					ServerInfo->SetMaze(Recv_Test->Get_Maze(i, j), i, j);
				}
			}

			for (int i = 0; i < GHOSTMAX; ++i)
			{
				ServerInfo->SetGhost(Recv_Test->Get_Ghost(i), i);
			}

			ServerInfo->UpdatingAll();

			DWORD fCurTime = timeGetTime();
			g_fElapsedTime = float(fCurTime - g_fPrevTime) * 0.001f;

			for (int i = 0; i < PLAYERMAX; ++i)
			{
				Send_Test->Set_Player(ServerInfo->GetPlayer(i), i);
			}

			/*for (int i = 0; i < B_SIZE; ++i)
			{
				for (int j = 0; j < B_SIZE; ++j)
				{
					Send_Test->Set_Maze(ServerInfo->GetMaze(i, j), i, j);
				}
			}*/

			for (int i = 0; i < GHOSTMAX; ++i)
			{
				Send_Test->Set_Ghost(ServerInfo->GetGhost(i), i);
			}
		}
		

		

		
		delete ServerInfo;
	}

	// closesocket()
	closesocket(client_sock);

	return 0;
}



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
	HANDLE H_Thread[4];


	while (1)
	{
		
		addrlen = sizeof(clientaddr);
		client_sock = accept(listen_sock, (SOCKADDR*)&clientaddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			err_display("accept()");
			break;
		}


		H_Thread[0] = CreateThread(NULL, 0, ProcessClient, (LPVOID)client_sock, 0, NULL);
		if (H_Thread[0] == NULL)
		{
			closesocket(client_sock);
		}
		else
		{
			CloseHandle(H_Thread[0]);
		}
		
	}

	WaitForMultipleObjects(4, H_Thread, TRUE, INFINITE);

	//윈속 종료
	closesocket(listen_sock);
	WSACleanup();

	return;
}

int main(int argc, char *argv[])
{
	fp = fopen(NET_MAP, "rt");
	H_Read_Event = CreateEvent(NULL, FALSE, TRUE, NULL);
	if (H_Read_Event == NULL) return 1;
	H_Write_Event = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (H_Write_Event == NULL) return 1;

	Send_Test = new CSendTo;

	int cha = 0;

	while (feof(fp) == 0)
	{
		for (int i = 0; i < B_SIZE; i++)
		{
			for (int j = 0; j < B_SIZE; j++)
			{
				fscanf(fp, "%d", &cha);
				Send_Test->get_maze(i, j, cha);
			}
		}
	}
	fclose(fp);

	Recv_Test = new CRecvFrom;

	serverdata();
	

	delete Send_Test;
	delete Recv_Test;
	return 0;
}