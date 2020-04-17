#include"default.h"
#include<vector>

int main() {
	vector<int> v{ 1,2,3,4 };
	
	cout << "vector v의 주소 :" << &v << endl;

	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리:" << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수:" << v.capacity() << endl;

	// 777을 추가합니다.
	v.push_back(777);

	cout << endl << "---------원소 추가 후 ----" << endl;

	cout << "vector v의 주소 :" << &v << endl;

	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리:" << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수:" << v.capacity() << endl;

}