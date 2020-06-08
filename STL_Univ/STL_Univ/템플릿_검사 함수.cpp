#include"default.h"
#include<string>

template<class T>
T add(T a, T b) {
	if constexpr (is_arithmetic<T>()) // T�� ��� ������ Ÿ���̴� ?
	{
		cout << typeid(T).name() << "�� ��������� �����մϴ�." << endl;
		return a + b;
	}
	else {
		cout << "���� �� ���� Ÿ�Դϴ�." << endl;
		return a;
	}
}

class Dog { };

int main() {

	// �Լ� ���ø� add�� �ۼ��϶�.
	cout << add<int>(1, 2) << endl;
	cout << add<string>("1"s, "2"s) << endl;
	cout << add<string>("a", "b") << endl;

	// cout << add("ab", "cd") << endl;	// const char* �� �Ǵ��ؼ� ���ư�. -> �����ͳ����� ���� �� ����.

	// add<Dog>(Dog(), Dog());				// �̰� �ȵ�
}
