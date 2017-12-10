#pragma once
#include "CGameObject.h"

class CPlayer :
   public CGameObject
{
private://멤버변수
   unsigned int   m_uiSerialNum;   //고유번호
   int            m_iMyTeam;      //팀 소속

   float         m_fDeltaAngle;      //조작에따른각도
   float         m_fSpeed;
public:// Get & Set
   unsigned int*   GetSerialNum(void);
   void         SetSerialNum(unsigned int* SerialNum);

   int*         GetMyTeam(void);
   void         SetMyTeam(int* Myteam);

   float*         GetDeltaAngle(void);
   void         SetDeltaAngle(float* DeltaAngle);

   float*         GetSpeed(void);
   void         SetSpeed(float Speed);
public:
   CPlayer();
   ~CPlayer();
};