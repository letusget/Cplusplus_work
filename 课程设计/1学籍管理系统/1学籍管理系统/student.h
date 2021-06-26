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
//	student** stuArry;  //用来管理班级的各个学生
//	int number;  //班级学生人数
//
//	void print_menu();
//	void add_stu();
//	void get_stu();  //查找学生，实现学生的 姓名和学号的查询
//	void get_degree();  //获得班级平均成绩
//	void sort_str();  //对学生按照成绩排序
//
//};



class student
{

public:
	//student(fstream &infile);  //文件操作,先读取文件是否有已经存好的信息
	//在构造类时实例化学生信息
	student(string name1, long id1, string gender1, float en_de1, float ma_de1, float pr_de1, float pe_de1);
	
	float getEnglish();
	float getMathes();
	float getProgram();
	float getPE();

	friend void printMenu();
	friend bool searchID(long id);  //通过ID查找学生
	friend bool searchName(string &name);  //
	friend bool add();  //添加学生信息
	friend bool avgDegree();  //求各科平均分
	friend bool sortDegree();  //通过成绩排序
	//friend bool readFile(fstream &infile);  // 读取文件
	friend bool saveFile(ofstream &outfile);  //保存文件
	
private:
	string name;  //姓名
	long id;  //学号
	string gender;  //性别
	float English_degree;  //英语成绩
	float Maths_degree;  //数学成绩
	float Program_degree;  //程序设计成绩
	float PE_degree;   //体育成绩

};


 void printMenu();
 bool searchID(long id);  //通过ID查找学生
 bool searchName(string& name);  //
 bool add();  //添加学生信息
 bool avgDegree();  //求各科平均分
 bool sortDegree();  //通过成绩排序
// bool readFile(fstream& infile);  // 读取文件
 bool saveFile(ofstream& outfile);  //保存文件

 vector<student> cla; //容器用来存放各个学生
 vector<student>::iterator it;  //迭代器