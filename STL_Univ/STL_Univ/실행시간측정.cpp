#include"default.h"
#include<thread>
#include<chrono>

int main() {

	cout << "����" << endl;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	// �ð� ���� ��´�.

	this_thread::sleep_for(3s);

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	// �ð� ���� �ٽ� ��´�.

	chrono::duration<double> duration = end - start;  // �ð� ������ ���.
	chrono::duration<double> d = chrono::duration_cast<chrono::seconds>(duration);
	// ǥ���ϰ� ���� ������ ������ ��ȯ�Ѵ�.

	cout << d.count() << "�ʰ� �ɸ�" << endl;

	cout << "3�ʰ� ����" << endl;
}