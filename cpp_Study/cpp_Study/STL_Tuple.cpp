#include<iostream>
#include<tuple>

using namespace std;

// �Լ��ε� ����� �����ϴ�.
tuple<int, string> getName() { 
	int age;
	string Name;
	cout << "���� �Է� : ";
	cin >> age;

	cout << "�̸��� �Է� : ";
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
	cout << "�̸� : " << get<1>(SetName) << endl;
	cout << "���� : " << get<0>(SetName) << endl;
}