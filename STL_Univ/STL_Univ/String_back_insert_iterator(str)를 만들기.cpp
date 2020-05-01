#include"default.h"
#include"String.h"
#include<algorithm>
#include<string>

template<class Initer,class Outiter>
Outiter my_copy(Initer, Initer, Outiter);

String::iterator String_back_insert_iterator(String);

int main() {
	string s{ "The quick brown fox jumps over the lazy dog" };

	String str;

	my_copy(s.begin(), s.end(), String_back_insert_iterator(str));
	cout << str << endl;  //str에는 s의 원소들이 복사되어야 한다.
}

template<class Initer, class Outiter>
Outiter my_copy(Initer first, Initer last, Outiter result) {

	while (first != last) {
		*result = *first;
		++result;
		++first;
	}
	return result;
}


String::iterator String_back_insert_iterator(String str) {

	return str.begin();
}