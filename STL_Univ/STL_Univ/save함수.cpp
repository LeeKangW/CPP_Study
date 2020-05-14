#include"save.h"


void save(string_view str) { // save 정의

	size_t size = filesystem::file_size(str);

	unique_ptr<char[]>p{ new char[size] };
	
	ifstream in(str);

	in.read(p.get(), size);

	ofstream out("강의 저장.txt", ios::binary | ios::app);

	auto tp = chrono::system_clock::now();
	auto ct = chrono::system_clock::to_time_t(tp);
	auto lt = localtime(&ct);

	out.imbue(locale("korean"));

	out << put_time(lt, "%c - (%A)") << endl;

	out.write(p.get(), size);

#pragma region  원래 방법
	/*
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
	*/
#pragma endregion

	

}