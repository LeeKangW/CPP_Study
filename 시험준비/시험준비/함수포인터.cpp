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
		cout << "a 나 d 키를 누르세요. c를 누르면 기능을 바꿉니다.끝내려면 q를 누르세요.";
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
	cout << "점프" << endl;
}
void slide() {
	cout << "슬라이드" << endl;
}