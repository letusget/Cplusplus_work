#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

void InputStudent(CStudent* pStudent);

long nId = 0;
string pszName = { 0 };
char nGender = { 0 };
int nAge = 0;
string pszMajor = {0};

int main() {
	vector<CStudent*> hVector;
	string Info[5] = { "number", "name", "性别", "年龄", "专业" };


	while (1) {
		CStudent* pszStudent = new CStudent;
		cout << "Enter " << Info[0] << ": ";
		cin >> nId;
		cout << endl;

		cout << "Enter " << Info[1] << ": ";
		cin >> pszName;
		cout << endl;

		cout << "Enter " << Info[2] << ": ";
		cin >> nGender;
		cout << endl;

		cout << "Enter " << Info[3] << ": ";
		cin >> nAge;
		cout << endl;

		cout << "Enter " << Info[4] << ": ";
		cin >> pszMajor;
		cout << endl;
			
		InputStudent(pszStudent);
		//hVector.push_back(pszStudent);
		pszStudent->Printf();
		break;

	}
	
	return 0;
}

void InputStudent(CStudent* pStudent) {
	pStudent->setInfo(nId, pszName, nAge, nGender, pszMajor);
}
