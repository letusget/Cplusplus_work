#include "student.h"

/*
��string�̳������Ĵ��󣬻�����һ�����Ӵ���
�ο��� https://blog.csdn.net/hongbin_xu/article/details/79202697
�������������ѡ��ʹ��switch-case ��䣬�ᵼ����������֧����������Ͳ��ᱻִ�У��ᵼ�±���
*/
int main()
{
	while (1)
	{
		int choice = 1;
		string fileName1 = "student.dat";
		fstream infile(fileName1);
		if (!infile)
		{
			cout << "  ��ǰû��ѧ����Ϣ" << endl;
		}
		else
		{
			cout << "  �ɹ��ҵ�ѧ����Ϣ" << endl;
			//readFile(infile);
		}

		printMenu();  //չʾѡ��˵�

		do
		{ //����������
			//cout << "����������ѡ��";
			cin >> choice;
			if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
			{
				break;  //������ȷѡ��ʱ���ſ�������ѭ��
			}
			cin.clear();  //�����������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//���Ժܺõĸ������д�������
		} while (1);

		
		if (choice == 1)
		{
			//¼��ѧ����Ϣ
			cout << "  Ҫ���ѧ��������Ϊ��";
			int n;
			cin >> n;
			while (n <= 0)
			{
				cout << "�����������������: ";
				cin >> n;
			}

			for (int i = 0; i < n; i++)
			{
				add();
			}
			cout << "  ѧ����Ϣ��ӳɹ���";
			ofstream outFile(fileName1, fstream::trunc | fstream::out);
			cout << "  �ѳɹ��������ļ���" << fileName1 << endl;
			cout << endl;
			outFile.close();
		}
		else if (choice == 2)
		{
			//��ѯѧ����Ϣ
				cout << "***************************************" << endl;
				cout << "\t1.  ��ѯѧ��ID" << endl;
				cout << "\t2.  ��ѯѧ������" << endl;
				cout << "***************************************" << endl;
				int choice1 = 0;
				cout << "����������ѡ��";

				do
				{ //����������
					//cout << "����������ѡ��";
					cin >> choice;
					if (choice == 1 || choice == 2)
					{
						break;  //������ȷѡ��ʱ���ſ�������ѭ��
					}
					cin.clear();  //�����������
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (1);
				if (choice==1)
				{
					long stuId;
					cout << "������ѧ��ID��";
					cin >> stuId;
					searchID(stuId);
					cout << endl;
				}
				else if (choice==2)
				{
					string stuName;
					cout << "������ѧ��������";
					cin >> stuName;
					searchName(stuName);
					cout << endl;
				}
		}
		else if (choice == 3)
		{
			//ͳ��ѧ����Ϣ
			avgDegree();
		}
		else if (choice == 4)
		{
			//���ճɼ�����
			sortDegree();
		}
		else if(choice==5)
		{
			cout << "��Ϣ����ִ����������Զ�����ɹ���" << endl;
			cout << endl;
			cout << endl;
			//		//�����˳�
		}
		else
		{
			exit(0);
		}

	}
	return 0;
}