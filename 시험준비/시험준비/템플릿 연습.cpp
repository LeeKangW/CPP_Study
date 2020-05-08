#include<iostream>
using namespace std;

class IntArry {
private:
	size_t length = 0;
	int* a{ nullptr };
public:
	explicit IntArry(int num) :length(num) {
		a = new int[num];
	}
	~IntArry() {
		delete[] a;
	}
	IntArry(const IntArry&) = delete;
	IntArry& operator=(const IntArry&) = delete;

	int& operator[](int num) {
		return a[num];
	}

	int& operator[](int num) const {
		return a[num];
	}

};

int main() {
	IntArry a(10); // 정수 10개를 담을 메모리 확보

	for (int i = 0; i < 10; ++i)
		a[i] = i;

	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' ';

	cout << endl;
}