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
		* mutex를 통해 특정 한 스레드가 해당 작업을 진행할 수 있도록 함.
		* 그렇게 함으로서, 여러 스레드가 같은 것을 더하면서 서로 다른 결과를 도출하는 오류를 제거... ( T1이 +1을 하는 도중에 T2가 +1을 하면, count는 실질적으로 +1만 됨 )
		*/
		lock_guard<mutex> lock(m); // 이러면 m.lock을 해주고 lock이 끝날 때 스스로 unlock 처리를 해줘 데드락 상태에 빠지는 걸 방지해준다.
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