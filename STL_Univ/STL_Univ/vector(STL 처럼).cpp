#include"default.h"
#include<string>
#include<vector>
#include<iterator>
#include <algorithm>

int main() {
	cout << "�ܾ ������ �Է��ϼ���. �����÷��� Ctrl-z�� �Է��ϼ���" << endl;

	vector<string> v{ istream_iterator<string>(cin),istream_iterator<string>() };

	sort(begin(v), end(v));
	copy(begin(v), end(v), ostream_iterator<string>(cout, "\t"));
}