#include"default.h"
#include<deque>
#include<algorithm>
#include"String.h"

class Test {
	int arr;
	
public:
	void show() const {
		cout << "���� �� : " << this << endl;
	}
};

int main() {
	deque<Test> d;

	// deque �޸𸮰� ���ӵǾ� ���� ������ Ȯ��

	for (int i = 0; i < 10; ++i)
		d.emplace_back();

	cout << "������ �ּҸ� ���" << endl;
	for (auto&& test : d)
		test.show();
	cout << endl;

	cout << endl;
	cout << "���ʿ� ���Ҹ� �߰��� �� �ּҸ� ����Ѵ�" << endl;
	d.emplace_front();

	for (int i = 0; i < d.size(); ++i)
		d[i].show();
}