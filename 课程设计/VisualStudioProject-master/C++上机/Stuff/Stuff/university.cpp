#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	enum m_nType
	{
		STUDENT,
		TEACHER,
		EXECUTIVE
	};

	CStuff* ptr = NULL;
	CStudent A;
	A.setInfo(1950801, "195080101", "����", 18, 'M', "CS");
	ptr = &A;

	CTeacher B;
	B.setInfo(1110101,"111010111", "����", 35, 'M', "��ʦ");

	CExecutive C;
	C.setInfo(1220202, "122020222", "����", 45, 'M', "����");

	int StuffType = 0;
	cout << "��ѡ������Ҫ��ӡ�ĳ�Ա��" << endl;
	cin >> StuffType;
	switch (StuffType) {
	case STUDENT:
		ptr->Printf();
		break;
	case TEACHER:
		ptr->Printf();
		break;
	case EXECUTIVE:
		ptr->Printf();
		break;
	}

	return 0;
}