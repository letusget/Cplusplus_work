#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	ifstream infile;
	infile.open("old.dat", ios::in);
	if (!(infile.is_open())) {
		cout << "old.dat file opens fails!!!" << endl;
		exit(0);
	}

	string str;
	getline(infile, str, '\0');
	infile.close();

	ofstream outfile1, outfile2;
	outfile1.open("new1.dat", ios::out);
	outfile2.open("new2.dat", ios::out);

	if (!(outfile1.is_open())) {
		cout << "new1.dat file opens fails!!!" << endl;
		exit(0);
	}
	if (!(outfile2.is_open())) {
		cout << "new2.dat file opens fails!!!" << endl;
		exit(0);
	}

	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			if (i != 0 && !isdigit(str[i - 1])) {
				outfile1 << " " << str[i];
			}
			else {
				outfile1 << str[i];
			}
		}

		if (isalpha(str[i])) {
			if (i != 0 && !isalpha(str[i - 1])) {
				outfile2 << " " << str[i];
			}
			else {
				outfile2 << str[i];
			}
		}
	}

	cout << "new1.dat file writes successfully!!!" << endl;
	cout << "new2.dat file writes successfully!!!" << endl;

	outfile1.close();
	outfile2.close();

	return 0;
}

