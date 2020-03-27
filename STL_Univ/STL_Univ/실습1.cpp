#include"default.h"


class IntArray {
private:
	size_t num;
	int* data{ nullptr };

public:
	explicit IntArray(size_t n) :num{ n }, data{ new int[num] }{}
	~IntArray() {
		delete[] data;
	}

	IntArray(const IntArray&) = delete;
	IntArray& operator=(const IntArray&) = delete;

	int operator[](int idx) const {
		return data[idx];
	}

	int& operator[](int idx) {
		return data[idx];
	}
	
};
int main() {
	IntArray a(10); // 정수 10개를 담은 메모리 확보

	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << ' ';
		cout << endl;
	}
}