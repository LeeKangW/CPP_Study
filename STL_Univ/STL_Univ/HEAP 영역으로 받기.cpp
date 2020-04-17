#include"default.h"
#include<fstream>
#include<string>

//파일에서 1000'0000개의 int를 HEAP 여역에 확보한 메모리로 읽는다.
int main() {

	string file{ "정수1000만개.data" };

	ifstream in(file, ios::binary);

	if (!in)
		cout << file << "을 열지 못하였습니다." << endl;

	int* p = { new int[1000'0000] };

	in.read((char*)p, 1000'0000 * sizeof(int));

	// 데이터를 원하는대로 사용한다.


	cout << p[0] << endl;
	cout << p[1000'0000 - 1] << endl;

	delete[] p; // 사용 후 반납.
}