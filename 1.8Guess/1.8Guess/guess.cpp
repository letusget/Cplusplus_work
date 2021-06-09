#include "Random.h"

void Guess(CRandom& hRandom);
int main()
{
	while (1)
	{
		CRandom Rand(10,10);
		

		//打印游戏界面
		cout << endl;
		cout << "========================================" << endl;
		cout << "\t\t猜数字游戏开始" << endl;
		cout << "========================================" << endl;
		cout << endl;

		Guess(Rand);
		cout << "========================================" << endl;
		cout << "输入数字0退出游戏,输入其他数字继续游戏"<<endl;
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
			
		}


	}
	//Guess(Rand);
	
	

	return 0;
}

int getPrint()  //从键盘获取输入的数字
{
	int num = 0;
	cout << endl;
	cout << "请输入一个整数 （范围：0-9） ：";
	cin >> num;
	cout << endl;

	while (num < 0 || num>9)
	{
		cout << "输入数字错误（0-9），请重新输入：";
		cin >> num;
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
	while (result)  //知道语句内退出，才可以退出程序
	{
		switch (result)
		{
		default:
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
			//猜测次数用完，退出循环
			break;

		}
		cout << endl;

		num = getPrint();  //如果用户猜测错误，就继续猜测
		result = hRandom.Judge(num);  //判断结果的返回值

	}

	
	
}
