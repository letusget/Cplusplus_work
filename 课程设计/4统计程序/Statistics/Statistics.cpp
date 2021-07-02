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
	void Search();  //��������
	void Display();  //��ʾ
	~KeyWord();

private:
	string m_keyword[max];		//�ؼ��֣������֣�
	string m_filename;			//�ĵ�����
	long m_key;					//�ĵ��е�����
	long m_keycount;			//�����ּ���
	long m_nokeycount;			//�Ǳ����ּ���
	int m_keynum;
	int m_time;					//ɨ���ļ�����
};

void KeyWord::Display() {
	for (int i = 0; i < m_keynum; i++) {
		cout << m_keyword[i] << endl;
	}
}
void KeyWord::Search() {
	fstream file;		
	file.open(".\\" + m_filename + ".txt");		//�򿪵�ǰĿ¼�µ��ļ�
	ofstream record(".\\keywords.txt");			//�ļ�д��,��¼�����ּ������ĵ�ɨ������ͷǱ����ּ���

	char str[2000];			//���ĵ����ݴ�������str��
	int flag = 0;

	while (file.getline(str, 2000))  //��ȡ�ļ��е��ַ�
	{
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') {
				m_key++;
				char* word = new char[i + 1 - flag];  //�洢
				for (int j = flag; j < i; j++) 
				{
					word[j - flag] = str[j];
				}
				word[i - flag] = '\0';
				string st = string(word);

				if (st == m_keyword[0]) {  //ƥ��ͳ��
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
	file.clear();	//����ļ�������״̬
	file.seekg(0, ios::beg);	//�ص��ĵ��ײ�
	m_nokeycount = m_nokeycount + m_keycount;

	for (int w = 1; w < m_keynum; w++) 
	{
		while (file.getline(str, 2000))
		{
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!') 
				{
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
	cout << "һ����" << m_key << "������" << endl;
	cout << "������" << m_keycount << "�����ʲ�ƥ��" 
		<< ",��" << m_nokeycount << "������ƥ�䡣" << "һ��ɨ��" << m_time << "���ļ�";
	record << "�ؼ��ֳ��ִ�����" << m_keycount << "  �ǹؼ��ֳ��ִ��� " 
		<< m_nokeycount << "һ��ɨ��" << m_time << "���ļ�" << endl;

}

//������¼������
void KeyWord::SetData(string* keyword, string filename, long key, long kcon, long nkon, int keyn, int time) 
{
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
	//cout << "������������" << endl;
}
int main() {
	string file1;

	int count;
	int time1 = 0;
	cout << "����һ��ͳ���ļ��йؼ��ֵĳ���" << endl;
	cout << "����Ҫƥ����ļ�����";
	cin >> file1;
	cout << "����Ҫ���ҵĹؼ��ָ���(���Ϊ10)��";
	cin >> count;

	string* keywod = new string[count];
	for (int i = 0; i < count; i++) {
		cout << "�����" << i + 1 << "���ؼ���" << endl;
		cin >> keywod[i];  //��ȡ�ַ���
	}
	ofstream fot(".\\keyfile.txt", ios::in);
	for (int i = 0; i < count; i++) {
		fot << keywod[i] << "  ";  //�����ļ�
	}
	KeyWord KeySearch;
	KeySearch.SetData(keywod, file1, 0, 0, 0, count, time1);
	KeySearch.Search();
	return 0;
}
