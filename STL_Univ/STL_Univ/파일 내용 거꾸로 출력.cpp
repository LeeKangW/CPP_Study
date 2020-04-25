#include"default.h"
#include<fstream>
#include<vector>
#include<iterator>
#include"String.h"

string file{ "STL Wiki.txt"s };

int main() {

	ifstream in(file);

	// white space 포함
	//vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };

	//white space 제거 -> #include<iterator> 필요

	vector<char> v{ istream_iterator<char>(in), istream_iterator<char>() };

	//모든 원소 출력
	for (char c : v)
		cout << c;
}
