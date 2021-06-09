#pragma once
#include "CStuff.h"

class CExecutive :public CStuff
{
public:
	CExecutive(const long nId, string pszNo, string pszName, int nAge,
		const char nGender, string pszPosition);
	void Print();

private:

	string m_pszPosition;  // ¸ÚÎ»

};