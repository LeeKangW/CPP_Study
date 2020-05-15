#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;


class Dog {
private:
	string name{};
	size_t age{};
public:
	Dog() {	}
	string_view getname() const { return name; }
	size_t getAge()const { return age; }
	void show() const {
		cout << name << " - " << age << endl;
	}

	bool operator<(const Dog& rhs)const {
		return age < rhs.age;
	}
};

template<>
struct less<Dog> {
	bool operator()(const Dog& a, const Dog& b)const {
		return a.getAge() < b.getAge();
	}
};

// "개천마리"를 set로 읽어와라
// set은 Dog의 나이기준 ascending order로 초기화한다.

// 나이가 uniform_distribution인가 확인하라.
// [1살] - 몇 마리
// [2살] - 몇 마리
// [3살] - 몇 마리 
//
// [15살] - 몇 마리

bool ageComp(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}

int main() {
	ifstream in("개천마리", ios::binary);
	if (!in) {
		cout << "파일을 열 수 없습니다" << endl;
		return 0;
	}

	/* 해결방법은 3가지 가 있음.
	 1. operator< 를 사용. -> 매번 바꿔줘야 하기에 좋은 방법은 아니다.
	 2. less 클래스를 재정의. -> 추천하지 않는 방법.

	 3 번 째 방법이 가장 많이 씀.
	 3. 정렬 기준을 잡아주기.
	    multiset<Dog, 정렬기준> s(정렬기준);
	*/

	multiset<Dog, function<bool(const Dog&, const Dog&)>>s(ageComp);
	
	Dog dog;
	for (int i = 0; i < 1000; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		s.insert(dog);
	}

	// 분포 확인 코드 만들고 출력
	map<int, int> m;

	for (const Dog& dog : s)
		m[dog.getAge()]++;

	// 결과 출력

	for (auto& [나이, 개수] : m)
		cout << "[" << 나이 << "] - " << 개수 << endl;
}