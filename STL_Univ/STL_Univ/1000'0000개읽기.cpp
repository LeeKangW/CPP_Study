#include"default.h"
#include<string>
#include<fstream>


int main() {
	string file{ "����1000����.data"s };

	ifstream in(file, ios::binary);
	if (!in) {
		cout << file << "�� ���� ���Ͽ����ϴ�." << endl;
	}

	int n;

	for (int i = 0; i < 1000'0000; ++i) {
		in.read((char*)&n, sizeof(int));
		if (i % 1'0000 == 0)
			cout << i << "��° int" << n << endl;
	}
}
