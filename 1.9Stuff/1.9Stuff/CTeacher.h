#pragma once
#include "CStuff.h"

class CTeacher :public CStuff
{
public:
	//CTeacher();
	void setTea(long nId, const char* pszNo, const char* pszName, int nAge,
		char nGender, const char* pszTitle);
	void Print();
	

private:

	char* m_pszTitle;  //Ö°³Æ

};
