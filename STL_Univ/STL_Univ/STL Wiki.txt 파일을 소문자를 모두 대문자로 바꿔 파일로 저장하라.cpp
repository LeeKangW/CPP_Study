#include"default.h"
#include"String.h"
#include<string>
#include<fstream>


string file{ "STL Wiki.txt"s };
string out_file{ "STL Wiki 대문자.txt"s };

int main() {
	ifstream in(file);

	if (!in) {
		cout << file << "파일 열기 실패" << endl;
		return 0;
	}
	ofstream out(out_file);
	int c;

	while ((c = in.get()) != EOF) {
		c = toupper(c);
		out.put(c);	//out에 출력
	}
}