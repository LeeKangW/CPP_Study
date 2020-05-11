#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string file{ "STL Wiki.txt" };

int main() {
	ifstream in(file);

	if (!in)
		cout << "¾øÀ½" << endl;

	vector<string> v;
	v.reserve(1'000);

	int c;
	string str;
	while ((c = in.get()) != EOF) {
		if (c == ' ') {
			str += " ";
			v.emplace_back(str);
			str.clear();
		}
		else if (c == '\n') {
			v.emplace_back("\n");
			str.clear();
		}
		else
			str += (char)c;

	}

	for (string& s : v) {
		reverse(s.begin(), --s.end());
		cout << s;
	}
	
}