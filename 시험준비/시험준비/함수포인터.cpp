#include<iostream>
using namespace std;

void jump();
void slide();

void (*f1)() = jump;
void (*f2)() = slide;

int main() {
	char key;

	bool flag{ false };
	
	while (true) {
		cout << "a �� d Ű�� ��������. c�� ������ ����� �ٲߴϴ�.�������� q�� ��������.";
		cin >> key;
		
		switch (key) {
		case 'a':
		case 'A':
			f1();
			break;
		case 'd':
		case 'D':
			f2();
			break;
		case 'q':
		case 'Q':
			flag = true;
			break;
		case 'c':
		case 'C':
			f1 = slide;
			f2 = jump;
			break;
		default:
			break;
		}
		if (flag) {
			break;
		}
	}
}
void jump() {
	cout << "����" << endl;
}
void slide() {
	cout << "�����̵�" << endl;
}