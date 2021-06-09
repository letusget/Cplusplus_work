#pragma once
#include "CStuff.h"

class CTeacher :public CStuff
{
public:
	CTeacher(const long nId, string pszNo, string pszName, int nAge,
		const char nGender, string pszTitle);
	void Print();

private:

	string m_pszTitle;  // Ö°³Æ

};
