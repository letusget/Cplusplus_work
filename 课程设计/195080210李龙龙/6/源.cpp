#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	ifstream infile;
	infile.open("old.dat", ios::in);
	//如果文件为空或打开失败 输出错误提示
	if (!(infile.is_open())) {
		cout << "old.dat file opens fails!!!" << endl;
		exit(0);
	}

	string str;
	getline(infile, str, '\0');
	infile.close();

	//打开文件
	ofstream outfile1, outfile2;
	outfile1.open("new1.dat", ios::out);
	outfile2.open("new2.dat", ios::out);

	if (!(outfile1.is_open())) {
		cout << "new1.dat file opens fails!!!" << endl;
		exit(0);
	}
	if (!(outfile2.is_open())) {
		cout << "new2.dat file opens fails!!!" << endl;
		exit(0);
	}

	
	for (int i = 0; i < str.size(); i++) {
		//使用isdigit() 用来检测一个字符是否是十进制数字。
		if (isdigit(str[i])) {
			if (i != 0 && !isdigit(str[i - 1])) {
				outfile1 << " " << str[i];
				//如果不是数字，就放入一个空格
			}
			else {
				outfile1 << str[i];
			}
		}

		//使用isalpha() 函数用来检测一个字符是否是字母。
		if (isalpha(str[i])) {
			if (i != 0 && !isalpha(str[i - 1])) {
				outfile2 << " " << str[i];
			}
			else {
				outfile2 << str[i];
			}
		}
	}

	cout << "new1.dat file writes successfully!" << endl;
	cout << "new2.dat file writes successfully!" << endl;

	outfile1.close();
	outfile2.close();

	return 0;
}