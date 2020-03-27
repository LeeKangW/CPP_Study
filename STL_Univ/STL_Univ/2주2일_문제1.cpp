#include"default.h"

template<typename T>
class Array {
private:
	T num;
	T* data{ nullptr };
public:
	explicit Array(int n) :num{ n }, data{ new T[num] }{}
	~Array() { delete[] data; }
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	T& operator[](int idx) {
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