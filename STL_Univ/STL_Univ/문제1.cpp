#include<iostream>
#include<algorithm>
#include<fstream>
#include<random>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;

int main() {
	ifstream in("����1000����.data", ios::binary);

	vector<int> data(1000'0000);

	cout << "������ ���� ����" << endl;
	for (int i = 0; i < 1000'0000; ++i) {
		in.read((char*)&data[i], sizeof(data[i]));
	}
	cout << "������ ���� ��" << endl << endl;

	
	cout << "���� ����" << endl;
	sort(begin(data), end(data), [](int a, int b) {
		return a < b;
		});
	cout << "���� ��" << endl << endl;

	ofstream out("����1000��������.data",ios::binary);
	cout << "���� �� ���� ����" << endl;
	for (int n : data) {
		out.write((char*)&n, sizeof(n));
	}
	cout << "���� �� ���� �Ϸ�" << endl;

	//for (int n : data)
	//	cout << setw(20) << left << n;
}