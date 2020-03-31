#include"default.h"
#include<fstream>
#include<string>

int n[1000'0000];

int main() {
	string file{ "정수1000만개.data"s };

	ifstream in(file, ios::binary);
	if (!in) {
		cout << file << "을 열지 못하였습니다." << endl;
	}

	in.read((char*)&n, 1000'0000 * sizeof(n));

	cout << n[0] << endl;
	cout << n[1000'0000 -1 ] << endl;
}