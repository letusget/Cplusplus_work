#include "Random.h"

void Guess(CRandom& hRandom);
int main()
{
	while (1)
	{
		CRandom Rand(10,10);
		

		//��ӡ��Ϸ����
		cout << endl;
		cout << "========================================" << endl;
		cout << "\t\t��������Ϸ��ʼ" << endl;
		cout << "========================================" << endl;
		cout << endl;

		Guess(Rand);
		cout << "========================================" << endl;
		cout << "��������0�˳���Ϸ,�����������ּ�����Ϸ"<<endl;
		int end;
		cin >> end;
		if (end==0)
		{
			Rand.~CRandom();
			exit(0);
		}
		else
		{
			cout << "����Ϸ��ʼ��" << endl;
			
		}


	}
	//Guess(Rand);
	
	

	return 0;
}

int getPrint()  //�Ӽ��̻�ȡ���������
{
	int num = 0;
	cout << endl;
	cout << "������һ������ ����Χ��0-9�� ��";
	cin >> num;
	cout << endl;

	while (num < 0 || num>9)
	{
		cout << "�������ִ���0-9�������������룺";
		cin >> num;
		cout << endl;
	}
	cout << "�������Ϊ��" << num << endl;
	return num;
}

void Guess(CRandom& hRandom)
{
	hRandom.Start();
	int num=getPrint();

	int result=hRandom.Judge(num);  //�жϽ���ķ���ֵ
	while (result)  //֪��������˳����ſ����˳�����
	{
		switch (result)
		{
		default:
			cout << "Error!!!" << endl;
			break;
		case 1:
			cout << "congration!";
			cout << endl;
			//exit (0);
			return;
			//����û��¶����֣����˳�����������ص�������
			break;

		case 2:
			cout << "Sorry, too small, remaining: "<< hRandom.getCount();
			cout << endl;
			break;
		case 3:
			cout << "Sorry, too large, remaining: "<<hRandom.getCount();
			cout << endl;
			break;
		case 4:
			cout << "Sorry, exhausted, value: "<<hRandom.getCount();
			cout << endl;
			return;
			//�²�������꣬�˳�ѭ��
			break;

		}
		cout << endl;

		num = getPrint();  //����û��²���󣬾ͼ����²�
		result = hRandom.Judge(num);  //�жϽ���ķ���ֵ

	}

	
	
}
