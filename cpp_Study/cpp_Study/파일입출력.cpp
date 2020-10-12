#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("이상한나라의앨리스.txt",ios::app);
	ofstream out("테스트.txt");

	if (!in)
	{
		cout << "파일이 존재하지 않습니다." << endl;
		return 0;
	}
	int c;

	// 띄어쓰기 까지 포함되어 있다.
	while ((c = in.get()) != EOF)
	{
		out << (char)c;
	}


	/*
	// 띄어쓰기가 미포함 되어 있다. ( 공백기준으로 한 문자열만큼 계속 불러오는 형태 )
	string str;
	while (in >> str)
	{
		cout << str << endl;
	}
	*/

	cout << "모두 저장하였습니다." << endl;
}