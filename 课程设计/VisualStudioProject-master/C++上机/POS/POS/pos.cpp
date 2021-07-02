#include <iostream>
#include "Commodity.h"

#define N 10 // 定义数组长度

using namespace std;

int main() {
	// 定义第一个商品信息
	/* 如果用new分配内存空间也可以，最好是vector
	 *	char* commodityUpc1 = new char[10]{};
	 *	cout << "输入第一个Upc：" << endl;
	 *	cin >> commodityUpc1;
	*/
	cout << "欢迎登录商品信息系统！" << endl;
	cout << "========================================================" << endl;

	char commodityUpc1[N] = "A00A";
	char commodityName1[N] = "Apple";
	char commodityManu1[N] = "CN";

	// 创建第一个商品对象，并对应初始化类成员变量
	CCommodity commodity1;
	commodity1.setInfo(1001, commodityUpc1, commodityName1, 1.1, commodityManu1);


	// 同上
	char commodityUpc2[N] = "B00B";
	char commodityName2[N] = "Banana";
	char commodityManu2[N] = "JP";

	CCommodity commodity2;
	commodity2.setInfo(1002, commodityUpc2, commodityName2, 2.2, commodityManu2);

	// 同上
	char commodityUpc3[N] = "C00C";
	char commodityName3[N] = "Corn";
	char commodityManu3[N] = "US";

	CCommodity commodity3;
	commodity3.setInfo(1003, commodityUpc3, commodityName3, 3.3, commodityManu3);

	// 展示产品代码
	cout << "所有产品代码为:"
		<< commodityUpc1 << "\t"
		<< commodityUpc2 << "\t"
		<< commodityUpc3 << endl;
	cout << "========================================================" << endl;

	// 用户选择产品
	cout << "请输入产品代码:" << endl;
	char acquireUpc[10] = {};
	cin >> acquireUpc;

	// 根据用户选择的产品代码，显示对应的产品信息
	if (strcmp(acquireUpc, commodityUpc1) == 0) {
		commodity1.acquire(acquireUpc);
		cout << "请输入购买数量："; // 计算总价
		int num;
		cin >> num;
		commodity1.total(num);
	}
	else if (strcmp(acquireUpc, commodityUpc2) == 0) {
		commodity2.acquire(acquireUpc); cout << "请输入购买数量：";
		int num;
		cin >> num;
		commodity2.total(num);
	}
	else if (strcmp(acquireUpc, commodityUpc3) == 0) {
		commodity3.acquire(acquireUpc); cout << "请输入购买数量：";
		int num;
		cin >> num;
		commodity3.total(num);

	}
	// delete[] commodityUpc1;

	return 0;
}