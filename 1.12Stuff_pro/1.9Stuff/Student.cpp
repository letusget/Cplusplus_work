#include "Student.h"

CStudent::CStudent(const long nId, string pszNo, string pszName, int nAge,
	const char nGender, string pszMajor)
{
	this->m_nld = nId;
	this->m_pszNo = pszNo;
	this->m_pszName = pszName;
	this->m_nAge = nAge;
	this->m_nGender = nGender;
	this->m_pszMajor = pszMajor;
	//cout << "CStudent �Ĺ��캯������" << endl;
}

void CStudent::Print()
{
	
	cout << this->m_nld << "  " << this->m_pszNo << "  " << this->m_pszName 
		<< "  " << this->m_nAge << "  " << this->m_nGender << "  " << this->m_pszMajor<< " ";
	//cout << "CStudent ��Print��������" << endl;
}

//string CStudent::getMajor()
//{
//	return "Major";
//}
