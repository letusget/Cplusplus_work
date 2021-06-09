#include "CTeacher.h"

CTeacher::CTeacher(const long nId, string pszNo, string pszName, int nAge, 
	const char nGender, string pszTitle)
{
	this->m_nld = nId;
	this->m_pszNo = pszNo;
	this->m_pszName = pszName;
	this->m_nAge = nAge;
	this->m_nGender = nGender;
	this->m_pszTitle = pszTitle;
}

void CTeacher::Print()
{
	cout << this->m_nld << "  " << this->m_pszNo << "  " << this->m_pszName
		<< "  " << this->m_nAge << "  " << this->m_nGender << "  " << this->m_pszTitle << " ";
}


