#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<ctime>

using namespace std;
#define User_Num 4	//�û�����
#define FDT 1		//�̶���;�绰
#define FLT 2		//�̶����ص绰
#define	WDT 3		//���߳�;�绰
#define	WLT 4		//���߱��ص绰
#define	WAP 5		//���߽����绰

const char *UserTel[User_Num] = {"19850350929","13765188640","13862896766"};
/* char *UserTel[User_Num] = {"19850350929","13765188640","13862896766"};
������ֹ���E0144"const char *" ���͵�ֵ�������ڳ�ʼ�� "char *" ���͵�ʵ�壩������
���Խ�char����ǿ��ת��char*�����
��char *UserTel[User_Num] = {(char*)"19850350929",(char*)"13765188640",(char*)"13862896766"};
Ҳ������ʹ���ַ�������ַ����д洢����ʹ��ָ��
Ҳ���Ծ���ǰ�����const*/

const char* CodeStr[User_Num] = {"abcdef","123456","a1b2c3"};
static int login = 0;

void clear();//��������
void ui(const char* loguser);//ui����
void load();
int MUAC(const char* tel, const char* code);//�˺ź�����ƥ���жϲ���
void log(char ss[]);//��¼����
void logOut(char* user);//�ǳ�����

void clear()//����
{
	system("cls");
}

void ui(const char *loguser)//ui���棬ָ�����loguser�ж��û��Ƿ��Ѿ���¼
{
	cout << "" << endl;
	cout << "ģ����żƷѳ���" << endl;
	if (loguser == NULL)//����û���Ϊ�գ���ʾδ��¼��������ʾ�û���
	{
		 cout << "   (δ��¼)" <<  endl;
	}
	else
	{
		 cout << loguser <<  endl;
	}
	 cout << "===============================================================" <<  endl;
	 cout << "1.��¼" << "(��������ֻ��ź�����)" <<  endl;
	 cout << "2.��ѯ�˵�" <<  endl;
	 cout << "0.�˳�����" <<  endl;
}

void load()
{
	int i, count = 0;
	char str[50]="\0", str1[50]="\0";
	time_t t1, * t = &t1;

	printf("\n\n\n\n\n\n");
	printf("\t*                                                  *\n");
	printf("\t*                                                  *\n");
	printf("\t*                                                  *\n");
	printf("\t*                                                  *\n");
	printf("\t*             * * * *         * * * *          * * * * *\n");
	printf("\t*           *       *      *       *      *        *\n");
	printf("\t*          *         *    *         *    *         *\n");
	printf("\t*          *         *    *         *    *         *\n");
	printf("\t*           *       *      *       * *    *        *\n");
	printf("\t* * * *        * * * *          *     *   *      * * * * *\t");

	i = 6;
	do{
		t1 = time(NULL);
		strcpy(str, ctime(t));
		if (count == 6) break; 
		while (strcmp(str, str1) != 0)
		{
			strcpy(str1, str);
			 cout << ">" <<  endl;
			count++;
			break;
		}
	} while (1);
	system("cls");//����
}

int MUAC(const char* tel, const char* code)//�ж��û��������Ƿ�ƥ��
{
	int ret = -1, id = -1, i = 0;
	if (tel == NULL || code == NULL)	//��Ϊ��,����ֵΪ-1
		return -1;
	for (i = 0; i < User_Num; i++)//�����û�����,��strncmp()�����Ƚ�tel�Ƿ�����Ч���룬������Ч����ó������������е�λ�ã�Ȼ���˳�
	{
		if (strncmp(tel, UserTel[i], 11) == 0)
		{
			id = i;
			ret = 0;					//��Ч����ret=0
			break;
		}
	}
	if (ret == -1)						//����ȷ����ret=1
	{
		ret = 1;
		return ret;
	}
	if (strncmp(code, CodeStr[id], 6)!= 0)//����ȷ����ret=2
		ret = 2;
	return ret;
}

void log(char ss[])
{
	char user[12]="\0", code[7]="\0";//���������ַ�������������ֻ��ź�����
	int matchstate = 0, count = 1;

	while (count <= 3)//�������������
	{
			cout << "��������ֻ���:" << endl;
			cin >> user;
			cout << "�����������:" << endl;
			cin >> code;
			if (strlen(user) == 11 && strlen(code) == 6)//����ֻ��ź����볤����ȷ���˳�
				break;
			else
			{
				count++;
			}
			if(count > 1)
			{
				cout << "�����д���,����������" << endl;
		}
	}
	if (count >= 4)
		{
			clear();
			cout << "===�����������===" << endl;
			ui(NULL);
		}
	else
	{
		matchstate = MUAC(user, code);
		switch (matchstate)
		{
			case 0://����0����¼�ɹ����ı��¼״̬
				clear();
				load();
				clear();
				cout << "===  �� �� ½  ===" << endl;
				strncpy(ss, user, 11);
				ss[11]='\0';
				login = 1;
				ui(user);
				break;

			case 1://����1���ֻ��Ŵ�
				clear();
				cout << "===  �ֻ��Ŵ���  ===" << endl;
				ui(NULL);
				break;

			case 2:
				clear();//����2��˵�������������󣬷����ʼ�ĵ�¼ui
				cout << "=== �������  ===" << endl;
				ui(NULL);
				break;

			default:
				break;
		}
	}
}

int queryBill(const char* logUser)
{
	int i = 0, j = 0, id = -1;
	int k[6][2] = { 0 };
	int tel_time[6][5] = { 0 };
	const char* ss[] = { "C:/����/����/FDT.txt","C:/����/����/FLT.txt","C:/����/����/WDT.txt","C:/����/����/WLT.txt","C:/����/����/WAP.txt" };
	for (i = 0; i <= User_Num; i++)//�����û�����,��strncmp()�����Ƚ�tel�Ƿ�����Ч����
	{
		if (strncmp(logUser, UserTel[i], 11) == 0)
		{
			id = i;
			break;
		}
	}
	if (id < 0 || id >5)
		return  -2;
	for (i = 0; i < 5; i++)
	{
		FILE* fpRead = fopen(ss[i], "r");
		if (NULL == fpRead)//��ʧ�ܣ�����-1
		{
			return -1;
		}
		j = 0;
		while (fscanf(fpRead, "%d|%d", &k[j][0], &k[j][1]) != EOF)// fscanfΪ�ļ���׼���룬EOF���ļ������ı�־��������NULL��Ҳ����0.
		{
			if (j > 5)
				break;
			else
				j++;
		}
		fclose(fpRead);

		for (j = 0; j < 6; j++)
		{
			if (k[j][0] >= 1 && k[j][0] <= 6)
			{
				tel_time[k[j][0] - 1][i] = k[j][1];
				j++;
			}
			else
			{
				cout << "��Ϣ���޸�" << endl;
				ui(logUser);
				break;
			}
		}
	}
	cout << "���ı��»����˵�����:" << endl;
	cout << "�ֻ�����:" << UserTel[id]<<endl;
	cout << "�̶���;:" << tel_time[id][0]<< "��" << "��������:"<< 0.02*tel_time[id][0] <<endl;
	cout << "�̶�����:" << tel_time[id][1]<< "����" << "��������:"<< 0.06*tel_time[id][1] <<endl;
	cout << "���߳�;:" << tel_time[id][2]<< "����" << "��������:"<< 1.00*tel_time[id][2] <<endl;
	cout << "���߱���:" << tel_time[id][3]<< "����" << "��������:"<< 0.60*tel_time[id][3] <<endl;
	cout << "���߽���:" << tel_time[id][4]<< "����" << "��������:"<< 0.50*tel_time[id][4] <<endl;
	cout << "�ܼƷ���:" << 0.02 * tel_time[id][0]+0.06 * tel_time[id][1]+1.00 * tel_time[id][2]+0.60 * tel_time[id][3]+0.50 * tel_time[id][4] <<endl;
	return 0;
}

void logOut(char* user)
{
	if (user== NULL )
		return;

	login = 0;
	clear();
	ui(NULL);
}


int main(void)
{
	char activeUser[4];
	int user_choice = -1, flag = 1;

	ui(NULL);
	while (flag)
	{
		cout<<"��������Ҫ�ķ���:"<<endl;
		cin>>user_choice;
		if (user_choice==1 )
		{
			log(activeUser);
		}
		else if ( user_choice== 2)
		{
			if (login == 0)
			{
				cout<<"===========   ϵͳ���ȵ�¼   ==========="<<endl;
				ui(NULL);
			}
			else
			{
				queryBill(activeUser);
			}
		}

		else if (user_choice == 0)
		{
			cout<<"===========  �����ѽ��� ==========="<<endl;
			flag = 0;
		}

	}
	system("pause");
	return 0;
}