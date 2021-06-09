#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#define RAND_MIN 0   //随机数的最小值
#define RAND_MAX 10  //随机数最大值，猜测的最大值
//#define SIZE 10

using namespace std;
typedef int Result;  //自定义的类型名称

class CRandom
{
public:
	
	CRandom(int nBound,int nLimit);  //生成随机数的上界  允许用户猜测的最大次数
	Result Judge(int nValue);  //对用户从键盘上输入的整数值进行判断并返回结果
	void Start();  //生成随机数并保存在成员变量m_nValue中,并将猜测次数复位m_nCount
/*int rand(void)⽣成下⼀个随机数，范围[0, RAND_MAX)，头⽂件cstdlib。注意不要超过构造函数中所给定的上界*/
	int getValue();
	int getCount();


	enum Result {
		EQUAL=1, //1
		LESS,//2
		GREAT,//3
		EXCEED,//4
	};

	//~CRandom();

private:
	int m_nValue = 0;  //生成随机数
	int m_nCount = 10;  //猜测次数

};


