#include "Student.h"
#include "CTeacher.h"
#include "CExecutive.h"

int main()
{
	enum m_StuffType {
		STUDENT = 1, //ѧ��
		TEACHER, //��ʦ
		EXECUTIVE, //������Ա

	};
	
	while (1)
	{

	//��ӡ��ʾ����
		cout << "\t��ӭ����������ϵͳ" << endl;
	cout << "===================================" << endl;
	cout << "\t1. ѧ��" << endl;
	cout << "\t2. ��ʦ" << endl;
	cout << "\t3. ��ְ��" << endl;
	cout << "\t0. �˳�" << endl;
	cout << "===================================" << endl;
	
	int choice;  //ѡ�����ĸ���Ա
	do
	{ //���������飬���з��������Ĳſ��Ի�ȡ��
		cout << "����������ѡ��";
		cin >> choice;
		if (choice == 0 || choice == 1 || choice == 2 || choice == 3)
		{
			break;  //������ȷѡ��ʱ���ſ�������ѭ��
		}
		cin.clear();  //�����������
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (1);

	switch (choice)
	{
	default:
		cout << "Error!!" << endl;  //�������Ĵ�����Ϣ
		break;
	case 0:
		exit(0);  //�˳�
		break;
	case 1:
	{
		cout << "ѧ����Ϣ" << endl;
		CStudent stu1;  //�������
		CStuff* Stuff_stu1 = &stu1;  //ͨ����������������ĵ�ַ
		stu1.setStu(1001, "Stu1001", "Tim", 20, 'm', "CS");  //���ݳ�ʼ����Ϣ
		stu1.Print();  //�����Ϣ
		cout << endl;

		CStudent stu2;
		CStuff* Stuff_stu2 = &stu2;
		stu2.setStu(1002, "Stu1002", "Amy", 20, 'f', "CS");
		stu2.Print();
		cout << endl;

		cout << endl;
		break;
	}
		
	case 2:
	{
		CTeacher tea;
		CStuff* Stuff_tea = &tea;
		tea.setTea(2001, "Tea2001", "Tom", 35, 'f', "Docter");
		tea.Print();
		cout << endl;
		cout << endl;
		break;
	}
		
	case 3:
	{
		CExecutive exe;
		CStuff* Stuff_exe = &exe;
		exe.setExe(3001, "Exe2001", "Cook", 45, 'f', "Cleaner");
		exe.Print();
		cout << endl;
		cout << endl;
		break;
	}
	}

	}
	return 0;
}