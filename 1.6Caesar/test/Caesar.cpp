
#include "Caesar.h"

//CCaesar* CCaesar::instance = nullptr;
CCaesar* CCaesar::instance = new CCaesar();
CCaesar* CCaesar::getinstance()
{
	return instance;  //直接返回inatance
}

char CCaesar::code[len] = { '0' };

void CCaesar::menu()
{
	cout << "==================================================================" << endl;
	cout << "\t\t凯撒加密" << endl;

	cout << endl;
	cout << "本加密程序仅适用于大写英文和小写英文及, ; ' “ 其他字符均不支持" << endl;
	cout << "\t\t1. 加密字符" << endl;
	cout << "\t\t2. 解密字符" << endl;
	cout << "\t\t3. 显示密码表" << endl;
	cout << "\t\t0. 退出凯撒加密" << endl;
	cout << endl;
	cout << "==================================================================" << endl;
}

void CCaesar::init_Code()
{//初始化密码表，可以初始化为自己需要的任何字符
	for (int i = 0; i < 26; i++)
	{
		code[i] = char(65 + i);
	}
	for (int i = 0; i < 26; i++)
	{
		code[i + 26] = char(97 + i);
	}

	code[len - 1] = char(34);
	code[len - 2] = char(39);
	code[len - 3] = char(59);
	code[len - 4] = char(44);
}

void CCaesar::print_Code()
{
	for (int i = 0; i < len; i++)
	{
		cout << i << "  -------->" << code[i] << endl;
	}
}

char* CCaesar::Encrypt(char* conse1)  //加密函数
{
	for (int i = 0; i < (int)strlen(conse1); i++)
	{//遍历每一个字符
		for (int j = 0; j < len; j++)
		{//寻找该字符在密码表中的位置
			if (conse1[i] == code[j])
			{//找到就将其后移key个位置
				int temp = (j + key) % len;
				conse1[i] = code[temp];
				break;
			}
		}
	}
	return conse1;  //返回该字符串
}
char* CCaesar::Decrypt(char* conse2)  //解密函数
{
	for (int i = 0; i < (int)strlen(conse2); i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (conse2[i] == code[j])
			{
				int temp = (j + len - key) % len;
				//将密文数组中的值向前移动key个字符，+len和取模可以实现头尾相接
				conse2[i] = code[temp];
				break;
			}
		}
	}
	return conse2;
}

void CCaesar::deleteCaesar()
{
	delete instance;
}
