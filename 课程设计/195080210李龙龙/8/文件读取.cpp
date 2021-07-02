#include "file.h"

int main()
{
	ReadFile reFile;
	reFile.read();
	while (true)
	{
		//打印一个简单的运行提示界面
		cout << "=============================================" << endl;
		cout << "\t已有文件" << endl;
		cout << "\t1.txt" << endl;
		cout << "\t2.txt" << endl;
		cout << "\t3.txt" << endl;
		cout << "\t4.txt" << endl;
		cout << "\t5.txt" << endl;
		cout << "请输入要访问的文件下标（1-5），输入0退出：" << endl;
		cout << "=============================================" << endl;

	
		int choice;
		do
		{ //进行输入检查
			cout << "请输入您的选择(1-5)：";
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
			{
				break;  //输入正确选择时，才可以跳出循环
			}
			cin.clear();  //清除错误输入
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (1);

		if (choice>=1&&choice<=5)
		{//实现随机访问文件
			reFile[choice];
		}
		else
		{
			cout << "成功退出系统！" << endl;
			exit(0);
		}
		

	}
	return 0;
}
