#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

int main() {
	cout << "����" << endl;
	
	using namespace chrono;
	auto start = steady_clock::now();

	this_thread::sleep_for(3s);

	auto d = duration_cast<milliseconds>(steady_clock::now() - start);

	cout << d.count() << "�и��� �ɸ�." << endl;
	cout << "3�ʰ� ����" << endl;
}