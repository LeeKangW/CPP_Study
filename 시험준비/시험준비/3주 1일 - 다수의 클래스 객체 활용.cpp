#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<algorithm>

using namespace std;

int gid{};

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

class Dog {
private:
	string Name{};
	int age{ 0 };
	int id{ 0 };
public:
	Dog() :id{ ++gid } {
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			Name += uidName(dre);
		}
		age = uidAge(dre);
	}
	Dog(string name, int age) : Name{ name }, age{ age }, id(++gid) {
	}
	string GetName() const noexcept{
		return Name;
	}
	friend ostream& operator<<(ostream&, const Dog&);
};
ostream& operator<<(ostream& out, const Dog& dog) {
	out << dog.Name << ", " << dog.age << ", " << dog.id << endl;
	return out;
}

int main() {
	/*
	ofstream out("Dog만마리", ios::binary);

	for (int i = 0; i < 1'0000; ++i) {
		Dog d;
		out.write((char*)&d, sizeof(Dog));
	}
	*/
	ifstream in("Dog만마리", ios::binary);

	if (!in) {
		cout << "파일 없음." << endl;
		return 0;
	}
	Dog dog[1'0000];

	in.read((char*)dog, sizeof(Dog)*1'0000);

	sort(begin(dog), end(dog), [](const Dog& a, const Dog& b) {
		return a.GetName() < b.GetName();
		}
	);

	for (int i = 0; i < 1'0000; ++i) {
		cout << dog[i] << endl;
	}

	
}