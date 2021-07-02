#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void CStudent::Printf() {
	cout << "学号：" << m_nId << endl;
	cout << "姓名：" << m_pszName << endl;
	cout << "性别：" << m_nGender << endl;
	cout << "年龄：" << m_nAge << endl;
	cout << "专业：" << m_pszMajor << endl;
}

void CStudent::setInfo(long nId, string pszName, int nAge, char nGender, string pszMajor) {
	m_nId = nId;
	m_pszName = pszName;
	m_nAge = nAge;
	m_nGender = nGender;
	m_pszMajor = pszMajor;
}
