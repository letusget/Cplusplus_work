#include "file.h"

ReadFile::ReadFile()
{
	//创建索引与文件名，需要事先存在
	this->mFileName.insert(make_pair(1, "1.txt"));
	this->mFileName.insert(make_pair(2, "2.txt"));
	this->mFileName.insert(make_pair(3, "3.txt"));
	this->mFileName.insert(make_pair(4, "4.txt"));
	this->mFileName.insert(make_pair(5, "5.txt"));
	cout << "文件名获取成功！" << endl;
}

void ReadFile::read()
{
	for (int i = 1; i <=5; i++)
	{
		ifstream ifs;  //文件指针
		ifs.open(this->mFileName[i], ios::in);
		if (!ifs.is_open())
		{
			cout << "文件为空或打开失败！" << endl;
			cout << "请检查该目录下文件是否存在！" << endl;
		}
		vector<string>vTemp;  //用来存放文件内容
		string str;
		while (getline(ifs,str))//持续获取文件内容，知道文件内读取到空行
		{
			vTemp.push_back(str);  //将获取到的内容按行存取到容器中
		}
		this->mFile.insert(make_pair(i, vTemp));  //放入map容器
		vTemp.clear();
		ifs.close();  //在对文件读写完成之后，就关闭文件

	}
	cout << "文件读取成功！"<<endl;
}

void ReadFile::operator[](int i)
{
	cout << "下面是文件内容：" << endl;
	for (string str : this->mFile[i])
	{
		//直接输出文件的内容
		cout << str << endl;
		
	}
	cout << endl;
}
