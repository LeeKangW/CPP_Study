#include"default.h"
#include<thread>
#include<chrono>

int main() {
	cout << "시작" << endl;

	using namespace std::chrono;

	auto start = steady_clock::now(); // 시간 값을 얻는다.

	this_thread::sleep_for(3000ms); // 3초를 쉬는 코드

	auto d = duration_cast<milliseconds>(steady_clock::now() - start);

	cout << d.count << "밀리초가 걸림" << endl;
}