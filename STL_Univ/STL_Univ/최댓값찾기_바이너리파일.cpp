#include"default.h"
#include<fstream>
#include<limits>

int main() {
	ifstream in("���� 1000��.txt", ios::binary);

	int n;
	int max{ numeric_limits<int>::min() }; // ���� ���� ������ ����

	for (int i = 0; i < 1'000; ++i) {
		in.read((char*)&n, sizeof(n));
		if (max < n)
			max = n;
	}
	
	cout << "\"���� 1000��.txt\"�� ����� int �� ���� ū ���� " << max << endl;

}