#include"default.h"
#include<fstream>
#include<vector>
#include<iterator>
#include"String.h"

string file{ "STL Wiki.txt"s };

int main() {

	ifstream in(file);

	// white space ����
	//vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };

	//white space ���� -> #include<iterator> �ʿ�

	vector<char> v{ istream_iterator<char>(in), istream_iterator<char>() };

	//��� ���� ���
	for (char c : v)
		cout << c;
}
