#include"default.h"

template<typename Iter>
class Array {
private:
	Iter num;
	Iter* data{ nullptr };
public:
	explicit Array(int n) :num{ n }, data{ new Iter[num] }{}
	~Array() { delete[] data; }
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	Iter& operator[](int idx) {
		return data[idx];
	}

};

int main() {
	Array<int> a(10);

	for (int i = 0; i < 10; ++i)
		a[i] = i;

	for (int i = 0; i < 10; ++i) {
		cout << a[i] << ' ';
		cout << endl;
	}
}