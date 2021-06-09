#include "CExecutive.h"

CExecutive::CExecutive(const long nId, string pszNo, string pszName, int nAge, 
	const char nGender, string pszPosition)
{
	this->m_nld = nId;
	this->m_pszNo = pszNo;
	this->m_pszName = pszName;
	this->m_nAge = nAge;
	this->m_nGender = nGender;
	this->m_pszPosition = pszPosition;
}

void CExecutive::Print()
{
	cout << this->m_nld << "  " << this->m_pszNo << "  " << this->m_pszName
		<< "  " << this->m_nAge << "  " << this->m_nGender << "  " << this->m_pszPosition << " ";
}
