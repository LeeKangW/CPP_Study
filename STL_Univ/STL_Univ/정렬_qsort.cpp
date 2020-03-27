#include"default.h"
#include<fstream>
#include<iomanip>

int compareFunc(const void*, const void*);

int main() {
	ifstream in("���� 1000��.txt", ios::binary);

	int data[1'000];

	in.read((char*)&data, sizeof(int) * 1'000);
	// in.read(�о���� ���ڵ��� ������ ���� �迭, ���� �� ���� ���� ������ )

	qsort(data, 1'000, sizeof(int), compareFunc);

	// Ȯ�ο� ���
	for (int n : data)
		cout << setw(20) << left << n;
	//setw(����) : ������ŭ �� ���. ��, ���� ����

}

int compareFunc(const void* a, const void* b) {
	
	int num1 = *static_cast<const int*>(a);
	int num2 = *static_cast<const int*>(b);

	return num1 - num2;
}