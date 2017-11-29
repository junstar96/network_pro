#include "stdafx.h"
#include "CMaze.h"


int * CMaze::GetStatus(void)
{
	return &m_iStatus;
}

void CMaze::SetStatus(int * Status)
{
	m_iStatus = *Status;
}

float* CMaze::GetEdge(int EdgeWhat)
{
	return &m_fEdge[EdgeWhat];
}

void CMaze::SetEdge(float Edge, int EdgeWhat)
{
}

CMaze::CMaze()
{
}


CMaze::~CMaze()
{
}
