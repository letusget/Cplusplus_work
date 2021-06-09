#include <iostream>
#include "Commodity.h"

#define N 10 // 定义数组长度

using namespace std;

int main() {
	// 定义第一个商品信息
	
	cout << "欢迎登录商品信息系统！" << endl;
	cout << "========================================================" << endl;

	char commodityUpc1[N] = "A00A";
	//char* str1 = { "A00A"};
	/*含义是先新建一个字符串,内容是A00A 然后str1是一个头指针,指向这个串.但是这个新建串是
	作为const存在的,并不是一个可以编辑的变量,因此,一旦你想更改其中的值,
	程序就会挂掉,所以这里使用字符数组就很不错*/
	char commodityName1[N] = "Apple";
	char commodityManu1[N] = "CN";
	long nld1 = 1001;
	long nld2 = 1002;
	long nld3 = 1003;

	// 创建第一个商品对象，并对应初始化类成员变量
	CCommodity commodity1;
	commodity1.setInfo(nld1, commodityUpc1, commodityName1, 1.1, commodityManu1);


	// 同上
	char commodityUpc2[N] = "B00B";
	char commodityName2[N] = "Banana";
	char commodityManu2[N] = "JP";

	CCommodity commodity2;
	commodity2.setInfo(nld2, commodityUpc2, commodityName2, 2.2, commodityManu2);

	// 同上
	char commodityUpc3[N] = "C00C";
	char commodityName3[N] = "Corn";
	char commodityManu3[N] = "US";

	CCommodity commodity3;
	commodity3.setInfo(nld3, commodityUpc3, commodityName3, 3.3, commodityManu3);

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
	if (strcmp(acquireUpc, commodityUpc1) == 0) {  //strcmp比较两个字符串是否相等
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