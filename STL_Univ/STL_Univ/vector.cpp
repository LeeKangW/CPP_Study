#include"default.h"
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>


int main() {
	vector<string> v;

	string s;

	cout << " �ܾ ������ �Է��ϼ���. �����÷��� Ctrl-z�� �Է��ϼ���." << endl;

	while (cin >> s) {
		v.push_back(s);
	}

	cout << "�Է��� �������ϴ�." << endl;

	sort(v.begin(), v.end());

	cout << "���� ����� ����մϴ�." << endl;

	for (auto&& s : v)
		cout << s << '\t';
	cout << endl;

}