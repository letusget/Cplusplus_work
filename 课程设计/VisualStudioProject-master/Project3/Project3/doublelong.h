#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#ifndef _DOUBLELONG_H_
#define _DOUBLELONG_H_
class doublelong {
private:
	int* num;
	bool symbol;
	int length;
public:

	doublelong() {
		symbol = true;
		num = NULL;
		length = 0;
	}

	doublelong(string t) {
		num = new int[t.length()];
		if (t[0] != '-') {
			length = t.length();
			symbol = true;
			for (int i = t.length() - 1; i >= 0; i--) {
				num[t.length() - i - 1] = t[i] - '0';
			}
		}
		else {
			length = t.length() - 1;
			symbol = false;
			for (int i = t.length() - 1; i > 0; i--) {
				num[t.length() - i - 1] = t[i] - '0';
			}
		}
	}

	doublelong(long long t) {

		if (t >= 0) symbol = true;
		else {
			symbol = false;
			t = -t;
		}
		num = new int[100];
		if (t == 0) {
			num[0] = 0;
			length = 1;
			return;
		}
		int cnt = 0;
		while (t != 0) {
			num[cnt++] = t % 10;
			t /= 10;
		}

		length = cnt;

	}

	doublelong(int t[], int len, bool sym) {
		num = new int[len];
		length = len;
		for (int i = 0; i < len; i++)  num[i] = t[i];
		symbol = sym;
	}



	doublelong(const doublelong& t) {
		num = new int[t.length];
		length = t.length;
		for (int i = 0; i < length; i++) num[i] = t.num[i];
		symbol = t.symbol;
	}

	void operator = (long long x);


	doublelong operator + (doublelong& x);
	doublelong operator - (doublelong& x);
	doublelong operator * (doublelong& x);
	doublelong operator / (doublelong& x);
	doublelong& operator += (doublelong& x);
	doublelong& operator -= (doublelong& x);
	doublelong& operator *= (doublelong& x);
	doublelong& operator /= (doublelong& x);



	doublelong operator + (long long x);
	doublelong operator - (long long x);
	doublelong operator * (long long x);
	doublelong operator / (long long x);
	doublelong& operator += (long long x);
	doublelong& operator -= (long long x);
	doublelong& operator *= (long long x);
	doublelong& operator /= (long long x);

	friend istream& operator >> (istream& in, doublelong& x);
	friend ostream& operator << (ostream& out, doublelong& x);
};

void doublelong::operator = (long long t) {

	if (t >= 0) symbol = true;
	else {
		symbol = false;
		t = -t;
	}
	num = new int[100];
	if (t == 0) {
		num[0] = 0;
		length = 1;
		return;
	}
	int cnt = 0;
	while (t != 0) {
		num[cnt++] = t % 10;
		t /= 10;
	}

	length = cnt;

}



doublelong doublelong::operator + (doublelong& x) {
	int len = (length > x.length ? length : x.length) + 1;

	bool symj = symbol == x.symbol ? true : false;
	bool sym;
	int* t = new int[len];
	for (int i = 0; i < len; i++) t[i] = 0;
	int up = 0;
	if (symj) {
		sym = symbol;
		if (length > x.length) {
			for (int i = 0; i < length; i++) t[i] = num[i];
			for (int i = 0; i < x.length; i++) {
				t[i] += x.num[i] + up;
				up = t[i] / 10;
				t[i] = t[i] % 10;
			}
			t[x.length] += up;
			for (int i = x.length; i < length; i++)
				if (t[i] >= 10) {
					t[i + 1]++;
					t[i] = t[i] - 10;
				}
			if (t[length] == 0) len -= 1;
		}
		else {
			for (int i = 0; i < x.length; i++) t[i] = x.num[i];
			for (int i = 0; i < length; i++) {
				t[i] += num[i] + up;
				up = t[i] / 10;
				t[i] = t[i] % 10;
			}
			t[x.length] += up;
			for (int i = length; i < x.length; i++)
				if (t[i] >= 10) {
					t[i + 1]++;
					t[i] = t[i] - 10;
				}
			if (t[x.length] == 0) len -= 1;
		}
	}
	else {
		if (length > x.length) {
			sym = symbol;
			for (int i = 0; i < length; i++) t[i] = num[i];
			for (int i = 0; i < x.length; i++) {
				t[i] -= (up + x.num[i]);
				if (t[i] < 0) {
					t[i] = 10 + t[i];
					up = 1;
				}
				else up = 0;
			}
			t[x.length] -= up;
			for (int i = x.length; i < length; i++) {
				if (t[i] < 0) {
					t[i + 1]--;
					t[i] = 10 + t[i];
				}
			}

			if (t[len - 2] == 0) {
				len -= 2;
			}
			else len -= 1;

		}
		else if (length < x.length) {
			sym = x.symbol;
			for (int i = 0; i < x.length; i++) t[i] = x.num[i];
			for (int i = 0; i < length; i++) {
				t[i] -= (up + num[i]);
				if (t[i] < 0) {
					t[i] = 10 + t[i];
					up = 1;
				}
				else up = 0;
			}
			t[length] -= up;
			for (int i = length; i < x.length; i++) {
				if (t[i] < 0) {
					t[i + 1]--;
					t[i] = 10 + t[i];
				}
			}
			if (t[len - 2] == 0) {
				len -= 2;
			}
			else len -= 1;
		}
		else {
			int m = len - 2;
			while (num[m] == x.num[m]) m--;
			if (m < 0) {
				len = 1;
				t[0] = 0;
				sym = true;
			}
			else {
				len = m + 1;
				if (num[len - 1] > x.num[len - 1]) {
					sym = symbol;
					for (int i = 0; i < len; i++) t[i] = num[i];
					for (int i = 0; i < len; i++) {
						t[i] -= (up + x.num[i]);
						if (t[i] < 0) {
							t[i] = 10 + t[i];
							up = 1;
						}
						else up = 0;
					}

					t[len - 1] -= up;
					if (t[len - 1] == 0) {
						len -= 1;
					}


				}
				else {
					sym = x.symbol;
					for (int i = 0; i < x.length; i++) t[i] = x.num[i];
					for (int i = 0; i < length; i++) {
						t[i] -= (up + num[i]);
						if (t[i] < 0) {
							t[i] = 10 + t[i];
							up = 1;
						}
						else up = 0;
					}
					t[len - 1] -= up;
					if (t[len - 1] == 0) {
						len -= 1;
					}

				}
			}
		}
	}
	return doublelong(t, len, sym);
}
doublelong doublelong::operator+(long long x) {
	doublelong t(x);
	return *this + t;
}
doublelong& doublelong::operator += (doublelong& x) {
	*this = *this + x;
	return *this;
}
doublelong& doublelong::operator += (long long x) {
	*this = *this + x;
	return *this;
}







doublelong doublelong::operator-(doublelong& x) {
	x.symbol = !x.symbol;
	doublelong y;
	y = *this + x;
	x.symbol = !x.symbol;
	return y;
}
doublelong doublelong::operator-(long long x) {
	doublelong t(x);
	return *this - t;
}
doublelong& doublelong::operator -= (doublelong& x) {
	*this = *this - x;
	return *this;
}
doublelong& doublelong::operator -= (long long x) {
	*this = *this - x;
	return *this;
}







doublelong doublelong::operator*(doublelong& x) {
	int* t = new int[length + x.length];
	for (int i = 0; i < length + x.length; i++) {
		t[i] = 0;
	}
	int len = 0;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < x.length; j++) {
			t[i + j] += num[i] * x.num[j];
		}

	for (int i = 0; i < length + x.length - 1; i++) {
		t[i + 1] += t[i] / 10;
		t[i] = t[i] % 10;
	}


	for (int i = length + x.length - 1; i >= 0; i--)
		if (t[i] != 0) {
			len = i + 1;
			break;
		}
	bool sym = !(symbol ^ x.symbol);
	if (len == 0) len = 1;
	return doublelong(t, len, sym);
}
doublelong doublelong::operator*(long long x) {
	doublelong t(x);
	return *this * t;
}
doublelong& doublelong::operator *= (doublelong& x) {
	*this = *this * x;
	return *this;
}
doublelong& doublelong::operator *= (long long x) {
	*this = *this * x;
	return *this;
}







doublelong doublelong::operator/(doublelong& x) {

	if (x.length == 1 && x.num[0] == 0) {
		cout << "divide error!!!!!!!!!!!!!!" << endl;
		return 0;
	}

	doublelong ans = 0;

	if (length >= x.length) {
		doublelong t, th = *this;

		th.symbol = true;
		doublelong* pow = new doublelong[length - x.length + 1];
		pow[0] = 1;
		for (int i = 0; i < length - x.length; i++) pow[i + 1] = pow[i] * 10;//指数表
		for (int i = length - x.length; i >= 0; i--) {
			t = x * pow[i];

			t.symbol = true;
			while (1) {//这个最多进行9次
				doublelong y = th - t;
				if (!y.symbol) break;
				th = th - t;

				ans = ans + pow[i];

			}
		}
	}
	else ans = 0;
	ans.symbol = !(this->symbol ^ x.symbol);
	return ans;
}
doublelong doublelong::operator/(long long x) {
	doublelong y(x);
	return *this / y;
}
doublelong& doublelong::operator /= (doublelong& x) {
	*this = *this / x;
	return *this;
}
doublelong& doublelong::operator /= (long long x) {
	*this = *this / x;
	return *this;
}



istream& operator >>(istream& in, doublelong& x) {
	string s;
	in >> s;
	x = s;
	return in;
}

ostream& operator <<(ostream& out, doublelong& x) {
	if (!x.symbol && !(x.num[0] == 0 && x.length == 1)) out << "-";
	for (int i = x.length - 1; i >= 0; i--) {
		out << x.num[i];
	}
	return out;
}

#endif // !_DOUBLELONG_H_
