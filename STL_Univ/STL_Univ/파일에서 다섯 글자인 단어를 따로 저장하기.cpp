#include"default.h"
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


string file{ "STL Wiki.txt"s };
string out_file{ "STL Wiki���� 5���ڷ� �� �ܾ�.txt"s };

int main() {
	ifstream in(file);
	ofstream out(out_file);
	if (!in) {
		cout << file << "ã�� �� ����." << endl;
	}

	int c;
	string s;
	vector<string> v;
	v.reserve(2'000);

	while ((c = in.get()) != EOF) {
		if (c != ' ' && c != '\n') {
			s.push_back(c);
		}
		else if (c == ' ') {
			v.push_back(s);
			s.clear();
		}
	}

	for (auto i : v) {
		if (i.size() == 5) {
			cout << i<<' ';
			out << i << ' ';
		}
	}
}