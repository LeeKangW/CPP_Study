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
	int ch;
	string s;
	vector<string> v;

	while ((ch = in.get()) != EOF) {
		if (ch != ' ' && ch != '\n') {
			s.push_back(ch);
		}
		else if (ch == ' ') {
			v.push_back(s);
			s.clear();
		}
	}

	sort(v.begin(), v.end(), [](string a, string b) {
		return a.size() < b.size();
		});
	
	for (auto chr : v)
		cout << chr<<' ';
}