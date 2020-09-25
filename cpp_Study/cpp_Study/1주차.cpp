#include<iostream>

using namespace std;

class Animal
{
private: // �ڱ� �ڽŸ� ��� ����
protected: // �θ�� �ڽİ��迡�� ��� ����. (�ܺο��� ������ �Ұ�)
	int ages = 0;
	string name = "";

public: // �ٰ��� ����. ( ������ �͵� )
	/**
	* 1�� . ������
	* 2�� . �Ҹ���
	* 3�� . ���������
	* 4�� . ���Կ�����
	* 5�� . �̵�������
	* 6�� . �̵����Կ�����
	*/

	explicit Animal()
	{
		cout << "Animal ������" << endl;
	}; // 1��
	explicit Animal(int parmAge, string parmName) :ages(parmAge), name(parmName)
	{
		cout << "Animal ������" << endl;
	}

	virtual ~Animal() {}; // 2��
	Animal(const Animal& anim)
	{ // 3�� . ���������
		cout << "Animal ���������" << endl;
		ages = anim.ages;
		name = anim.name;
	}
	Animal& operator=(const Animal& anim)
	{
		cout << "Animal ������Կ�����" << endl;
		ages = anim.ages;
		name = anim.name;
		return *this;
	} // 4�� . ������Կ�����

// Animal(Animal&& anim){} // 4��. �̵�������
// Animal& operator=(Animal&& anim) { return *this; } // 5�� . �̵����Կ�����

	virtual void Speak()
	{
		cout << "Animal" << endl;
	}

	void Show()
	{
		cout << "���� " << ages << endl << "�̸� " << name << endl;
	}
};
class Dog : public Animal
{
private:

public:
	Dog() = default;
	Dog(int parmAge, string parmName) :Animal(parmAge, parmName)
	{
		cout << "Dog ������" << endl;
	}
	virtual void Speak() override
	{
		__super::Speak();
		cout << "�۸�" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void Speak() override
	{
		cout << "�߿�" << endl;
	}
};

int main()
{
	unique_ptr<Animal> anim{ new Dog() };
}