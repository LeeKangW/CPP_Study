#include"default.h"
#include<string>

int main() {
	int num = 0B0111'1111'1111'1111'1111'1111'1111'1111;

	cout << "num�� �޸� ũ��� " << sizeof(num) << "����Ʈ" << endl;
	cout << "num�� ����� ���� " << num << endl;

	string s{ to_string(num) };

	cout << "num�� ���ڷ� �����Ϸ��� " << size(s) << "����Ʈ�� �ʿ��մϴ�." << endl;
	
}