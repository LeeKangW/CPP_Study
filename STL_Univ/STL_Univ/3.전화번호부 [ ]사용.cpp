#include"default.h"
#include<map>

int main() {
	map<string, string> phonebook;

	phonebook["��ȣ�ȳ�"] = "114";
	//phonebook.operator[]("��ȣ�ȳ�")="114";

	phonebook["�ϱ⿹��"] = "131";
	phonebook["��������"] = "1333";
	phonebook["�������Ű�"] = "123";
	phonebook["���̹��׷�"] = "118";

	for (const auto& [name, number] : phonebook)
		cout << name << ": " << number << endl;

}