#include"default.h"
#include<string>
#include<fstream>


int main() {
	string file{ "정수1000만개.data"s };

	ifstream in(file, ios::binary);
	if (!in) {
		cout << file << "을 열지 못하였습니다." << endl;
	}

	int n;

	for (int i = 0; i < 1000'0000; ++i) {
		in.read((char*)&n, sizeof(int));
		if (i % 1'0000 == 0)
			cout << i << "번째 int" << n << endl;
	}
}
