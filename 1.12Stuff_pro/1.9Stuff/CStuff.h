#pragma once

#include <iostream>
#include <string>
using namespace std;

class CStuff
{
public:
	enum m_StuffType {
		STUDENT, //学生
		TEACHER, //教师
		EXECUTIVE, //行政人员

	};
public:
	
	virtual void Print() = 0;  //需要重写的抽象函数


protected:
	long m_nld;  //表示ID，使用该整数来唯一标识学生和教职员工
	string m_pszNo ;  //编号
	string m_pszName;  //名称
	int m_nAge;  //年龄
	char m_nGender;  //性别


};
