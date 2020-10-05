#include<iostream>
#include<memory>
using namespace std;

class Dog
{
	int n;
public:
	// 생성과 소멸 관찰용
	 Dog() { cout << "생성" << endl; }
	 ~Dog() { cout << "소멸" << endl; }
	void show()
	{
		cout << "Dog입니다만" << endl;
	}
};
void f(unique_ptr<Dog>);
int main()
{
	/* *
	* 이러면 delete에 문제가 발생.
	Dog* p = new Dog; // 자원을 확보한다
	p->show(); // 자원을 사용한다
	f(p); // 자원을 사용한다
	delete p; // 자원을 반환한다
	*/

	/** 이 문제를 해결하기 위한 unique_ptr */
	unique_ptr<Dog> p{ new Dog };
	p->show();
	f(move(p));

}
void f(unique_ptr<Dog> pDog)
{
	pDog->show();
	cout << "함수" << endl;
}