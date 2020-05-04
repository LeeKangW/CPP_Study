#include"default.h"
#include<map>

int main() {
	map<string, string> phonebook;

	phonebook["번호안내"] = "114";
	//phonebook.operator[]("번호안내")="114";

	phonebook["일기예보"] = "131";
	phonebook["교통정보"] = "1333";
	phonebook["전기고장신고"] = "123";
	phonebook["사이버테러"] = "118";

	for (const auto& [name, number] : phonebook)
		cout << name << ": " << number << endl;

}