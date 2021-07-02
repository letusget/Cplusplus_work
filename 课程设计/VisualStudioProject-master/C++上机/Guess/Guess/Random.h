#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef int Result; // 自定义类型名称

class CRandom {
public:
	CRandom(const int& nBound, const int& nLimit); // 生成随机数的上界，允许用户猜测的最大次数
	Result Judge(int nvaule); // 判断大小
	void Start(); // ⽣成随机数并将其保存在成员变量m_nValue中，并将表示当前已猜测次数的成员变量m_nCount复位
	int getValue(); // 获取随机数
	int getCount(); // 获取猜测次数

	enum Result { // 枚举结果常量
		EQUAL = 1,
		LESS,
		GREAT,
		EXCEED
	};

private:
	int m_nValue = 0; // 生成的随机数
	int m_nCount = 0; // 用户已猜测次数
	int m_nBound = 10;
	int m_nLimit = 10;
};