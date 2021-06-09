#include "Student.h"
#include "CTeacher.h"
#include "CExecutive.h"

int main()
{
	while(1)
	{ 
		//打印提示界面
		cout << "\t欢迎进入教务管理系统" << endl;
	cout << "===================================" << endl;
	cout << "\t1. 学生" << endl;
	cout << "\t2. 教师" << endl;
	cout << "\t3. 教职工" << endl;
	cout << "\t0. 退出" << endl;
	cout << "===================================" << endl;
	

	enum m_StuffType {
		STUDENT=1, //学生
		TEACHER, //教师
		EXECUTIVE, //行政人员

	};

	CStuff* Stuff;
	int choice;  //选择是哪个成员
	//m_StuffType choice;

	do
	{ //进行输入检查
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice==0||choice == 1 || choice == 2 || choice == 3)
		{
			break;  //输入正确选择时，才可以跳出循环
		}
		cin.clear();  //清除错误输入
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);

	switch (choice)
	{
	default:
		cout << "Error!!" << endl;
		break;
	case 0:
		exit(0);
		break;
	case 1:
		cout << "学生信息" << endl;
		/*
		CStudent stu1(1001, "Stu1001", "Tim", 20, 'm', "CS");
		CStuff* stuff_stu1 = &stu1;
		stu1.Print();
		*/

		Stuff = new CStudent(1001, "Stu1001", "Tim", 20, 'm', "CS");
		Stuff->Print();
		cout << endl;

		Stuff = new CStudent(1002, "Stu1002", "Amy", 21, 'f', "CS");
		Stuff->Print();

		cout << endl;
		break;
	case 2:
		cout << "教师信息" << endl;
		Stuff = new CTeacher(2001, "Teas001", "Tom", 35, 'f', "Docter");
		Stuff->Print();
		cout << endl;
		break;
	case 3:
		cout << "行政人员信息" << endl;
		Stuff = new CExecutive(3001, "Exes001", "Tam", 45, 'f', "Cleaner");
		Stuff->Print();
		cout << endl;
		break;

	}
	

	}



	return 0;
}