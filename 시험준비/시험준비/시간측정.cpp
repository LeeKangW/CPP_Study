#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

int main() {
	cout << "시작" << endl;
	
	using namespace chrono;
	auto start = steady_clock::now();

	this_thread::sleep_for(3s);

	auto d = duration_cast<milliseconds>(steady_clock::now() - start);

	cout << d.count() << "밀리초 걸림." << endl;
	cout << "3초가 끝남" << endl;
}