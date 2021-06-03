#pragma once
#include <iostream>
#include <string>
using namespace std;
#define size 32   //限定每次输入的字符串的长度
#define len 56  //密码本的长度
#define key 4   //秘钥长度

class CCaesar
{
private:
	static CCaesar* instance;  //单例对象，一个类对象指针
	CCaesar()
	{
		//cout << "创建一个单例对象" << endl;
	}
	~CCaesar()
	{
		//cout << "析构一个单例对象" << endl;
	}


public:
	static CCaesar* getinstance();
	static void menu();  //

	static char code[len];

	static void init_Code();  //初始化密码本
	
	static void print_Code();  //可以显示密码表
	
	static char* Encrypt(char* conse1);  //加密函数
	static char* Decrypt(char* conse2);  //解密函数


	static void deleteCaesar();  //负责调用析构函数，因为该类的构造和析构函数都是私有的，所以需要手动释放类

};



