#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef int Result;  //自定义的类型名称

class CRandom
{
public:
	
	CRandom(int nBound,int nLimit);  //生成随机数的上界  允许用户猜测的最大次数
	Result Judge(int nValue);  //对用户从键盘上输入的整数值进行判断并返回结果
	void Start();  //生成随机数并保存在成员变量m_nValue中,并将猜测次数复位m_nCount
/*int rand(void)⽣成下⼀个随机数，范围[0, RAND_MAX)，头⽂件cstdlib。注意不要超过构造函数中所给定的上界*/
	int getValue();  //获得随机数
	int getCount();  //获得猜测次数


	enum Result {  //枚举，方便使用switch-case语句根据返回值来输出不同内容
		EQUAL=1, //自定义顺序
		LESS,//2
		GREAT,//3
		EXCEED,//4
	};

	//~CRandom();  不提供默认析构函数，在类调用结束后，自动释放

private:
	int m_nValue = 0;  //生成随机数
	int m_nCount = 10;  //猜测次数

};


