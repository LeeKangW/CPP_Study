#include"default.h"
#include<fstream>
#include<iomanip>
#include<algorithm>


int main() {
	ifstream in("���� 1000��.txt", ios::binary);

	int data[1'000];

	in.read((char*)&data, sizeof(int) * 1'000);
	// in.read(�о���� ���ڵ��� ������ ���� �迭, ���� �� ���� ���� ������ )

	sort(begin(data), end(data), [](int a, int b) {
		return a < b;
		});
	// Ȯ�ο� ���
	for (int n : data)
		cout << setw(20) << left << n;
	//setw(����) : ������ŭ �� ���. ��, ���� ����

}
