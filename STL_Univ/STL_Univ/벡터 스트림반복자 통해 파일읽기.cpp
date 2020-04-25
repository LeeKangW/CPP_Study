#include"default.h"
#include<fstream>
#include<vector>
#include"String.h"

string file{ "STL Wiki.txt"s };

int main() {
	ifstream in(file);

	vector<char> v;
	v.reserve(2'000);

	if (!in) {
		cout << file << "ÀÌ ¾øÀ½." << endl;
	}

	int c;

	while ((c = in.get()) != EOF) {
		v.push_back(c);
	}

	for (vector<char>::reverse_iterator it = v.crbegin(); it != v.crend(); ++it)
		cout << *it;

}
