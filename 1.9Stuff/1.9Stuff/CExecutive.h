#pragma once
#include "CStuff.h"
class CExecutive :public CStuff
{
public:
	//CExecutive();
	void setExe(long nId, const char* pszNo, const char* pszName, int nAge,
		char nGender, const char* pszPosition);
	void Print();
	

private:

	char* m_pszPosition;  //¸ÚÎ»

};


