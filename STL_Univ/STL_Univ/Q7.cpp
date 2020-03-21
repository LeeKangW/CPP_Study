#include<iostream>

using namespace std;

class Model {
	char* data;		// 동적할당한 메모리의 시작번지
	size_t size;	// 메모리의 크기
public:
	Model() { cout << "생성자" << endl; };
	Model(int num);
	~Model();
	Model(Model& other);
	Model& operator=(const Model& other);
	Model(Model&& other);
	Model& operator=(const Model&& other);
};
Model::Model(int num) :size(num)
{
	data = new char[sizeof(char) * size];

	cout << "생성자" << endl;
}
Model::~Model()
{
	delete[] data;
	cout << "소멸자" << endl;
}
Model::Model(Model& other)
{
	cout << "복사 생성자" << endl;
}
Model& Model::operator=(const Model& other) {
	cout << "복사 대입 연산자" << endl;

	return*this;
}
Model::Model(Model&& other):data(nullptr),size(other.size) {
	/*

	이동 생성자
	-> C++11 부터 & 와 && 이 생겼다.
	&는 왼쪽값이라고 한다.

	왼쪽값은 이미 할당된 변수라고 생각하면 된다. 즉 int a = 3; 일 시, a는 왼쪽값이다.

	&& 은 오른쪽값 이라고 한다.

	오른쪽값은 사라지는 값이다. 즉, 1+2; 하면 3 이 나오고 사라지는데, 이를 오른쪽 값 이라 한다.

	복사 생성자와 같은 원리지만, &&은 매개변수로 생성 후 사라지기 때문에, 성능 상 유리하다.


	int a = 3;
	int& k = a; // 왼쪽값일 때, 왼쪽값은 가능
	int& k = 3; // 에러 -> 왼쪽 값 이지만, 3은 오른쪽값이기 때문에 에러
	int&& k = 3; // 둘 다 오른쪽 값이라 가능
	int&& k = a; // 에러 -> 오른쪽 값 = 왼쪽 값이라 에러


	*/
	data = other.data;

	other.data = nullptr;
	other.size = 0;

	cout << size << endl;
	cout << data << endl;

	cout << other.size << endl;
	cout << other.data << endl;
}
Model& Model::operator=(const Model&& other) {
	cout << "이동 대입 연산자" << endl;
	return*this;
}



int main() {
	Model a{ 1000 };
	Model b = move(a);
}