#include "student.h"

/*
由string继承引发的错误，会引起一个链接错误
参考： https://blog.csdn.net/hongbin_xu/article/details/79202697
而且再这里很难选择使用switch-case 语句，会导致再其他分支里的语句根本就不会被执行，会导致报错
*/
int main()
{
	while (1)
	{
		int choice = 1;
		string fileName1 = "student.dat";
		fstream infile(fileName1);
		if (!infile)
		{
			cout << "  当前没有学生信息" << endl;
		}
		else
		{
			cout << "  成功找到学生信息" << endl;
			//readFile(infile);
		}

		printMenu();  //展示选择菜单

		do
		{ //进行输入检查
			//cout << "请输入您的选择：";
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
			{
				break;  //输入正确选择时，才可以跳出循环
			}
			cin.clear();  //清除错误输入
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//可以很好的隔绝所有错误输入
		} while (1);

		
		if (choice == 1)
		{
			//录入学生信息
			cout << "  要添加学生的数量为：";
			int n;
			cin >> n;
			while (n <= 0)
			{
				cout << "输入错误，请重新输入: ";
				cin >> n;
			}

			for (int i = 0; i < n; i++)
			{
				add();
			}
			cout << "  学生信息添加成功！";
			ofstream outFile(fileName1, fstream::trunc | fstream::out);
			cout << "  已成功保存至文件：" << fileName1 << endl;
			cout << endl;
			outFile.close();
		}
		else if (choice == 2)
		{
			//查询学生信息
				cout << "***************************************" << endl;
				cout << "\t1.  查询学生ID" << endl;
				cout << "\t2.  查询学生姓名" << endl;
				cout << "***************************************" << endl;
				int choice1 = 0;
				cout << "请输入您的选择：";

				do
				{ //进行输入检查
					//cout << "请输入您的选择：";
					cin >> choice;
					if (choice == 1 || choice == 2)
					{
						break;  //输入正确选择时，才可以跳出循环
					}
					cin.clear();  //清除错误输入
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (1);
				if (choice==1)
				{
					long stuId;
					cout << "请输入学生ID：";
					cin >> stuId;
					searchID(stuId);
					cout << endl;
				}
				else if (choice==2)
				{
					string stuName;
					cout << "请输入学生姓名：";
					cin >> stuName;
					searchName(stuName);
					cout << endl;
				}
		}
		else if (choice == 3)
		{
			//统计学生信息
			avgDegree();
		}
		else if (choice == 4)
		{
			//按照成绩排序
			sortDegree();
		}
		else if(choice==5)
		{
			cout << "信息已在执行完操作后自动保存成功！" << endl;
			cout << endl;
			cout << endl;
			//		//保存退出
		}
		else
		{
			exit(0);
		}

	}
	return 0;
}