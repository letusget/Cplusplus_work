#include "file.h"

int main()
{
	ReadFile reFile;
	reFile.read();
	while (true)
	{
		//��ӡһ���򵥵�������ʾ����
		cout << "=============================================" << endl;
		cout << "\t�����ļ�" << endl;
		cout << "\t1.txt" << endl;
		cout << "\t2.txt" << endl;
		cout << "\t3.txt" << endl;
		cout << "\t4.txt" << endl;
		cout << "\t5.txt" << endl;
		cout << "������Ҫ���ʵ��ļ��±꣨1-5��������0�˳���" << endl;
		cout << "=============================================" << endl;

	
		int choice;
		do
		{ //����������
			cout << "����������ѡ��(1-5)��";
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
			{
				break;  //������ȷѡ��ʱ���ſ�������ѭ��
			}
			cin.clear();  //�����������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (1);

		if (choice>=1&&choice<=5)
		{//ʵ����������ļ�
			reFile[choice];
		}
		else
		{
			cout << "�ɹ��˳�ϵͳ��" << endl;
			exit(0);
		}
		

	}
	return 0;
}
