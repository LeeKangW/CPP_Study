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
	Array<int,10> a; // ���� 10���� ���� �޸� Ȯ��
	for (int i = 0; i < 10; ++i)
		a[i] = i; // a�� ����
	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' '; // a���� �б�
	cout << endl;
}