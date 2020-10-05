#include<iostream>

using namespace std;

void jump()
{
	cout << "점프" << endl;
}
void slide()
{
	cout << "슬라이드" << endl;
}

void(*func1)() = jump;
void(*func2)() = slide;

int main()
{
	char key;

	bool flag{ false };
	
	/**
	* 함수포인터
	* 
	while (true)
	{
		cout << "a나 d키를 누르세요. 기능전환은 c키, 끝내려면 q키를 누르세요: ";

		cin >> key;

		switch (key)
		{
		case 'a':
		case 'A':
			func1();
			break;

		case 'd':
		case 'D':
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
	*/

	/** 람다형태 함수포인터	*/
	auto callableType = []() { cout << "람다" << endl; };

	callableType();
}