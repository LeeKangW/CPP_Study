#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


class Dog {
private:
	string name;
	size_t age;
public:
	Dog() {	}
	string_view getname() const{ return name; }
	void show() const {
		cout << name << " - " << age << endl;
	}

	bool operator<(const Dog& rhs)const {
		return name < rhs.name;
	}
};

// "개천마리"를 vector로 읽어와라
// vector에 있는 Dog를 show()로 출력하라.


int main() {
	ifstream in("개천마리", ios::binary);
	if (!in) {
		cout << "파일을 열 수 없습니다" << endl;
		return 0;
	}

	/* 배열로 읽기
	Dog dogs[1000];	// [ ], array, vector, string -> 메모리가 붙어 있는 STL
	in.read((char*)dogs, 1000 * sizeof(Dog));
	*/

	/* 벡터로 읽기.
	*/
	vector<Dog> dogs;
	// dogs.reserve(1000); // 메모리 확보
	dogs.resize(1000); // 원소 수 1000 - 메모리 확보

	in.read((char*)dogs.data(), 1000 * sizeof(Dog));

	/* reserve 로 하면 이렇게 불러올 수 있다.
	for (int i = 0; i < 1000; ++i){
		dogs.data()[i].show(); // 메모리에 접근해서 해버리는 거. 이렇게 접근하진 않음.
		// dogs[i].show();
	}
	*/

	int num{};
	// 읽어 온 Dog를 이름 오름차순(ascending order)으로 정렬
	
	sort(dogs.begin(), dogs.end(), [&](const Dog& a, const Dog& b) {
		num++; // 몇 번 부르는지 체크해보자.
		return a.getname() < b.getname();
		});



	// resize 로 초기화 하면 이렇게 접근 가능
	for (const Dog& dog : dogs)
		dog.show();

	cout << endl <<"람다가 호출된 횟수 - " << num << endl;
	cout << "vector의 원소 수 - " << dogs.size() << endl;
}