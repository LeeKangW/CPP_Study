#include"default.h"
#include"String.h"
#include<memory>

int main() {
	auto s = make_unique<String>("COVID-19");

	string e = "dd";

	cout << "���� s�� ������ ���� - " << *s << endl;
}