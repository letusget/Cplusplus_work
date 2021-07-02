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
	cout << "ѧ�����: " << m_pszNo << endl;
	cout << "ѧ������: " << m_pszName << endl;
	cout << "����: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "�Ա�:" << "��" << endl;
	}
	else {
		cout << "�Ա�:" << "Ů" << endl;
	}
	cout << "רҵ" << m_pszMajor << endl;
}

void CTeacher::Printf() {
	cout << "ID: " << m_nId << endl;
	cout << "��ʦ���: " << m_pszNo << endl;
	cout << "��ʦ����: " << m_pszName << endl;
	cout << "����: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "�Ա�:" << "��" << endl;
	}
	else {
		cout << "�Ա�:" << "Ů" << endl;
	}
	cout << "רҵ" << m_pszTitle << endl;
}

void CExecutive::Printf() {
	cout << "ID: " << m_nId << endl;
	cout << "�������: " << m_pszNo << endl;
	cout << "��Ա����: " << m_pszName << endl;
	cout << "����: " << m_nAge << endl;
	if (m_nGender == 'M') {
		cout << "�Ա�:" << "��" << endl;
	}
	else {
		cout << "�Ա�:" << "Ů" << endl;
	}
	cout << "רҵ" << m_pszPosition << endl;
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
