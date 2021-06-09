#pragma once
#include "CStuff.h"

class CStudent :public CStuff
{
public:
	//CStudent();
	void setStu(long nId, const char* pszNo, const char* pszName, int nAge,
		char nGender, const char* pszMajor);
	void Print();
	

private:

	char* m_pszMajor;  //专业

};
