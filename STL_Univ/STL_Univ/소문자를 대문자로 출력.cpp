#include"default.h"
#include<fstream>
#include"String.h"

string file("STL Wiki.txt"s);

int main() {
	ifstream in{ file };
	if (!in) {
		cout << "���� ����" << endl;
	}
	int c;

	while ((c = in.get()) != EOF) {
		/*
		if (isalpha(c)) // c�� �����ΰ�?
			if (islower(c)) // c�� �ҹ����ΰ�?
			{
				c = toupper(c);
				//c -= 0x20; //�׷��ٸ� �빮�ڷ� �ٲ۴�.
			}
		//0x20 -> 32
		*/
		c = toupper(c); // �˾Ƽ� �ҹ��ڸ� �빮�ڷ� �ٲ��ش�.
		cout.put(c);
	}
	in.close();
}