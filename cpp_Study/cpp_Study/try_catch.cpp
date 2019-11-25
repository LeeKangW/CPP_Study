#include<iostream>
#define function 1

/*
	try - try ���ο��� ���ܰ� �ִ��� Ž���� �ϴ� �κ�
	throw - try���� ���ܸ� Ž���ϸ� throw�� ���ڷ� �� ������ catch�� �����ϴ�.
	catch - throw���� ���� ������ ���ڷ� �޾Ƽ� catch ���ο� ���α׷��Ӱ� ������ ����ó���� �ǽ��մϴ�.
*/
using namespace std;

#pragma region  ���ι��� ( function == 0) �Լ��� ���� ( function == 1) ��� ����
#if function == 0


int main() {
	cout << "���ι��� ��� " << endl;
	int a, b;
	try {
		cin >> a;
		cin >> b;

		if (b <= 0) {
			// ���� �߻���,
			throw b; //throw�� ���� ���� b�� catch�� �Ķ���ͷ� ����.
		}
		cout << "[work]" << endl;
		cout << "a:" << a << ", b:" << b << endl;
		cout << "a/b: " << a / b << endl;
	}
	catch (int expn) { // throw���� ���� b ���ڸ� expn���� �޴´�.
		cout << "[error]" << endl;
		cout << "can't use this :" << expn << endl;
	}

	return 0;
}

#elif function == 1

int divide(int a, int b) {
	if (b == 0) {
		throw b;
	}
	return a / b;
}

int main() {
	cout << "�Լ� ��� " << endl;
	int a, b;
	try {
		cin >> a;
		cin >> b;

		cout << "a/b : "<<divide(a, b) << endl;
	}
	catch (int ex) {
		cout << "[error]" << endl;
		cout << "Can't use : " << ex << endl;
	}
}


#endif
#pragma endregion