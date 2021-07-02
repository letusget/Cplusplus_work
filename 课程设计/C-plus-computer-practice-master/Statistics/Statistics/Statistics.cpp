#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#define max 10

using namespace std;
class KeyWord
{
public:
	KeyWord();
	void SetData(string* keyword, string filename, long key, long kcon, long nkcon, int keyn, int time);
	void Search();
	void Display();
	~KeyWord();

private:
	string m_keyword[max];		//关键字（保留字）
	string m_filename;			//文档名称
	long m_key;					//文档中单词数
	long m_keycount;			//保留字计数
	long m_nokeycount;			//非保留字计数
	int m_keynum;
	int m_time;					//扫描文件次数
};

void KeyWord::Display() {
	for (int i = 0; i < m_keynum; i++) {
		cout << m_keyword[i] << endl;
	}
}
void KeyWord::Search() {
	fstream file;		//handle
	file.open("C:\\Users\\lenovo\\Desktop\\" + m_filename + ".txt");		//打开文件
	ofstream record("C:\\Users\\lenovo\\Desktop\\keywords.txt");			//文件写入,记录保留字计数、文档扫描次数和非保留字计数

	char str[2000];															//将文档内容存入数组str中
	int flag = 0;

	while (file.getline(str, 2000))
	{
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') {
				m_key++;
				char* word = new char[i + 1 - flag];
				for (int j = flag; j < i; j++) {
					word[j - flag] = str[j];
				}
				word[i - flag] = '\0';
				string st = string(word);

				if (st == m_keyword[0]) {
					m_keycount++;
					flag = i + 1;
				}
				else {
					m_nokeycount++;
					flag = i + 1;
				}
				delete[]word;

			}
		}
		m_time++;
		flag = 0;
	}
	file.clear();						//清除文件流属性状态
	file.seekg(0, ios::beg);			//回到文档首部
	m_nokeycount = m_nokeycount + m_keycount;

	for (int w = 1; w < m_keynum; w++) {

		while (file.getline(str, 2000))
		{
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') {

					char* word = new char[i + 1 - flag];
					for (int j = flag; j < i; j++) {
						word[j - flag] = str[j];
					}
					word[i - flag] = '\0';
					string st = string(word);

					if (st == m_keyword[w]) {
						m_keycount++;
						flag = i + 1;
					}
					else {
						flag = i + 1;
					}
					delete[]word;

				}
			}

			m_time++;
			flag = 0;

		}
		file.clear();
		file.seekg(0, ios::beg);
	}

	m_nokeycount = m_nokeycount - m_keycount;
	cout << "一共有" << m_key << "个单词" << endl;
	cout << "其中有" << m_keycount << "个单词匹配" << ",有" << m_nokeycount << "个单词不匹配。" << "一共扫描" << m_time << "次文件";
	record << "关键字出现次数：" << m_keycount << "  非关键字出现次数 " << m_nokeycount << "一共扫描" << m_time << "次文件" << endl;

}
//将数据录入类中
void KeyWord::SetData(string* keyword, string filename, long key, long kcon, long nkon, int keyn, int time) {
	for (int i = 0; i < keyn; i++) {
		m_keyword[i] = keyword[i];
	}
	m_filename = filename;
	m_key = key;
	m_keycount = kcon;
	m_nokeycount = nkon;
	m_keynum = keyn;
	m_time = time;
}
KeyWord::KeyWord()
{
	m_keyword[0] = "xxx";
	m_filename = "xxx";
	m_keycount = 0;
	m_nokeycount = 0;
	m_time = 0;
}

KeyWord::~KeyWord()
{
}
int main() {
	string file1;

	int count;
	int time1 = 0;
	cout << "这是一个统计文件中关键字的程序" << endl;
	cout << "输入要匹配的文件名：";
	cin >> file1;
	cout << "输入要查找的关键字个数(最大为10)：";
	cin >> count;

	string* keywod = new string[count];
	for (int i = 0; i < count; i++) {
		cout << "输入第" << i + 1 << "个关键字" << endl;
		cin >> keywod[i];
	}
	ofstream fot("C:\\Users\\lenovo\\Desktop\\keyfile.txt", ios::in);
	for (int i = 0; i < count; i++) {
		fot << keywod[i] << "  ";
	}
	KeyWord KeySearch;
	KeySearch.SetData(keywod, file1, 0, 0, 0, count, time1);
	KeySearch.Search();
	return 0;
}
