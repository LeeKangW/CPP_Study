#include"default.h"
#include<cmath>
#include<thread>

// sin 곡선을 화면에 출력합니다. - 출력창을 가로 80칸으로 설정

int main() {
	double rad{ 2 * 3.1416 };
	int val;
	int freq;

	cout << "주파수를 입력하세요(Hz) 추천값은 10 - ";
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