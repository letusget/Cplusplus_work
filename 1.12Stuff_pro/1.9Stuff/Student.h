#pragma once
#include "CStuff.h"

class CStudent :public CStuff
{
public:
	CStudent(const long nId, string pszNo,string pszName, int nAge,
		const char nGender, string pszMajor);
	
	void Print();
	//string getMajor();

private:

	string m_pszMajor;  //专业
};
