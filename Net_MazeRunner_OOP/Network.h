#pragma once
#include "stdafx.h"
#include "GetNetwork.h"

#define SERVERIP   "127.0.0.1"
#define SERVERPORT 9000
#define BUFSIZE 2048
#define BUFSIZE2 128

extern SOCKET sock; // 소켓
extern char buf[BUFSIZE2 + 1]; // 데이터 송수신 버퍼
extern ForPingPong S_Get_Data;
extern HANDLE hWrite_Event, hRead_Event;

DWORD WINAPI Network(LPVOID arg);
void network();

// 대화상자 프로시저
void err_quit(char *msg);
void err_display(char *msg);
int recvn(SOCKET s, char *buf, int len, int flags);
