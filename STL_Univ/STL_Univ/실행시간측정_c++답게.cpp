#include"default.h"
#include<thread>
#include<chrono>

int main() {
	cout << "����" << endl;

	using namespace std::chrono;

	auto start = steady_clock::now(); // �ð� ���� ��´�.

	this_thread::sleep_for(3000ms); // 3�ʸ� ���� �ڵ�

	auto d = duration_cast<milliseconds>(steady_clock::now() - start);

	cout << d.count << "�и��ʰ� �ɸ�" << endl;
}