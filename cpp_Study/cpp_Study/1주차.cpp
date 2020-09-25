#include<iostream>

using namespace std;

class Animal
{
private: // 자기 자신만 사용 가능
protected: // 부모랑 자식관계에서 사용 가능. (외부에서 접근이 불가)
	int ages = 0;
	string name = "";

public: // 다같이 쓴다. ( 공개된 것들 )
	/**
	* 1번 . 생성자
	* 2번 . 소멸자
	* 3번 . 복사생성자
	* 4번 . 대입연산자
	* 5번 . 이동생성자
	* 6번 . 이동대입연산자
	*/

	explicit Animal()
	{
		cout << "Animal 생성자" << endl;
	}; // 1번
	explicit Animal(int parmAge, string parmName) :ages(parmAge), name(parmName)
	{
		cout << "Animal 생성자" << endl;
	}

	virtual ~Animal() {}; // 2번
	Animal(const Animal& anim)
	{ // 3번 . 복사생성자
		cout << "Animal 복사생성자" << endl;
		ages = anim.ages;
		name = anim.name;
	}
	Animal& operator=(const Animal& anim)
	{
		cout << "Animal 복사대입연산자" << endl;
		ages = anim.ages;
		name = anim.name;
		return *this;
	} // 4번 . 복사대입연산자

// Animal(Animal&& anim){} // 4번. 이동생성자
// Animal& operator=(Animal&& anim) { return *this; } // 5번 . 이동대입연산자

	virtual void Speak()
	{
		cout << "Animal" << endl;
	}

	void Show()
	{
		cout << "나이 " << ages << endl << "이름 " << name << endl;
	}
};
class Dog : public Animal
{
private:

public:
	Dog() = default;
	Dog(int parmAge, string parmName) :Animal(parmAge, parmName)
	{
		cout << "Dog 생성자" << endl;
	}
	virtual void Speak() override
	{
		__super::Speak();
		cout << "멍멍" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void Speak() override
	{
		cout << "야옹" << endl;
	}
};

int main()
{
	unique_ptr<Animal> anim{ new Dog() };
}