#include"default.h"
#include<fstream>
#include<iomanip>


int main() {
	ifstream in("���� 1000��.txt", ios::binary);

	int data[1'000];

	in.read((char*)&data, sizeof(int) * 1'000);
	// in.read(�о���� ���ڵ��� ������ ���� �迭, ���� �� ���� ���� ������ )

	qsort(data, 1'000, sizeof(int), 
		[](const void* a, const void* b) {
			return *(static_cast<int const*>(a)) - *(static_cast<int const*>(b));
		});

	// Ȯ�ο� ���
	for (int n : data)
		cout << setw(20) << left << n;
	//setw(����) : ������ŭ �� ���. ��, ���� ����

}
