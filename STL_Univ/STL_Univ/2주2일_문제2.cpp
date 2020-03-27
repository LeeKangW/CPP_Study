#include"default.h"
#include<string>

template<typename T,int length>
class Array {
private:
	T* data{ nullptr };
public:
	explicit Array() :data{ new T[length] }{}
	~Array() { delete[] data; }
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	T& operator[](int idx) {
		return data[idx];
	}

};

int main() {
	Array<string, 10> a;

	for (int i = 0; i < 10; ++i)
		a[i] = "string"s + to_string(i); // a 에 쓰기

	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl; // a에 쓰기
}