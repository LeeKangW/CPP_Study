#include<iostream>
#include<string>
#include<random>
#include<fstream>
using namespace std;

default_random_engine dre;
uniform_int_distribution<> uidName('a','z');
uniform_int_distribution<> uidAge(1,15);

class Dog {
private:
	string name;
	size_t age;
public:
	Dog() {
		for (int i = 0; i < 10; ++i)
			name += uidName(dre);
		age = uidAge(dre);
	}
	void show() const {
		cout << name << " - " << age << endl;
	}
};

int main() {
	Dog dog[1000];
	ofstream out("개천마리",ios::binary);
	out.write((char*)dog, sizeof(Dog) * 1000);
}