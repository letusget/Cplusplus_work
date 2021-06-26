#include "student.h"



//student::student(fstream& infile)
//{
//	//从文件中读取已有信息
//	infile >> name;
//	infile >> id;
//	infile >> gender;
//	infile >> English_degree;
//	infile >> Maths_degree;
//	infile >> Program_degree;
//	infile >> PE_degree;
//}

student::student(string name1, long id1, string gender1, float en_de1, float ma_de1, float pr_de1, float pe_de1)
{
	//实例化一个类
	this->name = name1;
	this->id = id1;
	this->gender = gender1;
	this->English_degree = en_de1;
	this->Maths_degree = ma_de1;
	this->Program_degree = pr_de1;
	this->PE_degree = pe_de1;
}

float student::getEnglish()
{
	return English_degree;
}

float student::getMathes()
{
	return Maths_degree;
}

float student::getProgram()
{
	return Program_degree;
}

float student::getPE()
{
	return PE_degree;
}


void printMenu()
{
	cout << "=============================================" << endl;
	cout << "\t欢迎进入学生学籍管理系统" << endl;
	cout << "\t1.  录入学生信息" << endl;
	cout << "\t2.  查询学生信息" << endl;
	cout << "\t3.  计算班级平均成绩" << endl;
	cout << "\t4.  按照各科成绩排序并存储" << endl;
	cout << "\t5.  保存学生信息" << endl;
	cout << "\t0.  退出系统" << endl;
	cout << endl;
	cout << "\t请输入您的选择：" << endl;
	cout << "=============================================" << endl;
}

bool searchID(long id)
{
	it = cla.begin();
	for (; it != cla.end(); it++)
	{//如果找到id 一致的，就输出学生信息，如果没有找到，就继续找下一个
		if (it->id==id)
		{
			cout <<it->name<<" " << it->id << " " << it->gender << " " << it->English_degree << " "
				<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
			break;
		}

	}
	cout << endl;
	if (it==cla.end())  //一直找到最后一条信息，都没有找到学生信息，就输出相应的错误提示
	{
		cout << "没有找到ID= " << id << " 的学生信息！" << endl;
	}
	cout << endl;
	return true;
}

bool searchName(string& name)
{
//与查找 ID 基本一致
	it = cla.begin();
	for (; it != cla.end(); it++)
	{//如果找到id 一致的，就输出学生信息，如果没有找到，就继续找下一个
		if (it->name == name)
		{
			cout << it->name << " " << it->id << " " << it->gender << " " << it->English_degree << " "
				<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
			break;
		}

	}
	cout << endl;

	if (it == cla.end())  //一直找到最后一条信息，都没有找到学生信息，就输出相应的错误提示
	{
		cout << "没有找到姓名为 " << name << " 的学生信息！" << endl;
	}
	cout << endl;
	return true;
}

bool add()
{
	string name;  //姓名
	long id;  //学号
	string gender;  //性别
	float English_degree;  //英语成绩
	float Maths_degree;  //数学成绩
	float Program_degree;  //程序设计成绩
	float PE_degree;   //体育成绩

	cout << "请输入学生信息：" << endl;
	cout << "姓名: ";
	cin >> name;
	cout << "学生ID: ";
	cin >> id;
	cout << "学生性别（男/女）: ";
	cin >> gender;
	cout << "学生英语成绩: ";
	cin >> English_degree;
	cout << "学生数学成绩: ";
	cin >> Maths_degree;
	cout << "学生程序设计成绩: ";
	cin >> Program_degree	;
	cout << "学生体育成绩: ";
	cin >> PE_degree;

	//将学生信息放入容器
	cla.push_back(student(name, id, gender, English_degree, Maths_degree, Program_degree, PE_degree));

	return true;
}

bool avgDegree()
{
	int num=0;
	float sumEng = 0, avgEng = 0;
	float sumMat = 0, avgMat = 0;
	float sumPro = 0, avgPro = 0;
	float sumPE = 0, avgPE = 0;
	it = cla.begin();
	for (num=0;it!=cla.end();it++)
	{
		/*sumEng += it->getEnglish();
		sumMat += it->getMathes();
		sumPro += it->getProgram();
		sumPE += it->getProgram();	*/

		sumEng += (*it).getEnglish();
		sumMat += (*it).getMathes();
		sumPro += (*it).getProgram();
		sumPE += (*it).getProgram();	
		num++;
	}
	cout << "sum= " << sumEng << " " << sumMat << "  " << sumPro << "  " << sumPE << endl;
	

	avgEng = sumEng / ((float)num);
	avgMat = sumMat / ((float)num );
	avgPro = sumPro / ((float)num );
	avgPE = sumPE / ((float)num );

	cout << "num= " << float(num) << endl;

	/*由于是在执行完存储之后，就会进行存文件，这样在计算平均分会就会出现问题，人数就会发生变化了*/

	/*avgEng = sumEng / ((float)num-1);
	avgMat = sumMat / ((float)num-1);
	avgPro = sumPro / ((float)num-1);
	avgPE = sumPE / ((float)num-1);*/
	
	cout << "下面是各科的平均分：" << endl;
	cout << "英语: " << avgEng << endl;
	cout << "数学: " << avgMat << endl;
	cout << "程序设计: " << avgPro << endl;
	cout << "体育: " << avgPE << endl;
	cout << endl;
	return true;
}

//按照各门成绩排序
bool cmpEnglish(student a,student b)
{
	return a.getEnglish() > b.getEnglish();
}
bool cmpMath(student a, student b)
{
	return a.getMathes() > b.getMathes();
}
bool cmpProgramming(student a, student b)
{
	return a.getProgram() > b.getProgram();
}
bool cmpPE(student a, student b)
{
	return a.getPE() > b.getPE();
}

bool sortDegree()
{
	ofstream outfileEng("English.dat", ios::out);  //打开English.dat 文件，并建立输入流
	if (!outfileEng)
	{//如果不能正确打开文件，就直接报错
		cout << "open error!!!" << endl;
		exit(1);
	}
	/*调用排序函数，
	（1）第一个是要排序的数组的起始地址。
	（2）第二个是结束的地址（最后一位要排序的地址）
	（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，
		此时默认的排序方法是从小到大排序。
	*/
	sort(cla.begin(), cla.end(), cmpEnglish);
	vector<student>::iterator iter_eng;
	//将内容存储到文件中
	for (iter_eng  = cla.begin();  iter_eng!=cla.end(); iter_eng++)  
	{
		outfileEng<<iter_eng->name<<" "<<iter_eng->id << " " << iter_eng->gender << " " << iter_eng->English_degree << " "
			<< iter_eng->Maths_degree << " " << iter_eng->Program_degree << " " << iter_eng->PE_degree<<endl;

	}
	outfileEng.close();  //关闭输入源

	//下面的操作与上面都是一样的，这里我选择将不同的排序的
	ofstream outfile_mat("Math.dat", ios::out);
	if (!outfile_mat) {
		cout << "open error!" << endl;
		exit(1);
	}
	sort(cla.begin(), cla.end(), cmpMath);
	vector<student>::iterator iter_ma;
	for (iter_ma = cla.begin(); iter_ma != cla.end(); iter_ma++)
	{
		outfile_mat << iter_ma->name << " " << iter_ma->id << " " << iter_ma->gender << " " << iter_ma->English_degree << " "
			<< iter_ma->Maths_degree << " " << iter_ma->Program_degree << " " << iter_ma->PE_degree;
	}
	outfile_mat.close();

	//下面的操作与上面都是一样的
	ofstream outfile_pro("Program.dat", ios::out);
	if (!outfile_pro) {
		cout << "open error!" << endl;
		exit(1);
	}
	sort(cla.begin(), cla.end(), cmpProgramming);
	vector<student>::iterator iter_pr;
	for (iter_pr = cla.begin(); iter_pr != cla.end(); iter_pr++)
	{
		outfile_pro << iter_pr->name << " " << iter_pr->id << " " << iter_pr->gender << " " << iter_pr->English_degree << " "
			<< iter_pr->Maths_degree << " " << iter_pr->Program_degree << " " << iter_pr->PE_degree;
	}
	outfile_pro.close();

	//下面的操作与上面都是一样的
	ofstream outfile_pe("PE.dat", ios::out);
	if (!outfile_pe) {
		cerr << "open error!" << endl;
		exit(1);
	}
	sort(cla.begin(), cla.end(), cmpPE);
	vector<student>::iterator iter_pe;
	for (iter_pe = cla.begin(); iter_pe != cla.end(); iter_pe++)
	{
		outfile_pe << iter_pe->name << " " << iter_pe->id << " " << iter_pe->gender << " " << iter_pe->English_degree << " "
			<< iter_pe->Maths_degree << " " << iter_pe->Program_degree << " " << iter_pe->PE_degree;
	}
	outfile_pe.close();

	cout << "output succeed!" << endl;

	return true;
}

//bool readFile(fstream& infile)
//{
//	while (!infile.eof())  //读取到文件尾
//	{
//		cla.push_back(infile);
//		infile.get();  //从文件流中读取，直到结尾
//	}
//	return true;
//}

bool saveFile(ofstream& outfile)
{
	bool emptyCheck = true;  //确定文件为空
	it = cla.begin();
	while (it!=cla.end())
	{
		if (!emptyCheck)  //文件非空，就执行
		{
			outfile << endl;  //如果是空文件则不添加回车符，否则先添加一个回车符，再输出下一条学生数据
		}
		outfile << it->name << " " << it->id << " " << it->gender << " " << it->English_degree << " "
			<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
		it++;
		emptyCheck = false;  //此时文件不为空

	}
	return true;

}
