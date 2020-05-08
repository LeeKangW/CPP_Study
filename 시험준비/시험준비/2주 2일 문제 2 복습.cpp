#include<iostream>
#include<string>
using namespace std;

template<class T,size_t size>
class Array {
private:
	T* arr{ nullptr };
public:
	explicit Array() {
		arr = new T[size];
		}	
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	T& operator[](int num) {
		return arr[num];
	}
	T& operator[](int num) const{
		return arr[num];
	}
};
int main() {

	Array<string, 10> a;

	for (int i = 0; i < 10; ++i)
		a[i] = "string"s + to_string(i); // a에 쓰기
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl; // a에서 읽기

}