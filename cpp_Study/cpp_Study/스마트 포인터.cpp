#include<iostream>
#include<memory>
using namespace std;

class Dog
{
	int n;
public:
	// ������ �Ҹ� ������
	 Dog() { cout << "����" << endl; }
	 ~Dog() { cout << "�Ҹ�" << endl; }
	void show()
	{
		cout << "Dog�Դϴٸ�" << endl;
	}
};
void f(unique_ptr<Dog>);
int main()
{
	/* *
	* �̷��� delete�� ������ �߻�.
	Dog* p = new Dog; // �ڿ��� Ȯ���Ѵ�
	p->show(); // �ڿ��� ����Ѵ�
	f(p); // �ڿ��� ����Ѵ�
	delete p; // �ڿ��� ��ȯ�Ѵ�
	*/

	/** �� ������ �ذ��ϱ� ���� unique_ptr */
	unique_ptr<Dog> p{ new Dog };
	p->show();
	f(move(p));

}
void f(unique_ptr<Dog> pDog)
{
	pDog->show();
	cout << "�Լ�" << endl;
}