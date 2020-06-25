#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

class Dog {
	string str{};

public:
	Dog(string s) :str{ s } {}
	
	string_view GetString() const { return str; }
};
int main() {
	vector<int> v{ 1,2,3,4,5 };
	vector<int> v2{ 1,3,3,3,5,5,5,8,8 };
	vector<Dog> v_dog;
	v_dog.emplace_back("�̷�");
	v_dog.emplace_back("Ŭ������");
	v_dog.emplace_back("�����ϰ���");

	list<int> l{ v.begin(),v.end() };

	if (is_sorted(v.begin(), v.end())) {
#pragma region binary_search
		// �����Ͱ� �ִ��� ������ ã��� binary_search( )
		cout << "======= binary_search =======" << endl << endl;
		bool b = binary_search(v.begin(), v.end(), 3);
		if (b)
			cout << "������ ����" << endl;
		else
			cout << "������ ����" << endl;

		cout << "=====================" << endl << endl;
#pragma endregion
	}
#pragma region lower_bound
	// lower_bound �� 
	// ã������
	// �����Ͱ� �ִٸ�, �������� ��ġ�� �ݺ��ڷ� ��ȯ���ְ�
	// �����Ͱ� ���ٸ�, �����ͺ��� ū ���� ���� ���� ã�´�.

	cout << "======= lower_bound =======" << endl << endl;
	auto it = lower_bound(v2.begin(), v2.end(), 3);
	cout << "lower_bound - "<< *it << endl;
	cout << "=====================" << endl << endl;
#pragma endregion
#pragma region upper_bound
	// upper_bound ��
	// ã������
	// �����Ͱ� �ִٸ�, ������ ���� �ʰ��ϴ� ���� ù �� ° ������ ��ġ�� ��ȯ ( Ex. 3, 3, 3, 5 �� ��, 3�� ã���� 5�� ���� )
	// �����Ͱ� ������, ���� ���� ���� ������ ��ġ�� ��ȯ�Ѵ�.
	cout << "======= upper_bound =======" << endl << endl;
	auto it2 = upper_bound(v2.begin(), v2.end(), 3);
	cout << "upper_bound - " << *it2 << endl;
	cout << "=====================" << endl << endl;
#pragma endregion
	
#pragma region equal_range
	// [���� ����] ���ĵ� ���¸� ���߸��� �ʰ�, 4�� ���� ��ġ�� ã�ƶ�.
	// ��ġ�� ã�ƶ�. -> equal_range �Լ�
	// equal_range�� lower_bound(), upper_bound() ����� ������ �����ش�.

	cout << "======= equal_range =======" << endl <<endl;
	

	auto [����,����] = equal_range(v2.begin(), v2.end(), 3);
	
	if (���� == ����) {
		cout << "�ߺ��Ǵ� ���� �����ϴ�." << endl;
		cout << "���� �� - " << *���� << " ���� �� - "<< *���� <<endl;
	}
	else {
		cout << "�ߺ��Ǵ� ���� �ֽ��ϴ�." << endl;
		cout << "���� �� - " << *���� << " ���� �� - " << *���� << endl;
	}
	cout << "=====================" << endl << endl;
#pragma endregion

	
}