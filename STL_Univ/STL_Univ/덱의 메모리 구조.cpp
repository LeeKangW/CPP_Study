#include"default.h"
#include<deque>
#include<algorithm>
#include"String.h"

class Test {
	int arr;
	
public:
	void show() const {
		cout << "실험 중 : " << this << endl;
	}
};

int main() {
	deque<Test> d;

	// deque 메모리가 연속되어 있지 않음을 확인

	for (int i = 0; i < 10; ++i)
		d.emplace_back();

	cout << "원소의 주소를 출력" << endl;
	for (auto&& test : d)
		test.show();
	cout << endl;

	cout << endl;
	cout << "앞쪽에 원소를 추가한 후 주소를 출력한다" << endl;
	d.emplace_front();

	for (int i = 0; i < d.size(); ++i)
		d[i].show();
}