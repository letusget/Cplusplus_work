#include "Random.h"

void Guess(CRandom& hRandom);  //猜测函数

int main()
{
	while (1)  //使用while循环可以一直运行，知道循环内部退出循环
	{
		CRandom Rand(10,10);  //默认构造函数，确定默认值
		

		//打印游戏界面
		cout << endl;
		cout << "========================================" << endl;
		cout << "\t\t猜数字游戏开始" << endl;
		cout << "========================================" << endl;
		cout << endl;

		Guess(Rand);
		cout << "========================================" << endl;
		cout << "输入数字0退出游戏,输入其他数字继续游戏"<<endl;
		cout << "请输入：>>";
		int end;
		cin >> end;
		if (end==0)
		{
			Rand.~CRandom();
			exit(0);
		}
		else
		{
			cout << "新游戏开始！" << endl;
			cout << endl;
			cout << endl;
			
		}

	}
	//Guess(Rand);
	
	return 0;
}

int getPrint()  //从键盘获取输入的数字
{
	int num = 0;
	cout << endl;
	cout << "请输入您猜测的整数 （范围：0-9） ：";
	cin >> num;
	cout << endl;

	while (num < 0 || num>9)
	{
		cout << "输入数字错误（0-9），请重新输入：";
		cin >> num;  //防止输入错误，知道输入正确才可以退出循环
		cout << endl;
	}
	cout << "您输入的为：" << num << endl;
	return num;
}

void Guess(CRandom& hRandom)
{
	hRandom.Start();
	int num=getPrint();

	int result=hRandom.Judge(num);  //判断结果的返回值
	while (result)  //直到语句内退出，才可以退出程序
	{
		switch (result)
		{
		default:  //出现错误的情形
			cout << "Error!!!" << endl;
			break;
		case 1:
			cout << "congration!";
			cout << endl;
			//exit (0);
			return;
			//如果用户猜对数字，就退出这个函数，回到主函数
			break;

		case 2:
			cout << "Sorry, too small, remaining: "<< hRandom.getCount();
			cout << endl;
			break;

		case 3:
			cout << "Sorry, too large, remaining: "<<hRandom.getCount();
			cout << endl;
			break;

		case 4:
			cout << "Sorry, exhausted, value: "<<hRandom.getCount();
			cout << endl;
			return;
			//猜测次数用完，退出循环,回到主函数
			break;

		}
		cout << endl;

		num = getPrint();  //如果用户猜测错误，就继续猜测
		result = hRandom.Judge(num);  //判断结果的返回值

	}

	
	
}
