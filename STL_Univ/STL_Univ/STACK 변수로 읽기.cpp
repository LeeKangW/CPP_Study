#include"default.h"
#include<string>
#include<fstream>


int main() {
	string file{ "����1000����.data"s };

	ifstream in(file, ios::binary);
	if (!in) {
		cout << file << "�� ���� ���Ͽ����ϴ�." << endl;
	}

	int n[1000'0000];

	in.read((char*)&n, 1000'0000 * sizeof(n));

	cout << "�� ���� read �Լ�ȣ��� �д´�." << endl;
}
