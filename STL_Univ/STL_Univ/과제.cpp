#include"default.h"
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>

/*

 �ñ��� ���� �־�, �ּ����� ������ϴ�.


 vector<Dog> dogs(1'0000);

	for (int i = 0; i < 1'0000; ++i) {
		in.read((char*)&dogs[i], sizeof(dogs[i]));
	}

 in.read�� ���� �� �ε����� ���� �־���µ�, ������ �ڵ����� �Ҵ��� �Ǿ����ϴ�.
 ����� �Լ��� �ۼ��Ͽ� Ȯ���غ�������, ���� �Ҹ��� ���� �������ϴ�.

 �������� ��������, ���� ���� ��, Ŭ���� �� ������ �ּҸ� ������ �־��⿡, �а� �ʱ�ȭ �� ���� �ش� �ּҸ� �����Ͽ� �Ҵ� �� ���̴� ��� �����ߴµ�,
 ��Ȯ�� ������ �ñ��մϴ�.


*/
class Dog {
private:
	string Name;
	int Age;
	int Id;
public:
	Dog() :Name{ " " }, Age{ 0 }, Id{ 0 } {}

	string Get_Name();

	Dog(const Dog& dog); 
	Dog& operator=(const Dog& dog);
	bool operator<(const Dog& a)const;
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
string Dog::Get_Name() {
	return Name;
}

bool Dog::operator<(const Dog& a) const {
	return this->Name < a.Name;
}

int main() {
	ifstream in("Dog������", ios::binary);

	vector<Dog> dogs(1'0000);

	for (int i = 0; i < 1'0000; ++i) {
		in.read((char*)&dogs[i], sizeof(dogs[i]));
	}

	cout << "������ ���� ��" << endl;

	sort(dogs.begin(), dogs.end());
	
	cout << "ó�� ��ü �̸� : " << dogs.at(0).Get_Name() << endl;
	cout << "������ ��ü �̸� : " << dogs.at(1'0000-1).Get_Name() << endl;

}