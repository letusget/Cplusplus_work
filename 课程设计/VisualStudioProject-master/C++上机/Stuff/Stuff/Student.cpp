#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

void CStuff::setBasic(int nId, const char* pszNo, const char* pszName, int nAge, char nGender) {
	m_nId = nId;
	m_pszNo = new char[strlen(pszNo) + 1];
	strcpy(m_pszNo, pszNo);
	m_pszName = new char[strlen(pszName) + 1];
	strcpy(m_pszName, pszName);
	m_nAge = nAge;
	m_nGender = nGender;

}


void CStudent::Printf() {
	cout << "ID: " << m_nId << endl;
	cout << "学生编号: " << m_pszNo << endl;
	cout << "学生姓名: " << m_pszName << endl;
	cout << "年龄: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "性别:" << "男" << endl;
	}
	else {
		cout << "性别:" << "女" << endl;
	}
	cout << "专业" << m_pszMajor << endl;
}

void CTeacher::Printf() {
	cout << "ID: " << m_nId << endl;
	cout << "教师编号: " << m_pszNo << endl;
	cout << "教师姓名: " << m_pszName << endl;
	cout << "年龄: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "性别:" << "男" << endl;
	}
	else {
		cout << "性别:" << "女" << endl;
	}
	cout << "专业" << m_pszTitle << endl;
}

void CExecutive::Printf() {
	cout << "ID: " << m_nId << endl;
	cout << "行政编号: " << m_pszNo << endl;
	cout << "人员姓名: " << m_pszName << endl;
	cout << "年龄: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "性别:" << "男" << endl;
	}
	else {
		cout << "性别:" << "女" << endl;
	}
	cout << "专业" << m_pszPosition << endl;
}




void CStudent::setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszMajor) {
	setBasic(nId, pszNo, pszName, nAge, nGender);
	m_pszMajor = new char[strlen(pszMajor) + 1];
	strcpy(m_pszMajor, pszMajor);
}


void CTeacher::setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszTitle) {
	setBasic(nId, pszNo, pszName, nAge, nGender);
	m_pszTitle = new char[strlen(pszTitle) + 1];
	strcpy(m_pszTitle, pszTitle);
}



void CExecutive::setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszPosition) {
	setBasic(nId, pszNo, pszName, nAge, nGender);
	m_pszPosition = new char[strlen(pszPosition) + 1];
	strcpy(m_pszPosition, pszPosition);
}
