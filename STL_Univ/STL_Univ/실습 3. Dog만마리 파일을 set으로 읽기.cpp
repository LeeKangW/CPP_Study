#include<set>
#include<fstream>
#include"default.h"
#include <iterator>
#include<string>


class Dog {
private:
	string Name;
	int Age;
	int Id;
public:
	Dog() :Name{ " " }, Age{ 0 }, Id{ 0 } {}

	string getname() { return Name; }
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	bool operator<(const Dog& a)const;
	friend istream& operator>>(istream&, Dog&);
};

Dog::Dog(const Dog& dog) :Name{ dog.Name }, Age{ dog.Age }, Id{ dog.Id }{
	/*
	   string 값인 Name이 있기 때문에,

	   복사생성자를 작성하지 않으면, 얕은 복사가 발생 ( string에서 주소만 복사하기 때문에 sort() 시, 런타임 에러가 발생 )

	   깊은 복사로 string 값 자체를 복사를 해줘야 런타임 에러가 발생하지 않는다.

	*/
}

Dog& Dog::operator=(const Dog& dog) {
	cout << "복사 대입 연산자 호출" << endl;
	Name = dog.Name;
	Age = dog.Age;
	Id = dog.Id;

	return *this;
}

bool Dog::operator<(const Dog& a) const {
	return this->Name < a.Name;
}
istream& operator>>(istream& input, Dog& dog) {
	input >> dog.Name >> dog.Age >> dog.Id;
	return input;
}

int main() {

}