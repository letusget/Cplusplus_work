#include "Student.h"
#include "CTeacher.h"
#include "CExecutive.h"

int main()
{
	enum m_StuffType {
		STUDENT = 1, //学生
		TEACHER, //教师
		EXECUTIVE, //行政人员

	};
	
	while (1)
	{

	//打印提示界面
		cout << "\t欢迎进入教务管理系统" << endl;
	cout << "===================================" << endl;
	cout << "\t1. 学生" << endl;
	cout << "\t2. 教师" << endl;
	cout << "\t3. 教职工" << endl;
	cout << "\t0. 退出" << endl;
	cout << "===================================" << endl;
	
	int choice;  //选择是哪个成员
	do
	{ //进行输入检查，仅有符合条件的才可以获取到
		cout << "请输入您的选择：";
		cin >> choice;
		if (choice == 0 || choice == 1 || choice == 2 || choice == 3)
		{
			break;  //输入正确选择时，才可以跳出循环
		}
		cin.clear();  //清除错误输入
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (1);

	switch (choice)
	{
	default:
		cout << "Error!!" << endl;  //输出意外的错误信息
		break;
	case 0:
		exit(0);  //退出
		break;
	case 1:
	{
		cout << "学生信息" << endl;
		CStudent stu1;  //子类对象
		CStuff* Stuff_stu1 = &stu1;  //通过父类来管理子类的地址
		stu1.setStu(1001, "Stu1001", "Tim", 20, 'm', "CS");  //传递初始化信息
		stu1.Print();  //输出信息
		cout << endl;

		CStudent stu2;
		CStuff* Stuff_stu2 = &stu2;
		stu2.setStu(1002, "Stu1002", "Amy", 20, 'f', "CS");
		stu2.Print();
		cout << endl;

		cout << endl;
		break;
	}
		
	case 2:
	{
		CTeacher tea;
		CStuff* Stuff_tea = &tea;
		tea.setTea(2001, "Tea2001", "Tom", 35, 'f', "Docter");
		tea.Print();
		cout << endl;
		cout << endl;
		break;
	}
		
	case 3:
	{
		CExecutive exe;
		CStuff* Stuff_exe = &exe;
		exe.setExe(3001, "Exe2001", "Cook", 45, 'f', "Cleaner");
		exe.Print();
		cout << endl;
		cout << endl;
		break;
	}
	}

	}
	return 0;
}