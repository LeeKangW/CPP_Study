#include"default.h"
#include"String.h"
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

string file{ "STL Wiki.txt"s };
string out_file{ "STL Wiki 단어 역순.txt"s };

int main() {
	ifstream in(file);

	if (!in) {
		cout << file << "이 없음." << endl;
	}
	int c;
	ofstream out(out_file);

	string s{};
	vector<string> v;
	v.reserve(2'000);

	while ((c = in.get()) != EOF) {
		if (c != ' ' && c != '\n') {
			s.push_back(c);
		}
		else if (c == ' ') {
			if (s.size() != 0)
				v.push_back(s);
			v.push_back(" ");
			s.clear();
		}
		else {
			if(s.size() != 0)
				v.push_back(s);
			v.push_back("\n");
			s.clear();

		}
	}
	
	for (int i = 0; i < v.size(); ++i) {
		reverse(v[i].begin(), v[i].end());
	}

	for (auto i : v) {
		cout << i;
		out << i;
	}
}