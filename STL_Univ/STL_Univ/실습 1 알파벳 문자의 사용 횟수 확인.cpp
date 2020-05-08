#include"default.h"
#include<string>
#include<fstream>
#include<map>
#include <iomanip>

int main() {
	cout << "���� ���� - ";
	string file;
	cin >> file;
	ifstream in(file);

	if (!in) {
		cout << file << "�� ����." << endl;
	}
	map<char, int> alpha;
	char str;
	while (in >> str) {
		if (isalpha(str)) {
			str = tolower(str);
			alpha[str]++;
		}
	}
	cout << "���� ���ĺ��� ���� - " << alpha.size() << endl;


	int count = 0;

	for (const pair<char,int>& a : alpha) {
		count += a.second;
	}
	cout << "���� ���ĺ��� ���� -" << count<<endl;

	cout << "�� ���ĺ��� ���Ƚ��" << endl;

	count = 0;
	for (const auto& a : alpha) {
		if (count % 5 == 0 && count != 0) {
			cout << endl;
			count = 0;
		}
		cout << a.first << " - " << right << setw(5) << a.second<<"  ";
		++count;
	}
	
}