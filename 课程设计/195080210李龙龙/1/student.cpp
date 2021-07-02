#include "student.h"



//student::student(fstream& infile)
//{
//	//���ļ��ж�ȡ������Ϣ
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
	//ʵ����һ����
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
	cout << "\t��ӭ����ѧ��ѧ������ϵͳ" << endl;
	cout << "\t1.  ¼��ѧ����Ϣ" << endl;
	cout << "\t2.  ��ѯѧ����Ϣ" << endl;
	cout << "\t3.  ����༶ƽ���ɼ�" << endl;
	cout << "\t4.  ���ո��Ƴɼ����򲢴洢" << endl;
	cout << "\t5.  ����ѧ����Ϣ" << endl;
	cout << "\t0.  �˳�ϵͳ" << endl;
	cout << endl;
	cout << "\t����������ѡ��" << endl;
	cout << "=============================================" << endl;
}

bool searchID(long id)
{
	it = cla.begin();
	for (; it != cla.end(); it++)
	{//����ҵ�id һ�µģ������ѧ����Ϣ�����û���ҵ����ͼ�������һ��
		if (it->id==id)
		{
			cout <<it->name<<" " << it->id << " " << it->gender << " " << it->English_degree << " "
				<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
			break;
		}

	}
	cout << endl;
	if (it==cla.end())  //һֱ�ҵ����һ����Ϣ����û���ҵ�ѧ����Ϣ���������Ӧ�Ĵ�����ʾ
	{
		cout << "û���ҵ�ID= " << id << " ��ѧ����Ϣ��" << endl;
	}
	cout << endl;
	return true;
}

bool searchName(string& name)
{
//����� ID ����һ��
	it = cla.begin();
	for (; it != cla.end(); it++)
	{//����ҵ�id һ�µģ������ѧ����Ϣ�����û���ҵ����ͼ�������һ��
		if (it->name == name)
		{
			cout << it->name << " " << it->id << " " << it->gender << " " << it->English_degree << " "
				<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
			break;
		}

	}
	cout << endl;

	if (it == cla.end())  //һֱ�ҵ����һ����Ϣ����û���ҵ�ѧ����Ϣ���������Ӧ�Ĵ�����ʾ
	{
		cout << "û���ҵ�����Ϊ " << name << " ��ѧ����Ϣ��" << endl;
	}
	cout << endl;
	return true;
}

bool add()
{
	string name;  //����
	long id;  //ѧ��
	string gender;  //�Ա�
	float English_degree;  //Ӣ��ɼ�
	float Maths_degree;  //��ѧ�ɼ�
	float Program_degree;  //������Ƴɼ�
	float PE_degree;   //�����ɼ�

	cout << "������ѧ����Ϣ��" << endl;
	cout << "����: ";
	cin >> name;
	cout << "ѧ��ID: ";
	cin >> id;
	cout << "ѧ���Ա���/Ů��: ";
	cin >> gender;
	cout << "ѧ��Ӣ��ɼ�: ";
	cin >> English_degree;
	cout << "ѧ����ѧ�ɼ�: ";
	cin >> Maths_degree;
	cout << "ѧ��������Ƴɼ�: ";
	cin >> Program_degree	;
	cout << "ѧ�������ɼ�: ";
	cin >> PE_degree;

	//��ѧ����Ϣ��������
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

	/*��������ִ����洢֮�󣬾ͻ���д��ļ��������ڼ���ƽ���ֻ�ͻ�������⣬�����ͻᷢ���仯��*/

	/*avgEng = sumEng / ((float)num-1);
	avgMat = sumMat / ((float)num-1);
	avgPro = sumPro / ((float)num-1);
	avgPE = sumPE / ((float)num-1);*/
	
	cout << "�����Ǹ��Ƶ�ƽ���֣�" << endl;
	cout << "Ӣ��: " << avgEng << endl;
	cout << "��ѧ: " << avgMat << endl;
	cout << "�������: " << avgPro << endl;
	cout << "����: " << avgPE << endl;
	cout << endl;
	return true;
}

//���ո��ųɼ�����
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
	ofstream outfileEng("English.dat", ios::out);  //��English.dat �ļ���������������
	if (!outfileEng)
	{//���������ȷ���ļ�����ֱ�ӱ���
		cout << "open error!!!" << endl;
		exit(1);
	}
	/*������������
	��1����һ����Ҫ������������ʼ��ַ��
	��2���ڶ����ǽ����ĵ�ַ�����һλҪ����ĵ�ַ��
	��3������������������ķ����������ǴӴ�СҲ���Ǵ�С���󣬻����Բ�д������������
		��ʱĬ�ϵ����򷽷��Ǵ�С��������
	*/
	sort(cla.begin(), cla.end(), cmpEnglish);
	vector<student>::iterator iter_eng;
	//�����ݴ洢���ļ���
	for (iter_eng  = cla.begin();  iter_eng!=cla.end(); iter_eng++)  
	{
		outfileEng<<iter_eng->name<<" "<<iter_eng->id << " " << iter_eng->gender << " " << iter_eng->English_degree << " "
			<< iter_eng->Maths_degree << " " << iter_eng->Program_degree << " " << iter_eng->PE_degree<<endl;

	}
	outfileEng.close();  //�ر�����Դ

	//����Ĳ��������涼��һ���ģ�������ѡ�񽫲�ͬ�������
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

	//����Ĳ��������涼��һ����
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

	//����Ĳ��������涼��һ����
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
//	while (!infile.eof())  //��ȡ���ļ�β
//	{
//		cla.push_back(infile);
//		infile.get();  //���ļ����ж�ȡ��ֱ����β
//	}
//	return true;
//}

bool saveFile(ofstream& outfile)
{
	bool emptyCheck = true;  //ȷ���ļ�Ϊ��
	it = cla.begin();
	while (it!=cla.end())
	{
		if (!emptyCheck)  //�ļ��ǿգ���ִ��
		{
			outfile << endl;  //����ǿ��ļ�����ӻس��������������һ���س������������һ��ѧ������
		}
		outfile << it->name << " " << it->id << " " << it->gender << " " << it->English_degree << " "
			<< it->Maths_degree << " " << it->Program_degree << " " << it->PE_degree;
		it++;
		emptyCheck = false;  //��ʱ�ļ���Ϊ��

	}
	return true;

}
