#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<ctime>

using namespace std;
#define User_Num 4	//用户个数
#define FDT 1		//固定长途电话
#define FLT 2		//固定本地电话
#define	WDT 3		//无线长途电话
#define	WLT 4		//无线本地电话
#define	WAP 5		//无线接听电话

const char *UserTel[User_Num] = {"19850350929","13765188640","13862896766"};
/* char *UserTel[User_Num] = {"19850350929","13765188640","13862896766"};
这里出现过（E0144"const char *" 类型的值不能用于初始化 "char *" 类型的实体）的问题
可以将char类型强制转换char*来解决
即char *UserTel[User_Num] = {(char*)"19850350929",(char*)"13765188640",(char*)"13862896766"};
也可以先使用字符数组对字符进行存储，再使用指针
也可以就在前面加上const*/

const char* CodeStr[User_Num] = {"abcdef","123456","a1b2c3"};
static int login = 0;

void clear();//清屏操作
void ui(const char* loguser);//ui界面
void load();
int MUAC(const char* tel, const char* code);//账号和密码匹配判断操作
void log(char ss[]);//登录操作
void logOut(char* user);//登出操作

void clear()//清屏
{
	system("cls");
}

void ui(const char *loguser)//ui界面，指针变量loguser判断用户是否已经登录
{
	cout << "" << endl;
	cout << "模拟电信计费程序" << endl;
	if (loguser == NULL)//如果用户名为空，显示未登录，否则显示用户名
	{
		 cout << "   (未登录)" <<  endl;
	}
	else
	{
		 cout << loguser <<  endl;
	}
	 cout << "===============================================================" <<  endl;
	 cout << "1.登录" << "(输入你的手机号和密码)" <<  endl;
	 cout << "2.查询账单" <<  endl;
	 cout << "0.退出程序" <<  endl;
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
	system("cls");//清屏
}

int MUAC(const char* tel, const char* code)//判断用户与密码是否匹配
{
	int ret = -1, id = -1, i = 0;
	if (tel == NULL || code == NULL)	//都为空,返回值为-1
		return -1;
	for (i = 0; i < User_Num; i++)//遍历用户数组,用strncmp()函数比较tel是否是有效号码，若是有效号码得出号码在数组中的位置，然后退出
	{
		if (strncmp(tel, UserTel[i], 11) == 0)
		{
			id = i;
			ret = 0;					//有效号码ret=0
			break;
		}
	}
	if (ret == -1)						//非正确号码ret=1
	{
		ret = 1;
		return ret;
	}
	if (strncmp(code, CodeStr[id], 6)!= 0)//非正确密码ret=2
		ret = 2;
	return ret;
}

void log(char ss[])
{
	char user[12]="\0", code[7]="\0";//定义两个字符数组用来存放手机号和密码
	int matchstate = 0, count = 1;

	while (count <= 3)//有三次输入机会
	{
			cout << "请输入的手机号:" << endl;
			cin >> user;
			cout << "请输入的密码:" << endl;
			cin >> code;
			if (strlen(user) == 11 && strlen(code) == 6)//如果手机号和密码长度正确，退出
				break;
			else
			{
				count++;
			}
			if(count > 1)
			{
				cout << "输入有错误,请重新输入" << endl;
		}
	}
	if (count >= 4)
		{
			clear();
			cout << "===错误次数过多===" << endl;
			ui(NULL);
		}
	else
	{
		matchstate = MUAC(user, code);
		switch (matchstate)
		{
			case 0://返回0，登录成功，改变登录状态
				clear();
				load();
				clear();
				cout << "===  已 登 陆  ===" << endl;
				strncpy(ss, user, 11);
				ss[11]='\0';
				login = 1;
				ui(user);
				break;

			case 1://返回1，手机号错
				clear();
				cout << "===  手机号错误  ===" << endl;
				ui(NULL);
				break;

			case 2:
				clear();//返回2，说明输入的密码错误，返回最开始的登录ui
				cout << "=== 密码错误  ===" << endl;
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
	const char* ss[] = { "C:/电脑/桌面/FDT.txt","C:/电脑/桌面/FLT.txt","C:/电脑/桌面/WDT.txt","C:/电脑/桌面/WLT.txt","C:/电脑/桌面/WAP.txt" };
	for (i = 0; i <= User_Num; i++)//遍历用户数组,用strncmp()函数比较tel是否是有效号码
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
		if (NULL == fpRead)//打开失败，返回-1
		{
			return -1;
		}
		j = 0;
		while (fscanf(fpRead, "%d|%d", &k[j][0], &k[j][1]) != EOF)// fscanf为文件标准输入，EOF是文件结束的标志，它等于NULL，也就是0.
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
				cout << "信息被修改" << endl;
				ui(logUser);
				break;
			}
		}
	}
	cout << "您的本月话费账单如下:" << endl;
	cout << "手机号码:" << UserTel[id]<<endl;
	cout << "固定长途:" << tel_time[id][0]<< "秒" << "产生费用:"<< 0.02*tel_time[id][0] <<endl;
	cout << "固定本地:" << tel_time[id][1]<< "分钟" << "产生费用:"<< 0.06*tel_time[id][1] <<endl;
	cout << "无线长途:" << tel_time[id][2]<< "分钟" << "产生费用:"<< 1.00*tel_time[id][2] <<endl;
	cout << "无线本地:" << tel_time[id][3]<< "分钟" << "产生费用:"<< 0.60*tel_time[id][3] <<endl;
	cout << "无线接听:" << tel_time[id][4]<< "分钟" << "产生费用:"<< 0.50*tel_time[id][4] <<endl;
	cout << "总计费用:" << 0.02 * tel_time[id][0]+0.06 * tel_time[id][1]+1.00 * tel_time[id][2]+0.60 * tel_time[id][3]+0.50 * tel_time[id][4] <<endl;
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
		cout<<"请输入需要的服务:"<<endl;
		cin>>user_choice;
		if (user_choice==1 )
		{
			log(activeUser);
		}
		else if ( user_choice== 2)
		{
			if (login == 0)
			{
				cout<<"===========   系统需先登录   ==========="<<endl;
				ui(NULL);
			}
			else
			{
				queryBill(activeUser);
			}
		}

		else if (user_choice == 0)
		{
			cout<<"===========  服务已结束 ==========="<<endl;
			flag = 0;
		}

	}
	system("pause");
	return 0;
}