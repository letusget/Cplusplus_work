#include "CStuff.h"

void CStuff::setInfo(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender)
{
	m_nld = nId;
	m_pszNo = new char[strlen(pszNo) + 1];  //�����ڴ�ռ䣬��������Ŀռ��һ��
	strcpy(m_pszNo, pszNo);  
	/*�ַ������ƣ���Ϊchar* ���͵ı����ڳ�ʼ��֮����൱��һ������������ھ�̬��
	�����ڴ��ݲ�����ʱ�򣬾Ͳ��ò�ʹ��const ���Σ�������Ҫʵ�ֶ�����޸ĸ�ֵ���Ϳ���ʹ���ַ���������ʵ����

	*/
	m_pszName = new char[strlen(pszName) + 1];
	strcpy(m_pszName, pszName);
	m_nAge = nAge;
	m_nGender = nGender;

	//m_pszNo = new char[strlen(pszMajor) + 1];
	//strcpy(m_pszMajor, pszMajor);
}


