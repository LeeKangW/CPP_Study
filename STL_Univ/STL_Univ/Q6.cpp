#include<iostream>

using namespace std;

class Model {
private:
	static int id;
	int my_id = 0;
public:
	Model();
	~Model();
	Model(const Model& model);
	Model& operator=(const Model& model);
	Model(const Model&& model);
	Model& operator=(const Model&& model);
};
int Model::id = 0;
Model::Model() {
	my_id = 0;
	my_id = id;
	id +=1;
	cout << "생성된 id : "<<my_id << endl;
}
Model::~Model()
{
	cout << "소멸된 id : " << my_id << endl;
}
Model::Model(const Model& model)
{
	cout << "복사 생성자" << endl;
}
Model& Model::operator=(const Model& model) {
	cout << "복사 대입 연산자" << endl;

	return*this;
}
Model::Model(const Model&& model) {
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
	cout << "이동 생성자" << endl;
}
Model& Model::operator=(const Model&& model) {
	cout << "이동 대입 연산자" << endl;
	return*this;
}



int main() {
	Model a[10];
}