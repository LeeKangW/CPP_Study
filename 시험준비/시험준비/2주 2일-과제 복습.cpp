#include <iostream>
using namespace std;

template<class T,size_t size>
class Array {
private:
	T* a{ nullptr };

public:
	explicit Array(){
		a = new T[size];
	}
	Array& operator=(const Array&) = delete;
	Array(const Array&) = delete;

	int& operator[](int num) {
		return a[num];
	}
	int& operator[](int num)const {
		return a[num];
	}

};
int main()
{
	Array<int,10> a; // 정수 10개를 담을 메모리 확보
	for (int i = 0; i < 10; ++i)
		a[i] = i; // a에 쓰기
	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' '; // a에서 읽기
	cout << endl;
}