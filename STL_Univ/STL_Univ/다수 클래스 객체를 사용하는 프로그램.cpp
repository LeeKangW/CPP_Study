#include"default.h"
#include<string>
#include<random>
#include<fstream>

int gid{};

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

class Dog {
private:
	string Name;	// 이름 - 15글자까지만 허용
	int age;		// 나이
	int id;			// 생성 시 결정되는 고유의 숫자로 된 id

public:
	Dog() :id(++gid) {
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			Name += uidName(dre);
			age = uidAge(dre);
		}
	}
	Dog(string _Name, int _age) :Name{ _Name }, age{ _age }, id{ ++gid }{}

	friend ostream& operator<<(ostream& os, const Dog& dog);
	
};
ostream& operator<<(ostream& os, const Dog& dog) {

	os << dog.Name << ", " << dog.age << ", " << dog.id << endl;

	return os;
}

// Dog 1'0000 객체의 정보를 파일에 기록한다.

int main() {

	ofstream out("Dog만마리",ios::binary);

	for (int i = 0; i < 1'0000; ++i) {
		Dog d;
		out.write((char*)&d, sizeof(Dog));
	}
}