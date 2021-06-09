#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  //微软的安全函数声明
#include <iostream>
#include <cstring>
using namespace std;

class CStuff
{
public:
	enum m_StuffType {
		STUDENT, //学生
		TEACHER, //教师
		EXECUTIVE, //行政人员

	};

	void setInfo(long nId, const char* pszNo, const char* pszName, int nAge,
		char nGender);
	virtual void Print() = 0;  //需要重写的抽象函数


protected:
	long m_nld;  //表示ID，使用该整数来唯一标识学生和教职员工
	char* m_pszNo;  //编号
	char* m_pszName;  //名称
	int m_nAge=0;  //年龄
	char m_nGender='m';  //性别


};
