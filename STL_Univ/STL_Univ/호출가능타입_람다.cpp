#include"default.h"

int main() {

	auto callableType = []() {
		cout << "�ȳ�? �� ���ٶ�� ��!" << endl;
	};

	// ȣ�� ���� Ÿ���� ()�� ���� �� �ִ�.
	callableType();

	cout << typeid(callableType).name() << endl;

	/*

	�̷��� �ϸ� ȣ���� ���� ����.
	-> ȣ�Ⱑ�� Ÿ���� ���ٸ� ȣ������ �ʾұ� ����.

	[]() {
		cout << "�ȳ�? �� ���ٶ�� ��!" << endl;
	};
	*/
}