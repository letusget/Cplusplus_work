#include "CExecutive.h"

//CExecutive::CExecutive()
//{
//	cout << "CExecutive 类的调用" << endl;
//}

void CExecutive::setExe(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender, const char* pszPosition)
{
	setInfo(nId, pszNo, pszName, nAge, nGender);
	m_pszPosition = new char[strlen(pszPosition) + 1];
	strcpy(m_pszPosition, pszPosition);
}

void CExecutive::Print()
{
	cout << m_nld << "  " << m_pszNo << "  " << m_pszName
		<< "  " << m_nAge << "  " << m_nGender << "  " << m_pszPosition << " ";
}
