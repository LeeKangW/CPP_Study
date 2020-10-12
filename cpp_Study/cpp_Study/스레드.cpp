#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

void Add(int& count,mutex& m)
{
	for (int i = 0; i < 10000; i++)
	{
		/**
		* mutex�� ���� Ư�� �� �����尡 �ش� �۾��� ������ �� �ֵ��� ��.
		* �׷��� �����μ�, ���� �����尡 ���� ���� ���ϸ鼭 ���� �ٸ� ����� �����ϴ� ������ ����... ( T1�� +1�� �ϴ� ���߿� T2�� +1�� �ϸ�, count�� ���������� +1�� �� )
		*/
		lock_guard<mutex> lock(m); // �̷��� m.lock�� ���ְ� lock�� ���� �� ������ unlock ó���� ���� ����� ���¿� ������ �� �������ش�.
		count += 1;
	}
}
int main()
{
	int count = 0;
	mutex m;
	vector<thread> v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(thread(Add, ref(count),ref(m)));
	}
	for (int i = 0; i < v.size(); ++i)
	{
		v[i].join();
	}

	cout << count << endl;
	
}