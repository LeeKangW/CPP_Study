#include <iostream>
#include <vector>
#include<algorithm>
#include"String.h"
using namespace std;
int main()
{
	
	vector<String> v;
	v.reserve(4);
	v.emplace_back("일본");
	v.emplace_back("코로나");
	v.emplace_back("신규확진");
	v.emplace_back("700명");

	int n{};
	cout << "STACK 주소:" << &n << endl;
	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리: " << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;

	cout << "오름차순으로 정렬합니다" << endl;
	sort(v.begin(), v.end(), [](String a, String b) {
		return a.getString() < b.getString();
		});
	cout << "오름차순으로 정렬한 결과입니다" << endl;

	// 컨테이너의 모든 원소를 순회하려면 range-based for를 사용하자
	for (const String& str : v)
		cout << str << endl;
}