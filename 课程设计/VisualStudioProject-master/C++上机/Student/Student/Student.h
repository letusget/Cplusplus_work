#pragma once
#include <string>

using namespace std;

class CStudent {
public:
	void Printf();
	void setInfo(long nId, string pszName, int nAge, char nGender, string pszMajor);

private:
	long m_nId;
	string m_pszName;
	int m_nAge;
	char m_nGender;
	string m_pszMajor;
};

