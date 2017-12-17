#include "stdafx.h"
#include "CMaze.h"


int CMaze::GetStatus(void)
{
	return m_iStatus;
}

void CMaze::SetStatus(int  Status)
{
	m_iStatus = Status;
}

float* CMaze::GetEdge(int EdgeWhat)
{
	return &m_fEdge[EdgeWhat];
}

void CMaze::SetEdge(float Edge, int EdgeWhat)
{
	m_fEdge[EdgeWhat] = Edge;
}

bool CMaze::Getbitem(int i)
{
	return bitem[i];
}

void CMaze::Setbitem(bool item, int i)
{
	bitem[i] = item;
}

bool CMaze::GetbGoal(int i)
{
	return bGoal[i];
}

void CMaze::SetbGoal(bool Goal, int i)
{
	bGoal[i] = Goal;
}

CMaze::CMaze()
{
}


CMaze::~CMaze()
{
}