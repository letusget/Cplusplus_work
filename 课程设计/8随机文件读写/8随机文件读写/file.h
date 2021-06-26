#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class ReadFile
{
public:
	//获取文章数据
	map<int, vector<string>>mFile;
	//存放文件名
	map<int, string>mFileName;
	//构造函数
	ReadFile();
	//读取文件
	void read();
	//重载操作符，实现从数据文件随机读写
	void operator[](int i);


};