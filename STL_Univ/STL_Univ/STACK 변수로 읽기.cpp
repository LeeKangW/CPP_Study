#include"default.h"
#include<string>
#include<fstream>


int main() {
	string file{ "정수1000만개.data"s };

	ifstream in(file, ios::binary);
	if (!in) {
		cout << file << "을 열지 못하였습니다." << endl;
	}

	int n[1000'0000];

	in.read((char*)&n, 1000'0000 * sizeof(n));

	cout << "한 번의 read 함수호출로 읽는다." << endl;
}
