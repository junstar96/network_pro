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
	char sInputIP[30];

	printf("네트워크에 접속 합니다.\n");
	printf("접속하고자하는 IP를 입력해주세요.\n");
	scanf("%s", sInputIP);
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
	serveraddr.sin_addr.s_addr = inet_addr(sInputIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");



	int struct_len = sizeof(ForPingPong);

	isPlayGame = true;
	isNetwork = true;

	Level_HP += 1;
	player.SetPosition();

	//mynum 받아오기
	retval = recvn(sock, (char*)&S_Get_Data.iplayernum,
		sizeof(S_Get_Data.iplayernum), 0);
	if (retval == SOCKET_ERROR)
		err_quit("player recvn()");

	printf("[mynum] : %d\n", S_Get_Data.iplayernum);
	player.PlayerID = S_Get_Data.iplayernum;
	player.SetPosition(); // ID에 맞는 초기 포지션을 받아.
	int wcnt = 0;
	while (1)
	{
		//////////////////////////////////////////////
		//											//
		//      서버 to 클라 코드 들어가야할 부분     //
		//											//
		//////////////////////////////////////////////

		// 서버에서 플레이어 정보를 받는다.
		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player recvn()");

			if (player.PlayerID == i) { // 내 어레이 정보를 적용시킬 필요 없음
				//printf("player[%d] x -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fX);
				//printf("player[%d] y -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fY);
				//printf("player[%d] z -[], %f\n\n", i, S_Get_Data.PlayerArray[i].Pos.fZ); // 내정보는 잘 갔다 오고 있음.
			}
			else { // 다른 어레이들은 others[3]에 하나씩 좌표 넣어준다. 
				//others[i].SetPosition(S_Get_Data.PlayerArray[i].Pos.fX, S_Get_Data.PlayerArray[i].Pos.fY, S_Get_Data.PlayerArray[i].Pos.fZ);
				//printf("Other[%d] x -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fX);
				//printf("Other[%d] y -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fY);
				//printf("Other[%d] z -[], %f\n\n", i, S_Get_Data.PlayerArray[i].Pos.fZ);
			} // 나 받아와
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = recvn(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);
				if (retval == SOCKET_ERROR)
					err_quit("maze recvn()");

				MazeBoard[i][j] = S_Get_Data.MazeArray[i][j].iStatus; // 맵 수정
				if (S_Get_Data.MazeArray[i][j].bitem == true) {
					iNetItem++; // 아이템을 먹었다는 것을 받으면 카운트 증가
					if (iNetItem > iNetItemMax) {
						srand((unsigned)time(NULL));

						item_rand = rand() % 5;
						switch (item_rand)
						{
						case ItemState::KEY:
							Level_Key++;
							break;
						case ItemState::SPEED:
							speedup += 0.1; // 속도증가
							Level_Speed++;
							break;
						case ItemState::HP:
							Level_HP++; // 체력 증가
							break;
						case ItemState::MINIMAP:
							Level_Minimap += 1;
							break;
						case ItemState::CUTOFF: // 임시로 KEy하나 추가
							Level_Key++;
							break;
						}

						iNetItemMax = iNetItem;
					}// item 먹은 숫자가 더 많아지면 갱신
				}
			}
		} // 맵 전송받기 완료
		iNetItem = 0;

		//player.Camera_y+=wcnt;
		for (int i = 0; i < GHOSTMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.GhostArray[i],
				sizeof(S_Get_Data.GhostArray[i]), 0);

			if (retval == SOCKET_ERROR)
				err_quit("ghost recvn()");

			Ghosts[i].pos_x = S_Get_Data.GhostArray[i].Pos.fX;
			Ghosts[i].pos_y = S_Get_Data.GhostArray[i].Pos.fY;
			Ghosts[i].pos_z = S_Get_Data.GhostArray[i].Pos.fZ;
		} // 고스트 좌표 더미로 넘어옴
		//wcnt++;
		//player.Camera_y += wcnt;
		// 플레이어 좌표 보내주는 부분.
		
		for (int i = 0; i < PLAYERMAX; ++i)
		{
			if (S_Get_Data.iplayernum == i) {
				S_Get_Data.PlayerArray[i].fAngle = angle;
				S_Get_Data.PlayerArray[i].fDeltaAngle = deltaAngle;
				S_Get_Data.PlayerArray[i].fspeed = speedup;
				S_Get_Data.PlayerArray[i].Pos.fX = player.Camera_x;
				S_Get_Data.PlayerArray[i].Pos.fY = player.Camera_y;
				S_Get_Data.PlayerArray[i].Pos.fZ = player.Camera_z;
			} // 내정보만 갱신 시켜서 보내준다.

			retval = send(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player send()"); 

			//printf("Send[%d] x -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fX);
			//printf("Send[%d] y -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fY);
			//printf("Send[%d] z -[], %f\n\n", i, S_Get_Data.PlayerArray[i].Pos.fZ);
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j) {
				retval = send(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);
				if (retval == SOCKET_ERROR)
					err_quit("player send()");
			}
		} // maze 보내주자. (알맞은 데이터를 보내고 있음.)
	}
	//closesocket()
	closesocket(sock);

	//윈속 종료
	WSACleanup();
}



DWORD WINAPI SendThread(LPVOID arg)
{
	return 0;
}

DWORD WINAPI RecvThread(LPVOID arg)
{
	return 0;
}