#include"default.h"
#include<vector>
#include"String.h"

int main() {

	vector<String> v{ "일본","코로나","신규확진","700명" };

	cout << "vector v의 주소 : " << &v << endl;

	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리: " << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 개수: " << v.capacity() << endl;

	//컨테이너의 모든 원소를 순회하려면 range-based for를 사용하자
	for (const String& str : v)
		cout << str << endl;
}