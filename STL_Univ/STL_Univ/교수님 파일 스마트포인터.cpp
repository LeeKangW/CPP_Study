#include"default.h"
#include"String.h"
#include<memory>

int main() {
	auto s = make_unique<String>("COVID-19");

	string e = "dd";

	cout << "변수 s가 저장한 내용 - " << *s << endl;
}