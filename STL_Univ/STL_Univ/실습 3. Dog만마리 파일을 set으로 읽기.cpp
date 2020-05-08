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
	   string ���� Name�� �ֱ� ������,

	   ��������ڸ� �ۼ����� ������, ���� ���簡 �߻� ( string���� �ּҸ� �����ϱ� ������ sort() ��, ��Ÿ�� ������ �߻� )

	   ���� ����� string �� ��ü�� ���縦 ����� ��Ÿ�� ������ �߻����� �ʴ´�.

	*/
}

Dog& Dog::operator=(const Dog& dog) {
	cout << "���� ���� ������ ȣ��" << endl;
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