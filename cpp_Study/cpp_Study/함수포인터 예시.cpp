#include<iostream>

using namespace std;

void jump()
{
	cout << "����" << endl;
}
void slide()
{
	cout << "�����̵�" << endl;
}

void(*func1)() = jump;
void(*func2)() = slide;

int main()
{
	char key;

	bool flag{ false };
	
	/**
	* �Լ�������
	* 
	while (true)
	{
		cout << "a�� dŰ�� ��������. �����ȯ�� cŰ, �������� qŰ�� ��������: ";

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

	/** �������� �Լ�������	*/
	auto callableType = []() { cout << "����" << endl; };

	callableType();
}