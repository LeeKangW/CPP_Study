#include"default.h"

void jump();
void slide();
void(*func1)() = jump;
void(*func2)() = slide;

int main() {
	char key;
	bool flag{ false };

	while (true) {
		cout << "a나 d 키를 누르세요 기능전환은 c, 끝내려면 q를 누르세요: ";
		cin >> key;

		switch (key)
		{
		case 'a':
		case 'A':
			func1();
			break;
		case'd':
		case'D':
			func2();
			break;
		case 'c':
		case 'C':
		{
			auto temp{ func1 };
			func1 = func2;
			func2 = temp;
		}
		break;
		case 'q':
		case 'Q':
			flag = true;
			break;
		default:
			break;
		}
		if (flag == true)
			break;
	}
}

void jump() {
	cout << "점프" << endl;
}
void slide() {
	cout << "슬라이드" << endl;
}