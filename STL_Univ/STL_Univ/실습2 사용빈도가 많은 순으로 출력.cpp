#include"default.h"
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
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

	for (const pair<char, int>& a : alpha) {
		count += a.second;
	}
	cout << "���� ���ĺ��� ���� -" << count << endl;

	cout << "���Ƚ���� ���� ���ĺ� ��" << endl;

	vector<pair<char, int>> v;
	v.reserve(alpha.size());

	for (const auto& a : alpha)
		v.push_back(a);

	sort(v.begin(), v.end(), [](const pair<char,int>& a, const pair<char, int>& b) {
		return a.second > b.second;
		});

	count = 0;
	
	for (const auto& a : v) {
		if (count % 5 == 0 && count != 0) {
			count = 0;
			cout << endl;
		}
		cout << a.first << " - " << right << setw(5) << a.second << " ";
		++count;
	}
}