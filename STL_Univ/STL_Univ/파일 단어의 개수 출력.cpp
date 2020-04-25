#include"default.h"
#include<fstream>
#include<string>
#include<vector>

string file{ "STL Wiki.txt"s };
int main() {
	ifstream in(file);

	if (!in) {
		cout << file << "ÀÌ ¾øÀ½." << endl;
	}
	 
	int c;
	int count = 0;
	bool check = false;
	vector<char> v;
	while ((c = in.get()) != EOF) {
		if (c == ' ')
			count += 1;
	}
	cout << count;
}