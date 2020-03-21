#include"default.h"

void save(string str) { // save 정의

	// 내용을 읽을 파일을 연다 -> "파일입출력.cpp"
	ifstream in(str);
	//읽은 내용을 저장할 파일을 연다 -> 저장할 파일이름을 "강의저장.txt" 라고 하자
	ofstream out("강의 저장.txt", ios::app); // ios::app 덧붙여쓰기 
	//파일입출력.cpp의 모든 내용을 읽어 강의저장.txt 파일에 기록한다.
	int c;
	out << endl;
	while ((c = in.get()) != EOF)
		out << (char)c;

	cout << str << "를 강의저장.txt에 저장하였습니다." << endl;

}