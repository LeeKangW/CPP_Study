#include"default.h"
#include<cmath>
#include<thread>

// sin ��� ȭ�鿡 ����մϴ�. - ���â�� ���� 80ĭ���� ����

int main() {
	double rad{ 2 * 3.1416 };
	int val;
	int freq;

	cout << "���ļ��� �Է��ϼ���(Hz) ��õ���� 10 - ";
	cin >> freq;

	double inc = 1. / freq;

	while (true)
	{
		val = sin(rad) * 39 + 39;
		for (int i = 0; i < val; i++)
			cout<< ' ';
		cout << '*' << endl;
		rad += inc;
		this_thread::sleep_for(33ms);
	}
}