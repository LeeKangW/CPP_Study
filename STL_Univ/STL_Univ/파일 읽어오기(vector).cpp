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

// "��õ����"�� vector�� �о�Ͷ�
// vector�� �ִ� Dog�� show()�� ����϶�.


int main() {
	ifstream in("��õ����", ios::binary);
	if (!in) {
		cout << "������ �� �� �����ϴ�" << endl;
		return 0;
	}

	/* �迭�� �б�
	Dog dogs[1000];	// [ ], array, vector, string -> �޸𸮰� �پ� �ִ� STL
	in.read((char*)dogs, 1000 * sizeof(Dog));
	*/

	/* ���ͷ� �б�.
	*/
	vector<Dog> dogs;
	// dogs.reserve(1000); // �޸� Ȯ��
	dogs.resize(1000); // ���� �� 1000 - �޸� Ȯ��

	in.read((char*)dogs.data(), 1000 * sizeof(Dog));

	/* reserve �� �ϸ� �̷��� �ҷ��� �� �ִ�.
	for (int i = 0; i < 1000; ++i){
		dogs.data()[i].show(); // �޸𸮿� �����ؼ� �ع����� ��. �̷��� �������� ����.
		// dogs[i].show();
	}
	*/

	int num{};
	// �о� �� Dog�� �̸� ��������(ascending order)���� ����
	
	sort(dogs.begin(), dogs.end(), [&](const Dog& a, const Dog& b) {
		num++; // �� �� �θ����� üũ�غ���.
		return a.getname() < b.getname();
		});



	// resize �� �ʱ�ȭ �ϸ� �̷��� ���� ����
	for (const Dog& dog : dogs)
		dog.show();

	cout << endl <<"���ٰ� ȣ��� Ƚ�� - " << num << endl;
	cout << "vector�� ���� �� - " << dogs.size() << endl;
}