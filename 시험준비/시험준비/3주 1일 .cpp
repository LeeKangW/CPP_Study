#include<iostream>
#include<fstream>
#include<string>
#include<random>

using namespace std;

int main() {

	default_random_engine dre;
	uniform_int_distribution<> uid;

	

	ifstream in("����100����.data"s, ios::binary);

	int* n{ new int[1000'0000] };

	in.read((char*)n, sizeof(int) * 1000'0000);

	for (int i = 0; i < 1000'0000; ++i) {
		cout << n[i] << endl;
	}
	delete[] n;
	/*
	ofstream out("����100����.data"s, ios::binary);

	for (int i = 0; i < 1000'0000; ++i) {
		n = uid(dre);
		out.write((char*)&n, sizeof(int));
	}
	*/
}