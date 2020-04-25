#include"default.h"
#include<fstream>
#include"String.h"

string file("STL Wiki.txt"s);

int main() {
	ifstream in{ file };
	if (!in) {
		cout << "파일 없음" << endl;
	}
	char c;
	
	while ((c=in.get())!=EOF) {
		cout.put(c);
	}
	in.close();
}