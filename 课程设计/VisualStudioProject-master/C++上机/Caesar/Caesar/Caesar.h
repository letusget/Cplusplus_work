#pragma once
#include <iostream>
#include <string>

using namespace std;

#define size 32
#define len 56
#define key 4

class CCaesar {
private:
	static CCaesar* instance;  //单例对象，一个类对象指针
	CCaesar() {
		cout << "创建一个单例对象" << endl;
	}
	~CCaesar() {
		cout << "析构一个单例对象" << endl;
	}

public:
	static CCaesar* getinstance(); // 唯一示例函数

	static void menu(); // 显示菜单

	static char code[len]; // 密码本
	static void init_Code(); // 初始化密码本
	static void print_Code();  //可以显示密码本

	static char* Encrypt(char* conse1);  //加密函数
	static char* Decrypt(char* conse2);  //解密函数

	static void deleteCaesar(); // 删除单例对象
};
