#pragma once
#include "stdafx.h"
#include "GetNetwork.h"

#define SERVERIP   "127.0.0.1"
#define SERVERPORT 9000
#define BUFSIZE 2048
#define BUFSIZE2 128

extern SOCKET sock; // ����
extern char buf[BUFSIZE2 + 1]; // ������ �ۼ��� ����
extern ForPingPong S_Get_Data;
extern HANDLE hWrite_Event, hRead_Event;

DWORD WINAPI Network(LPVOID arg);
void network();

// ��ȭ���� ���ν���
void err_quit(char *msg);
void err_display(char *msg);
int recvn(SOCKET s, char *buf, int len, int flags);
