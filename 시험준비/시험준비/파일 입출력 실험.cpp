#include<iostream>
#include<fstream>
#include<string>
#include<random>
using namespace std;

#define save
#undef save

int main() {

	string file("����2.txt");
#ifdef save
	ofstream out(file,ios::binary);

	

	int n = 0;

	for (int i = 0; i < 100; ++i) {
		n = i;
		out.write((char*)&n, sizeof(int));
	}
	cout << "���� ���� �Ϸ�" << endl;
#else
	ifstream in(file, ios::binary);

	if (!in) {
		cout << file << " �� ����." << endl;
		return 0;
	}
	int n = 0;
	for (int i = 0; i < 100; ++i) {
		in.read((char*)&n, sizeof(int));
		cout << n << endl;
	}

#endif // save 1

	

}