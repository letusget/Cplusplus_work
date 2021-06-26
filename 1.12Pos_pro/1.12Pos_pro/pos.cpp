#include "commodity.h"

void create_commodity();

int main()
{
	
	while (1)
	{
		// ������һ����Ʒ���󣬲���Ӧ��ʼ�����Ա����
		string commodityUpc1 = "A00A";
		string commodityName1 = "Apple";
		string commodityManu1 = "CN";
		long nld1 = 1001;
		CCommodity commodity1;
		commodity1.setInfo(nld1, commodityUpc1, commodityName1, 1.1, commodityManu1);

		// �����ڶ�����Ʒ����
		string commodityUpc2 = "B00B";
		string commodityName2 = "Banana";
		string commodityManu2 = "JP";
		long nld2 = 1002;
		CCommodity commodity2;
		commodity2.setInfo(nld1, commodityUpc2, commodityName2, 2.2, commodityManu2);

		// ������������Ʒ����
		string commodityUpc3 = "C00C";
		string commodityName3 = "Corn";
		string commodityManu3 = "US";
		long nld3 = 1003;
		CCommodity commodity3;
		commodity3.setInfo(nld3, commodityUpc3, commodityName3, 3.3, commodityManu3);

		//��ӡ��ӭ��Ϣ�ͻ�����Ʒ��Ϣ
		cout << "��ӭ��¼��Ʒ��Ϣϵͳ��" << endl;
		cout << "========================================================" << endl;
		// չʾ��Ʒ����
		cout << "���в�Ʒ����Ϊ:"
			<< commodityUpc1 << "\t"
			<< commodityUpc2 << "\t"
			<< commodityUpc3;
		cout << endl;
		cout << "\t1. ����²�Ʒ" << endl;
		cout << "\t2. ʹ�����в�Ʒ��Ϣ" << endl;
		cout << "\t0. �˳�ϵͳ" << endl;
		cout << "========================================================" << endl;


		int choice = 0;
		
		do
		{ //����������
			cout << "����������ѡ��";
			cin >> choice;
			if (choice==0||choice==1||choice==2)
			{
				break;  //������ȷѡ��ʱ���ſ�������ѭ��
			}
			cin.clear();  //�����������
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
		{//����һ��Ҫ�� {},����ᱨ���ο���https://blog.csdn.net/dashumak/article/details/88680551
			// �û�ѡ���Ʒ
			cout << "�������Ʒ����:" << endl;
			//char acquireUpc[10] = {};
			string acquireUpc = "0";
			cin >> acquireUpc;

			// �����û�ѡ��Ĳ�Ʒ���룬��ʾ��Ӧ�Ĳ�Ʒ��Ϣ
			if (acquireUpc == commodityUpc1) {  //strcmp�Ƚ������ַ����Ƿ����
				commodity1.acquire(acquireUpc);
				cout << "�����빺��������"; // �����ܼ�
				int num;
				cin >> num;
				commodity1.total(num);
			}
			else if (acquireUpc == commodityUpc2) {
				commodity2.acquire(acquireUpc); cout << "�����빺��������";
				int num;
				cin >> num;
				commodity2.total(num);
			}
			else if (acquireUpc == commodityUpc3) {
				commodity3.acquire(acquireUpc); cout << "�����빺��������";
				int num;
				cin >> num;
				commodity3.total(num);
			}

			break;
		}
		case 0:
			cout << "�ɹ��˳�ϵͳ" << endl;
			exit(0);
			break;
		}

	}
	

	return 0;
}

string getUpc(string upc)
{
	return upc;  //��ȡUpc�����ڴ��ݣ����Ǵ��뻹δ����
}

void create_commodity()
{
	string commodityUpc = "0";
	string commodityName = "0";
	string commodityManu = "0";
	long nld = 0;
	double price = 0;
	cout << "�������Ʒ��ʶ�룺";
	cin >> nld;
	cout << endl;

	cout << "������ͨ�ò�Ʒ���룺";
	cin >> commodityUpc;
	cout << endl;
	getUpc(commodityUpc);  //��ȡUpc��Ϣ


	cout << "�������Ʒ���ƣ�";
	cin >> commodityName;
	cout << endl;
	
	cout << "�������Ʒ�۸�:";
	cin >> price;
	cout << endl;

	cout << "�������Ʒ������:";
	cin >> commodityManu;
	cout << endl;

	CCommodity commodity;
	commodity.setInfo(nld, commodityUpc, commodityName, price, commodityManu);

	cout << "�²�Ʒ��ӳɹ���" << endl;

}