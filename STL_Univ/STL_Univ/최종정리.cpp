#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class Dog {
public:
	Dog() {
		new int;		// ���� �� �ڿ� Ȯ��
	}
	// ���� �� new int�� ���� �۾��� ������, �Ʒ��� �ൿ�� ����� �Ѵ�.
	~Dog() {}
	Dog(const Dog&) {}
	Dog& operator=(const Dog&);
	// �̵�
	// �̵��Ҵ�
};
class B {
public:
	void operator() () {}
};

template<class Iter,class Out>

Out my_copy(Iter b, Iter e, Out o) {

	// T�� �ݺ������� �Ǵ�
	is_base_of_v<output_iterator_tag,iterator_trait<Iter>::iterator_category>

	return o;
}
int main() {

#pragma region syntactic sugar
	int a[]{ 1,2,3 };
	cout << a[0] << endl; // a[0] -> syntactic sugar
	cout << *(a + 0) << endl; // a[0] -> syntactic sugar



	for (int n : a) // syntactic sugar
		cout << n << endl;
#pragma endregion

#pragma region smart pointer

	unique_ptr<int, > p;	// deleter�� �� �� �˾� �Ѵ�. ( �迭�� ���� �� )
#pragma endregion

#pragma region ȣ�� ���� Ÿ��
	int n;
	// n�� ȣ�� �����ϴ�??
	B b;
	b();

	// n�� ȣ���� �����ϴٸ�, n(); // �̰� �� �� ������ ȣ�Ⱑ��Ÿ���̴�.

	// Q. ȣ�� ���� Ÿ���� ����?  A : ȣ���� ������ Ÿ��
	// -> () �� ȣ���� �����ϸ� �ȴ�.

#pragma endregion

// ���� �����̳�
	// hash �Լ� -> unordered -> �˻� �ӵ��� ���� ������.

#pragma region �ݺ��� 
	// Q : �ݺ��ڶ�?
	// A : �ݺ��ڴ� �ݺ���ó�� �ൿ�� �� �ִ� ��. / �����͸� �߻�ȭ �� ��.
	
	
	// copy(begin(a), end(a), ostream_iterator<int>{cout, "\n"});
	my_copy(begin(a), end(a), ostream_iterator<int>{cout, "\n"});
#pragma endregion

#pragma region �ݺ��� �����
	// ���� �ݺ���, ������ �ݺ��� ��

#pragma endregion


}