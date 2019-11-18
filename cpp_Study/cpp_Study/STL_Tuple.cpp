#include<iostream>
#include<tuple>

using namespace std;

// 함수로도 사용이 가능하다.
tuple<int, string> getName() { 
	int age;
	string Name;
	cout << "나이 입력 : ";
	cin >> age;

	cout << "이름을 입력 : ";
	cin >> Name;

	return make_tuple(age, Name);

}

int main() {
	tuple<int, int, int> t1 = make_tuple(10, 20, 30);

	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << get<2>(t1) << endl;

	cout << endl;

	tuple<int, string> SetName;
	SetName = getName();
	cout << "이름 : " << get<1>(SetName) << endl;
	cout << "나이 : " << get<0>(SetName) << endl;
}