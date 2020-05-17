#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<fstream>
#include<string>


using namespace std;

class Name {
	string first{};
	string last{};
public:
	Name() {}
	Name(string first, string last) :first{ first }, last{ last }{}

	string& getFirst() {
		return first;
	}
	string getFirst()const {
		return first;
	}
	string getLast()const {
		return last;
	}
	void setLast(const string& name) {
		last = name;
	}
	void show() const {
		cout << first << " " << last << endl;
	}

	void makeUpper() {
		first[0]=toupper(first[0]);
	}
	
	friend ifstream& operator>>(ifstream& in,Name& rhs) {
		 in >> rhs.first;
		 in >> rhs.last;

		return in;
	}

	/*
	// Q5�� ���� ����
	bool operator<(const Name& name) {
		return last < name.last;
	}
	*/
};

string file1{ "��.txt" }, file2{ "��2.txt" };

void makeUpper(vector<Name>&);
void makeData();

int main() {
#pragma region  Q1 1'0000�� ������ �о� �����̳ʿ� ����
	ifstream in(file1);
	if (!in) {
		cout << file1 << "�� �����ϴ�." << endl;
		return 0;
	}

	vector<Name> names;
	names.reserve(1'0000);


	for (int i = 0; i < 1'0000; ++i)
	{
		/*  �׳� string ���� �޴� ���.
		string first, last;

		in >> first;
		in >> last;

		cout << first << "- " << last << endl;
		*/
		Name name;
		in >> name;

		names.push_back(name);
	}
#pragma endregion

	cout << endl << "Q2 ����" << endl;

#pragma region Q2. �����̳ʿ��� ��(last name)�� "kim"�� ��ü�� ã��.
	auto find=find_if(names.begin(), names.end(), [](const Name& a) {
		if (a.getLast() == "kim")
			return true;
		return false;
		});

	if (find != names.end()) {
		cout << "��ü ã��" << endl;
		find->show();
	}
	else
		cout << "ã�� ����" << endl;
#pragma endregion

	cout << endl << "Q3 ����" << endl;

#pragma region Q3 �����̳��� ��� ��ü�� �̸�(first name) ������������ �����϶�.
	sort(names.begin(), names.end(), [](const Name& a, const Name& b) {
		return a.getFirst() < b.getFirst();
		});

	/*for (const Name& name : names)
		name.show();*/
#pragma endregion

	cout << endl << "Q4 ����" << endl;

#pragma region Q4 makeUpper()�� �� �������� ����� �����̳ʸ� ���ڷ� �޾� �̸� ù ���ڸ� �빮�ڷ� �ٲ۴�.
	makeUpper(names);

	/*for (const auto& name : names)
		name.show();*/
#pragma endregion

	cout << endl << "Q4 ����" << endl;

#pragma region Q5 sort ��� ��, ��(last name) ���� ������������ ����
	// ������ operator< ������ �����ε��� �ʿ�

	//sort(names.begin(), names.end());

	//for (const auto& name : names)
	//	name.show();
#pragma endregion

#pragma region Q6 "��.txt"��"��2.txt"�� �Ѱ��� �����̳ʷ� ���϶�.
	// ���� �����̳��� ���Ұ����� ����ϰ� �� ����� ������ �����.

	// ���� �����̳ʿ��� ������ ��(last name)�� Name ��ü�� �����ؼ��� �ȵȴ�.
	// ������ ���� Name ��ü�� �߿��� � ���� �������� ������ �ʾƵ� �ȴ�.
	
	ifstream in2(file2);

	names.reserve(3'0000);
	for (int i = 0; i < 2'0000; ++i) {
		Name name;
		in >> name;

		names.push_back(name);
	}

	sort(names.begin(), names.end(), [](const Name& a, const Name& b) {
		return a.getLast() < b.getLast();
		}
	);
	names.erase(unique(names.begin(), names.end(), [](const Name& a, const Name& b) {
		return a.getLast() == b.getLast();
		}), names.end());

	cout << "last name �ߺ� ���� �� �� ���� - " << names.size() << endl;
#pragma endregion



}

void makeUpper(vector<Name>& names) {
	
	for (auto& name : names)
		name.makeUpper();
	
}
void makeData() {
	ofstream out1(file1);
	ofstream out2(file2);

	default_random_engine dre;
	uniform_int_distribution<> uidNameLen(3, 12);
	uniform_int_distribution<> uidName('a', 'z');

	for (int i = 0; i < 1'0000; ++i) {
		string first;
		for (int i = 0; i < uidNameLen(dre); ++i)
			first += uidName(dre);

		string second;
		for (int i = 0; i < 3; ++i)
			second += uidName(dre);

		Name name(first, second);
		out1 << name.getFirst() << "\t" << name.getLast() << endl;
	}

	for (int i = 0; i < 2'0000; ++i) {
		string first;
		for (int i = 0; i < uidNameLen(dre); ++i)
			first += uidName(dre);

		string second;
		for (int i = 0; i < 3; ++i)
			second += uidName(dre);

		Name name(first, second);
		out2 << name.getFirst() << "\t" << name.getLast() << endl;

	}

}