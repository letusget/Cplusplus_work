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
	A.setInfo(1950801, "195080101", "张三", 18, 'M', "CS");
	ptr = &A;

	CTeacher B;
	B.setInfo(1110101,"111010111", "李四", 35, 'M', "讲师");

	CExecutive C;
	C.setInfo(1220202, "122020222", "王五", 45, 'M', "财务");

	int StuffType = 0;
	cout << "请选择输入要打印的成员：" << endl;
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