#include "CTeacher.h"

//CTeacher::CTeacher()
//{
//	cout << "CTeacher 类的调用" << endl;
//}

void CTeacher::setTea(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender, const char* pszTitle)
{
	setInfo(nId, pszNo, pszName, nAge, nGender);
	m_pszTitle = new char[strlen(pszTitle) + 1];
	strcpy(m_pszTitle, pszTitle);

}

void CTeacher::Print()
{
	cout << m_nld << "  " << m_pszNo << "  " << m_pszName
		<< "  " << m_nAge << "  " << m_nGender << "  " << m_pszTitle << " ";

}
