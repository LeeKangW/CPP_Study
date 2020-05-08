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
	string Name;	// �̸� - 15���ڱ����� ���
	int age;		// ����
	int id;			// ���� �� �����Ǵ� ������ ���ڷ� �� id

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

// Dog 1'0000 ��ü�� ������ ���Ͽ� ����Ѵ�.

int main() {

	ofstream out("Dog������",ios::binary);

	for (int i = 0; i < 1'0000; ++i) {
		Dog d;
		out.write((char*)&d, sizeof(Dog));
	}
}