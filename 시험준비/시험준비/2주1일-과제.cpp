#include<iostream>
#include<random>
#include<fstream>

using namespace std;

int main() {
	/*
	default_random_engine dre;
	uniform_int_distribution<int> uid;

	ofstream out("정수 1000만개.txt",ios::binary);

	int n;

	for (int i = 0; i < 1000'0000; ++i) {
		n = uid(dre);
		out.write((char*)&n, sizeof(n));
	}
	*/
	ifstream in("정수 1000만개.txt", ios::binary);

	int n = 0;
	vector<int> v;
	v.reserve(1000'0000);

	for (int i = 0; i < 1000'0000; ++i) {
		in.read((char*)&n, sizeof(n));
		v.push_back(n);
	}
	
	sort(v.begin(), v.end(), [](const int& a,const int& b) {
		return a < b;
		});
	
	for (const auto& i : v)
		cout << i << endl;
}