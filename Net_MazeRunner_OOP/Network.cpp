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
	char sInputIP[30];

	printf("��Ʈ��ũ�� ���� �մϴ�.\n");
	printf("�����ϰ����ϴ� IP�� �Է����ּ���.\n");
	scanf("%s", sInputIP);
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
	serveraddr.sin_addr.s_addr = inet_addr(sInputIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");



	int struct_len = sizeof(ForPingPong);

	isPlayGame = true;
	isNetwork = true;

	Level_HP += 1;
	player.SetPosition();

	//mynum �޾ƿ���
	retval = recvn(sock, (char*)&S_Get_Data.iplayernum,
		sizeof(S_Get_Data.iplayernum), 0);
	if (retval == SOCKET_ERROR)
		err_quit("player recvn()");

	
	("[mynum] : %d\n", S_Get_Data.iplayernum);
	player.PlayerID = S_Get_Data.iplayernum;
	player.SetPosition(); // ID�� �´� �ʱ� �������� �޾�.
	printf("%d\n", player.PlayerID);
	int wcnt = 0;
	while (1)
	{
		//////////////////////////////////////////////
		//											//
		//      ���� to Ŭ�� �ڵ� ������ �κ�     //
		//											//
		//////////////////////////////////////////////

		// �������� �÷��̾� ������ �޴´�.
		for (int i = 0; i < PLAYERMAX; ++i)
		{
			retval = recvn(sock, (char*)&S_Get_Data.PlayerArray[i],
				sizeof(S_Get_Data.PlayerArray[i]), 0);
			if (retval == SOCKET_ERROR)
				err_quit("player recvn()");
			
			others[i].PlayerID = S_Get_Data.PlayerArray[i].uiSerialNum;

			if (player.PlayerID == i + 1) { // �� ��� ������ �����ų �ʿ� ����
				//printf("player[%d] x -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fX);
				//printf("player[%d] y -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fY);
				//printf("player[%d] z -[], %f\n\n", i, S_Get_Data.PlayerArray[i].Pos.fZ); // �������� �� ���� ���� ����.
			}
			else { // �ٸ� ��̵��� others[3]�� �ϳ��� ��ǥ �־��ش�. 
				others[i].SetPosition(S_Get_Data.PlayerArray[i].Pos.fX, S_Get_Data.PlayerArray[i].Pos.fY, S_Get_Data.PlayerArray[i].Pos.fZ);
				//printf("Other[%d] x -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fX);
				//printf("Other[%d] y -[], %f\n", i, S_Get_Data.PlayerArray[i].Pos.fY);
				//printf("Other[%d] z -[], %f\n\n", i, S_Get_Data.PlayerArray[i].Pos.fZ);
			} // �� �޾ƿ�
		}

		for (int i = 0; i < B_SIZE; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{
				retval = recvn(sock, (char*)&S_Get_Data.MazeArray[i][j],
					sizeof(S_Get_Data.MazeArray[i][j]), 0);
				if (retval == SOCKET_ERROR)
					err_quit("maze recvn()");

				MazeBoard[i][j] = S_Get_Data.MazeArray[i][j].iStatus; // �� ����
				if (S_Get_Data.MazeArray[i][j].bitem[player.PlayerID] == true) {
					
					iNetItem++; // �������� �Ծ��ٴ� ���� ������ ī��Ʈ ����
					if (iNetItem > iNetItemMax) {
						srand((unsigned)time(NULL));

						item_rand = rand() % 5;
						PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_ASYNC | SND_ALIAS);
						switch (item_rand)
						{
						case ItemState::KEY:
							Level_Key++;
							break;
						case ItemState::SPEED:
							speedup += 0.1; // �ӵ�����
							Level_Speed++;
							break;
						case ItemState::HP:
							Level_HP++; // ü�� ����
							break;
						case ItemState::MINIMAP:
							Level_Minimap += 1;
							break;
						case ItemState::CUTOFF: // �ӽ÷� KEy�ϳ� �߰�
							Level_Key++;
							break;
						}

						iNetItemMax = iNetItem;
					}// item ���� ���ڰ� �� �������� ����
				}
				
				if (S_Get_Data.MazeArray[i][j].bGoal[player.PlayerID] == true) {
					PlaySound(TEXT(SOUND_FILE_NAME_FINISH), NULL, SND_ASYNC | SND_ALIAS);
					printf("���ӿ��� �¸��ϼ̽��ϴ�.\n");
					Level_HP = 0;
					startinit();
				}
			}
		} // �� ���۹ޱ� �Ϸ�
		iNetItem = 0;

		//�浹üũ �����...
		//camera & MazeBoard[i][j]
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < B_SIZE; ++j)
			{//��Ʈ�浹üũ
				for (int k = 0; k < B_SIZE; ++k)
				{//Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
					if (MazeBoard[j][k] == 1 || MazeBoard[j][k] == 5)
					{
						if (player.Camera_x - 0.1f <= j * 1.1 - 15 + 0.5 &&
							player.Camera_x + 0.1f >= j * 1.1 - 15 - 0.5 &&
							player.Camera_z + 0.1f >= k * 1.1 - 15 + 3 - 0.5&&
							player.Camera_z - 0.1f <= k * 1.1 - 15 + 3 + 0.5)
						{
							player.Camera_x -= 1 * sin(angle);	//1�κп� �÷��̾� ���ǵ� ����
							player.Camera_z -= 1 * -cos(angle);	//1�κп� �÷��̾� ���ǵ� ����
						}
					}
				}
			}
		}

		if ((-15 > player.Camera_x || player.Camera_x > 29 * 1.1 - 15) ||
			(-15 > player.Camera_z || player.Camera_z > 29 * 1.1 - 15))
		{//Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
			switch (player.PlayerID)
			{ //Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
			case 1:   // red
				player.Camera_x = 1.1f*1.5f - 15.f, player.Camera_y = 1.75f, player.Camera_z = 1.1f*10.f - 15.f; // �⺻0,5,1.75
				break;
			case 2: //blue
				player.Camera_x = 1.1f*27.f - 15.0f, player.Camera_y = 1.75f, player.Camera_z = 1.1f*4.f - 15.f; // �⺻0,5,1.75
				break;
			case 3:   //red
				player.Camera_x = 1.1*2.f - 15.f, player.Camera_y = 1.75f, player.Camera_z = 1.1*3.4f - 15.f; // �⺻0,5,1.75
				break;
			case 4: //blue
				player.Camera_x = 1.1f*28.f - 15.f, player.Camera_y = 1.75f, player.Camera_z = 1.1*8.f - 15.f; // �⺻0,5,1.75
				break;
			}
		}

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

			if (S_Get_Data.GhostArray[i].iCollsion == player.PlayerID && S_Get_Data.GhostArray[i].iCollsion != 999)
			{
				//Position Pos = Position(0.f, 0.f, 0.f);
				int iRandX, iRandY = 0.f;

				if (player.PlayerID % 2 == TEAM_Red)
				{
					iRandX = rand() % 1 + 1; // 1 or 2
				}
				else if (player.PlayerID % 2 == TEAM_Blue)
				{
					iRandX = rand() % 1 + 27;   // 27 or 28
				}
				else
					break;

				if (iRandX == 0)
				{
					printf("�߸��� ��!\n");
					break;
				}
				iRandY = rand() % 27 + 1; //   1 ~ 28 ������ ��

										  //Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
				player.Camera_x = iRandX * 1.1 - 15;
				player.Camera_z = iRandY * 1.1 - 15;
			}


		} // ��Ʈ ��ǥ ���̷� �Ѿ��
		//wcnt++;
		//player.Camera_y += wcnt;
		// �÷��̾� ��ǥ �����ִ� �κ�.
		
		for (int i = 0; i < PLAYERMAX; ++i)
		{
			if (S_Get_Data.iplayernum == i + 1) {
				S_Get_Data.PlayerArray[i].fAngle = angle;
				S_Get_Data.PlayerArray[i].fDeltaAngle = deltaAngle;
				S_Get_Data.PlayerArray[i].fspeed = speedup;
				S_Get_Data.PlayerArray[i].Pos.fX = player.Camera_x;
				S_Get_Data.PlayerArray[i].Pos.fY = player.Camera_y;
				S_Get_Data.PlayerArray[i].Pos.fZ = player.Camera_z;
				S_Get_Data.PlayerArray[i].ikey = Level_Key;
			} // �������� ���� ���Ѽ� �����ش�.

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
		} // maze ��������. (�˸��� �����͸� ������ ����.)
	}
	//closesocket()
	closesocket(sock);

	//���� ����
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