#include"default.h"
#include<string>
#include<fstream>
#include<map>
#include <iomanip>

int main() {
	cout << "읽은 파일 - ";
	string file;
	cin >> file;
	ifstream in(file);

	if (!in) {
		cout << file << "이 없음." << endl;
	}
	map<char, int> alpha;
	char str;
	while (in >> str) {
		if (isalpha(str)) {
			str = tolower(str);
			alpha[str]++;
		}
	}
	cout << "사용된 알파벳의 종류 - " << alpha.size() << endl;


	int count = 0;

	for (const pair<char,int>& a : alpha) {
		count += a.second;
	}
	cout << "사용된 알파벳의 개수 -" << count<<endl;

	cout << "각 알파벳의 사용횟수" << endl;

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