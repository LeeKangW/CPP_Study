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
	// Q5를 위한 문제
	bool operator<(const Name& name) {
		return last < name.last;
	}
	*/
};

string file1{ "고객.txt" }, file2{ "고객2.txt" };

void makeUpper(vector<Name>&);
void makeData();

int main() {
#pragma region  Q1 1'0000명 정보를 읽어 컨테이너에 저장
	ifstream in(file1);
	if (!in) {
		cout << file1 << "이 없습니다." << endl;
		return 0;
	}

	vector<Name> names;
	names.reserve(1'0000);


	for (int i = 0; i < 1'0000; ++i)
	{
		/*  그냥 string 으로 받는 방법.
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

	cout << endl << "Q2 시작" << endl;

#pragma region Q2. 컨테이너에서 성(last name)이 "kim"인 객체를 찾기.
	auto find=find_if(names.begin(), names.end(), [](const Name& a) {
		if (a.getLast() == "kim")
			return true;
		return false;
		});

	if (find != names.end()) {
		cout << "객체 찾음" << endl;
		find->show();
	}
	else
		cout << "찾지 못함" << endl;
#pragma endregion

	cout << endl << "Q3 시작" << endl;

#pragma region Q3 컨테이너의 모든 객체를 이름(first name) 오름차순으로 정렬하라.
	sort(names.begin(), names.end(), [](const Name& a, const Name& b) {
		return a.getFirst() < b.getFirst();
		});

	/*for (const Name& name : names)
		name.show();*/
#pragma endregion

	cout << endl << "Q4 시작" << endl;

#pragma region Q4 makeUpper()는 위 문제에서 사용한 컨테이너를 인자로 받아 이름 첫 글자를 대문자로 바꾼다.
	makeUpper(names);

	/*for (const auto& name : names)
		name.show();*/
#pragma endregion

	cout << endl << "Q4 시작" << endl;

#pragma region Q5 sort 사용 시, 성(last name) 기준 오름차순으로 정렬
	// 문제가 operator< 연산자 오버로딩이 필요

	//sort(names.begin(), names.end());

	//for (const auto& name : names)
	//	name.show();
#pragma endregion

#pragma region Q6 "고객.txt"와"고객2.txt"를 한개의 컨테이너로 합하라.
	// 합한 컨테이너의 원소개수를 출력하고 이 결과도 답지에 적어라.

	// 합한 컨테이너에는 동일한 성(last name)의 Name 객체가 존재해서는 안된다.
	// 동일한 성의 Name 객체들 중에서 어떤 것을 남길지는 정하지 않아도 된다.
	
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

	cout << "last name 중복 제거 후 총 개수 - " << names.size() << endl;
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