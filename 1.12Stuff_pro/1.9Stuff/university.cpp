#include "Student.h"
#include "CTeacher.h"
#include "CExecutive.h"

int main()
{
	while(1)
	{ 
		//��ӡ��ʾ����
		cout << "\t��ӭ����������ϵͳ" << endl;
	cout << "===================================" << endl;
	cout << "\t1. ѧ��" << endl;
	cout << "\t2. ��ʦ" << endl;
	cout << "\t3. ��ְ��" << endl;
	cout << "\t0. �˳�" << endl;
	cout << "===================================" << endl;
	

	enum m_StuffType {
		STUDENT=1, //ѧ��
		TEACHER, //��ʦ
		EXECUTIVE, //������Ա

	};

	CStuff* Stuff;
	int choice;  //ѡ�����ĸ���Ա
	//m_StuffType choice;

	do
	{ //����������
		cout << "����������ѡ��";
		cin >> choice;
		if (choice==0||choice == 1 || choice == 2 || choice == 3)
		{
			break;  //������ȷѡ��ʱ���ſ�������ѭ��
		}
		cin.clear();  //�����������
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);

	switch (choice)
	{
	default:
		cout << "Error!!" << endl;
		break;
	case 0:
		exit(0);
		break;
	case 1:
		cout << "ѧ����Ϣ" << endl;
		/*
		CStudent stu1(1001, "Stu1001", "Tim", 20, 'm', "CS");
		CStuff* stuff_stu1 = &stu1;
		stu1.Print();
		*/

		Stuff = new CStudent(1001, "Stu1001", "Tim", 20, 'm', "CS");
		Stuff->Print();
		cout << endl;

		Stuff = new CStudent(1002, "Stu1002", "Amy", 21, 'f', "CS");
		Stuff->Print();

		cout << endl;
		break;
	case 2:
		cout << "��ʦ��Ϣ" << endl;
		Stuff = new CTeacher(2001, "Teas001", "Tom", 35, 'f', "Docter");
		Stuff->Print();
		cout << endl;
		break;
	case 3:
		cout << "������Ա��Ϣ" << endl;
		Stuff = new CExecutive(3001, "Exes001", "Tam", 45, 'f', "Cleaner");
		Stuff->Print();
		cout << endl;
		break;

	}
	

	}



	return 0;
}