#include <iostream>
#include "Caesar.h"

using namespace std;

int main() {
	CCaesar* caesar = CCaesar::getinstance();
	char plain[size];  //明文
	char cipher[size];  //密文
	CCaesar::init_Code();
	/*
	单例模式分为饿汉模式和懒汉模式
	单例模式中：一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，
	并提供一个访问它的全局访问点，该实例被所有程序模块共享
	饿汉模式：就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象。
	懒汉模式：等到用的的时候程序再创建实例对象
	参考：https://blog.csdn.net/Miss_Monster/article/details/88086933
	*/

	int num;
	while (1) {
		CCaesar::menu();
		cout << endl;

		cout << "请输入你要实现的功能：";
		cin >> num;
		while (num != 0 && num != 1 && num != 2 && num != 3) {
			cout << "选择错误，请重新输入：";
			cin >> num;
		}

		switch (num) {
		default:cout << "选择错误，请重新选择！" << endl;
			break;
		case 0:
			cout << "成功退出" << endl;
			exit(0);
			break;
		case 1:
			cout << "开始加密！" << endl;

			cout << "请输入明文（大小不超过32个字符）:" << endl;
			cin >> plain;

			CCaesar::Encrypt(plain);
			cout << "加密结果如下：" << endl;
			for (int i = 0; i < (int)strlen(plain); i++) {
				cout << plain[i];
			}
			cout << endl;
			break;

		case 2:
			cout << "开始解密！" << endl;
			cout << "请输入密文（大小不超过32个字符）:" << endl;
			cin >> cipher;

			CCaesar::Decrypt(cipher);
			cout << "解密结果如下：" << endl;
			for (int i = 0; i < (int)strlen(cipher); i++) {
				cout << cipher[i];
			}
			cout << endl;
			break;
		case 3:
			CCaesar::print_Code();
			break;
		}
	}
	CCaesar::deleteCaesar();
}