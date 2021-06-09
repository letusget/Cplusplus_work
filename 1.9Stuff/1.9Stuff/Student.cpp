#include "Student.h"

//CStudent::CStudent()
//{
//	cout << "CStudent 的构造函数调用" << endl;
//
//}

void CStudent::setStu(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender, const char* pszMajor)
{
	//先使用父类来初始化基本的信息
	setInfo(nId, pszNo, pszName, nAge, nGender);

	//再把子类的信息添加 并输出
	m_pszMajor = new char[strlen(pszMajor) + 1];
	strcpy(m_pszMajor, pszMajor);
}


void CStudent::Print()
{
	cout << m_nld << "  " << m_pszNo << "  " << m_pszName 
		<< "  " << m_nAge << "  " << m_nGender << "  " << m_pszMajor<< " ";

}

