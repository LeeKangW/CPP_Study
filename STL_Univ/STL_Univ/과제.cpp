#include"default.h"
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>

/*

 궁금한 점이 있어, 주석으로 남겼습니다.


 vector<Dog> dogs(1'0000);

	for (int i = 0; i < 1'0000; ++i) {
		in.read((char*)&dogs[i], sizeof(dogs[i]));
	}

 in.read를 통해 각 인덱스에 맞춰 넣어줬는데, 변수에 자동으로 할당이 되었습니다.
 스페셜 함수를 작성하여 확인해보았지만, 따로 불리는 것은 없었습니다.

 개인적인 생각으론, 파일 생성 시, 클래스 내 변수의 주소를 가지고 있었기에, 읽고 초기화 할 때도 해당 주소를 참조하여 할당 된 것이다 라고 생각했는데,
 정확한 원리가 궁금합니다.


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
string Dog::Get_Name() {
	return Name;
}

bool Dog::operator<(const Dog& a) const {
	return this->Name < a.Name;
}

int main() {
	ifstream in("Dog만마리", ios::binary);

	vector<Dog> dogs(1'0000);

	for (int i = 0; i < 1'0000; ++i) {
		in.read((char*)&dogs[i], sizeof(dogs[i]));
	}

	cout << "데이터 삽입 됨" << endl;

	sort(dogs.begin(), dogs.end());
	
	cout << "처음 객체 이름 : " << dogs.at(0).Get_Name() << endl;
	cout << "마지막 객체 이름 : " << dogs.at(1'0000-1).Get_Name() << endl;

}