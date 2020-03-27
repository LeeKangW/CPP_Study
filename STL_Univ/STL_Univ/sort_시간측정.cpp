#include<iostream>
#include<chrono>
#include<algorithm>
#include<random>

using namespace std;

int main() {

	default_random_engine dre;
	uniform_int_distribution<> uid;

	int data[10'0000];

	for (int& d : data)
		d = uid(dre);

	auto start = chrono::steady_clock::now();

	sort(begin(data), end(data));

	auto d = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);

	cout << d.count() << "밀리초가 걸림" << endl;

	// 정렬되었나 확인
	
	cout << data[0] << "---" << data[10'0000 - 1] << endl;

}