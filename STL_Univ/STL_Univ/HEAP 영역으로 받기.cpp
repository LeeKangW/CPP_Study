#include"default.h"
#include<fstream>
#include<string>

//���Ͽ��� 1000'0000���� int�� HEAP ������ Ȯ���� �޸𸮷� �д´�.
int main() {

	string file{ "����1000����.data" };

	ifstream in(file, ios::binary);

	if (!in)
		cout << file << "�� ���� ���Ͽ����ϴ�." << endl;

	int* p = { new int[1000'0000] };

	in.read((char*)p, 1000'0000 * sizeof(int));

	// �����͸� ���ϴ´�� ����Ѵ�.


	cout << p[0] << endl;
	cout << p[1000'0000 - 1] << endl;

	delete[] p; // ��� �� �ݳ�.
}