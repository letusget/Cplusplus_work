#include "Student.h"

//CStudent::CStudent()
//{
//	cout << "CStudent �Ĺ��캯������" << endl;
//
//}

void CStudent::setStu(long nId, const char* pszNo, 
	const char* pszName, int nAge, char nGender, const char* pszMajor)
{
	//��ʹ�ø�������ʼ����������Ϣ
	setInfo(nId, pszNo, pszName, nAge, nGender);

	//�ٰ��������Ϣ��� �����
	m_pszMajor = new char[strlen(pszMajor) + 1];
	strcpy(m_pszMajor, pszMajor);
}


void CStudent::Print()
{
	cout << m_nld << "  " << m_pszNo << "  " << m_pszName 
		<< "  " << m_nAge << "  " << m_nGender << "  " << m_pszMajor<< " ";

}

