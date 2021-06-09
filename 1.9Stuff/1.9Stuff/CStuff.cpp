#include "CStuff.h"

void CStuff::setInfo(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender)
{
	m_nld = nId;
	m_pszNo = new char[strlen(pszNo) + 1];  //申请内存空间，这里申请的空间大一个
	strcpy(m_pszNo, pszNo);  
	/*字符串复制，因为char* 类型的变量在初始化之后就相当于一个常量，存放在静态区
	所以在传递参数的时候，就不得不使用const 修饰，而我们要实现对其的修改赋值，就可以使用字符串复制来实现了

	*/
	m_pszName = new char[strlen(pszName) + 1];
	strcpy(m_pszName, pszName);
	m_nAge = nAge;
	m_nGender = nGender;

	//m_pszNo = new char[strlen(pszMajor) + 1];
	//strcpy(m_pszMajor, pszMajor);
}


