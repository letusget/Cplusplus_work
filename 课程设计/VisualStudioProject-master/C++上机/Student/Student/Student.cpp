#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void CStudent::Printf() {
	cout << "ѧ�ţ�" << m_nId << endl;
	cout << "������" << m_pszName << endl;
	cout << "�Ա�" << m_nGender << endl;
	cout << "���䣺" << m_nAge << endl;
	cout << "רҵ��" << m_pszMajor << endl;
}

void CStudent::setInfo(long nId, string pszName, int nAge, char nGender, string pszMajor) {
	m_nId = nId;
	m_pszName = pszName;
	m_nAge = nAge;
	m_nGender = nGender;
	m_pszMajor = pszMajor;
}
