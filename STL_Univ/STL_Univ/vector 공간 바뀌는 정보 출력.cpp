#include"default.h"
#include<vector>
#include<thread>

int main()
{
	vector<int> v; // ����ִ� ����

	v.reserve(200);	// int 200�� ���� ����

	int capacity{ -1 };
	int i{};

	while (true) {
		v.push_back(++i); // ���� �߰�
		cout << i << " ";
		this_thread::sleep_for(100ms);

		if (capacity != v.capacity()) {
			cout << endl;
			cout << "���� ��-" << v.size() << endl;
			cout << "�޸� ���Ҵ� �� ���� �� �ִ� ������ ���� -"
				<< v.capacity() << endl;
			cout << endl << endl;

			capacity = v.capacity();
			cout << "���� �߰� -";
		}
	}
}