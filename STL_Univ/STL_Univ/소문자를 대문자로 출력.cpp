#include"default.h"
#include<fstream>
#include"String.h"

string file("STL Wiki.txt"s);

int main() {
	ifstream in{ file };
	if (!in) {
		cout << "파일 없음" << endl;
	}
	int c;

	while ((c = in.get()) != EOF) {
		/*
		if (isalpha(c)) // c가 문자인가?
			if (islower(c)) // c가 소문자인가?
			{
				c = toupper(c);
				//c -= 0x20; //그렇다면 대문자로 바꾼다.
			}
		//0x20 -> 32
		*/
		c = toupper(c); // 알아서 소문자를 대문자로 바꿔준다.
		cout.put(c);
	}
	in.close();
}