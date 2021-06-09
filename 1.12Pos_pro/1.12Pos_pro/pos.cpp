#include "commodity.h"

void create_commodity();

int main()
{
	
	while (1)
	{
		// 创建第一个商品对象，并对应初始化类成员变量
		string commodityUpc1 = "A00A";
		string commodityName1 = "Apple";
		string commodityManu1 = "CN";
		long nld1 = 1001;
		CCommodity commodity1;
		commodity1.setInfo(nld1, commodityUpc1, commodityName1, 1.1, commodityManu1);

		// 创建第二个商品对象
		string commodityUpc2 = "B00B";
		string commodityName2 = "Banana";
		string commodityManu2 = "JP";
		long nld2 = 1002;
		CCommodity commodity2;
		commodity2.setInfo(nld1, commodityUpc2, commodityName2, 2.2, commodityManu2);

		// 创建第三个商品对象
		string commodityUpc3 = "C00C";
		string commodityName3 = "Corn";
		string commodityManu3 = "US";
		long nld3 = 1003;
		CCommodity commodity3;
		commodity3.setInfo(nld3, commodityUpc3, commodityName3, 3.3, commodityManu3);

		//打印欢迎信息和基本产品信息
		cout << "欢迎登录商品信息系统！" << endl;
		cout << "========================================================" << endl;
		// 展示产品代码
		cout << "现有产品代码为:"
			<< commodityUpc1 << "\t"
			<< commodityUpc2 << "\t"
			<< commodityUpc3;
		cout << endl;
		cout << "\t1. 添加新产品" << endl;
		cout << "\t2. 使用现有产品信息" << endl;
		cout << "\t0. 退出系统" << endl;
		cout << "========================================================" << endl;


		int choice = 0;
		
		do
		{ //进行输入检查
			cout << "请输入您的选择：";
			cin >> choice;
			if (choice==0||choice==1||choice==2)
			{
				break;  //输入正确选择时，才可以跳出循环
			}
			cin.clear();  //清除错误输入
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		} while (1);

		switch (choice)
		{
		default:
			cout << "Error!!" << endl;
			break;
		case 1:
			create_commodity();
			break;
		case 2:
		{//这里一定要用 {},否则会报错，参考：https://blog.csdn.net/dashumak/article/details/88680551
			// 用户选择产品
			cout << "请输入产品代码:" << endl;
			//char acquireUpc[10] = {};
			string acquireUpc = "0";
			cin >> acquireUpc;

			// 根据用户选择的产品代码，显示对应的产品信息
			if (acquireUpc == commodityUpc1) {  //strcmp比较两个字符串是否相等
				commodity1.acquire(acquireUpc);
				cout << "请输入购买数量："; // 计算总价
				int num;
				cin >> num;
				commodity1.total(num);
			}
			else if (acquireUpc == commodityUpc2) {
				commodity2.acquire(acquireUpc); cout << "请输入购买数量：";
				int num;
				cin >> num;
				commodity2.total(num);
			}
			else if (acquireUpc == commodityUpc3) {
				commodity3.acquire(acquireUpc); cout << "请输入购买数量：";
				int num;
				cin >> num;
				commodity3.total(num);
			}

			break;
		}
		case 0:
			cout << "成功退出系统" << endl;
			exit(0);
			break;
		}

	}
	

	return 0;
}

string getUpc(string upc)
{
	return upc;  //获取Upc，用于传递，但是代码还未完善
}

void create_commodity()
{
	string commodityUpc = "0";
	string commodityName = "0";
	string commodityManu = "0";
	long nld = 0;
	double price = 0;
	cout << "请输入产品标识码：";
	cin >> nld;
	cout << endl;

	cout << "请输入通用产品代码：";
	cin >> commodityUpc;
	cout << endl;
	getUpc(commodityUpc);  //获取Upc信息


	cout << "请输入产品名称：";
	cin >> commodityName;
	cout << endl;
	
	cout << "请输入产品价格:";
	cin >> price;
	cout << endl;

	cout << "请输入产品制造商:";
	cin >> commodityManu;
	cout << endl;

	CCommodity commodity;
	commodity.setInfo(nld, commodityUpc, commodityName, price, commodityManu);

	cout << "新产品添加成功！" << endl;

}