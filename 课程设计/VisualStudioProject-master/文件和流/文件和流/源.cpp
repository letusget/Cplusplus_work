#include <fstream>
#include <iostream>

using namespace std;

int main() {
	char data[100];

	// 以写模式打开文件
	ofstream outfile;
	outfile.open("afile.txt");

	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);

	// 向文件写入用户输入的数据
	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();

	// 再次向文件写入用户输入的数据
	outfile << data << endl;

	// 关闭打开的文件
	outfile.close();

	// 以读模式打开文件
	ifstream infile;
	infile.open("afile.dat");

	cout << "Reading from the file" << endl;
	
	// 读取文件数据并显示在屏幕上
	infile >> data;
	cout << data << endl;

	// 再次读取文件数据并显示
	infile >> data;
	cout << data << endl;

	// 关闭打开的文件
	infile.close();

	return 0;
}