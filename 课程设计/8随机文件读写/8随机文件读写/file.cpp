#include "file.h"

ReadFile::ReadFile()
{
	//�����������ļ�������Ҫ���ȴ���
	this->mFileName.insert(make_pair(1, "1.txt"));
	this->mFileName.insert(make_pair(2, "2.txt"));
	this->mFileName.insert(make_pair(3, "3.txt"));
	this->mFileName.insert(make_pair(4, "4.txt"));
	this->mFileName.insert(make_pair(5, "5.txt"));
	cout << "�ļ�����ȡ�ɹ���" << endl;
}

void ReadFile::read()
{
	for (int i = 1; i <=5; i++)
	{
		ifstream ifs;  //�ļ�ָ��
		ifs.open(this->mFileName[i], ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ�Ϊ�ջ��ʧ�ܣ�" << endl;
			cout << "�����Ŀ¼���ļ��Ƿ���ڣ�" << endl;
		}
		vector<string>vTemp;  //��������ļ�����
		string str;
		while (getline(ifs,str))//������ȡ�ļ����ݣ�֪���ļ��ڶ�ȡ������
		{
			vTemp.push_back(str);  //����ȡ�������ݰ��д�ȡ��������
		}
		this->mFile.insert(make_pair(i, vTemp));  //����map����
		vTemp.clear();
		ifs.close();  //�ڶ��ļ���д���֮�󣬾͹ر��ļ�

	}
	cout << "�ļ���ȡ�ɹ���"<<endl;
}

void ReadFile::operator[](int i)
{
	cout << "�������ļ����ݣ�" << endl;
	for (string str : this->mFile[i])
	{
		//ֱ������ļ�������
		cout << str << endl;
		
	}
	cout << endl;
}
