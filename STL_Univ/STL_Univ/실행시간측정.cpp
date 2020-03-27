#include"default.h"
#include<thread>
#include<chrono>

int main() {

	cout << "시작" << endl;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	// 시간 값을 얻는다.

	this_thread::sleep_for(3s);

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	// 시간 값을 다시 얻는다.

	chrono::duration<double> duration = end - start;  // 시간 간격을 잰다.
	chrono::duration<double> d = chrono::duration_cast<chrono::seconds>(duration);
	// 표현하고 싶은 단위로 간격을 변환한다.

	cout << d.count() << "초가 걸림" << endl;

	cout << "3초가 지남" << endl;
}