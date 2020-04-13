#include"default.h"
#include<vector>
#include<thread>

int main()
{
	vector<int> v; // 비어있는 벡터

	v.reserve(200);	// int 200개 공간 예약

	int capacity{ -1 };
	int i{};

	while (true) {
		v.push_back(++i); // 원소 추가
		cout << i << " ";
		this_thread::sleep_for(100ms);

		if (capacity != v.capacity()) {
			cout << endl;
			cout << "원소 수-" << v.size() << endl;
			cout << "메모리 재할당 후 담을 수 있는 원소의 갯수 -"
				<< v.capacity() << endl;
			cout << endl << endl;

			capacity = v.capacity();
			cout << "원소 추가 -";
		}
	}
}