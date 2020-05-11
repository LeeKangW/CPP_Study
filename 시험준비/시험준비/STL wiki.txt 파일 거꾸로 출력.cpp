#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

string file{ "STL Wiki.txt" };

int main() {
	ifstream in(file);

	if (!in)
		cout << "¾øÀ½" << endl;

	vector<char> v;
	v.reserve(1'000);

	int c;
	while ((c = in.get()) != EOF) {
		v.push_back(c);
	}

	for (auto i = v.crbegin(); i != v.crend(); ++i)
		cout << *i;
}