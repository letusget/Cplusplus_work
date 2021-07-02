#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stdbool.h>

using namespace std;

//class community
//{
//public:
//	community();
//	student** stuArry;  //��������༶�ĸ���ѧ��
//	int number;  //�༶ѧ������
//
//	void print_menu();
//	void add_stu();
//	void get_stu();  //����ѧ����ʵ��ѧ���� ������ѧ�ŵĲ�ѯ
//	void get_degree();  //��ð༶ƽ���ɼ�
//	void sort_str();  //��ѧ�����ճɼ�����
//
//};



class student
{

public:
	//student(fstream &infile);  //�ļ�����,�ȶ�ȡ�ļ��Ƿ����Ѿ���õ���Ϣ
	//�ڹ�����ʱʵ����ѧ����Ϣ
	student(string name1, long id1, string gender1, float en_de1, float ma_de1, float pr_de1, float pe_de1);
	
	float getEnglish();
	float getMathes();
	float getProgram();
	float getPE();

	friend void printMenu();
	friend bool searchID(long id);  //ͨ��ID����ѧ��
	friend bool searchName(string &name);  //
	friend bool add();  //���ѧ����Ϣ
	friend bool avgDegree();  //�����ƽ����
	friend bool sortDegree();  //ͨ���ɼ�����
	//friend bool readFile(fstream &infile);  // ��ȡ�ļ�
	friend bool saveFile(ofstream &outfile);  //�����ļ�
	
private:
	string name;  //����
	long id;  //ѧ��
	string gender;  //�Ա�
	float English_degree;  //Ӣ��ɼ�
	float Maths_degree;  //��ѧ�ɼ�
	float Program_degree;  //������Ƴɼ�
	float PE_degree;   //�����ɼ�

};


 void printMenu();
 bool searchID(long id);  //ͨ��ID����ѧ��
 bool searchName(string& name);  //
 bool add();  //���ѧ����Ϣ
 bool avgDegree();  //�����ƽ����
 bool sortDegree();  //ͨ���ɼ�����
// bool readFile(fstream& infile);  // ��ȡ�ļ�
 bool saveFile(ofstream& outfile);  //�����ļ�

 vector<student> cla; //����������Ÿ���ѧ��
 vector<student>::iterator it;  //������