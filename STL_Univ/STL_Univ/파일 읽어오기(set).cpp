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

// "��õ����"�� set�� �о�Ͷ�
// set�� Dog�� ���̱��� ascending order�� �ʱ�ȭ�Ѵ�.

// ���̰� uniform_distribution�ΰ� Ȯ���϶�.
// [1��] - �� ����
// [2��] - �� ����
// [3��] - �� ���� 
//
// [15��] - �� ����

bool ageComp(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}

int main() {
	ifstream in("��õ����", ios::binary);
	if (!in) {
		cout << "������ �� �� �����ϴ�" << endl;
		return 0;
	}

	/* �ذ����� 3���� �� ����.
	 1. operator< �� ���. -> �Ź� �ٲ���� �ϱ⿡ ���� ����� �ƴϴ�.
	 2. less Ŭ������ ������. -> ��õ���� �ʴ� ���.

	 3 �� ° ����� ���� ���� ��.
	 3. ���� ������ ����ֱ�.
	    multiset<Dog, ���ı���> s(���ı���);
	*/

	multiset<Dog, function<bool(const Dog&, const Dog&)>>s(ageComp);
	
	Dog dog;
	for (int i = 0; i < 1000; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		s.insert(dog);
	}

	// ���� Ȯ�� �ڵ� ����� ���
	map<int, int> m;

	for (const Dog& dog : s)
		m[dog.getAge()]++;

	// ��� ���

	for (auto& [����, ����] : m)
		cout << "[" << ���� << "] - " << ���� << endl;
}