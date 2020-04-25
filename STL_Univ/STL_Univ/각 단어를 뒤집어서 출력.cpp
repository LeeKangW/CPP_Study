#include"default.h"
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


string file{ "STL Wiki.txt"s };

int main() {
	ifstream in(file);
	if (!in) {
		cout << file << "ÀÌ ¾øÀ½." << endl;
	}

	int c;
	string s;
	vector<string> v;
	v.reserve(2'000);

	while ((c = in.get()) != EOF) {
		if (c != ' ') {
			s += c;
		}
		else {
			v.push_back(s);
			v.push_back(" ");
			s.clear();
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		reverse(v[i].begin(), v[i].end());
	}
	for (auto i : v)
		cout << i;

}