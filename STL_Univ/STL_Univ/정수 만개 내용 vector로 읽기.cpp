#include"default.h"
#include<fstream>
#include<random>
#include<string>
#include<cstdlib>

int main() {

	string file = "정수 만개";

	/*ofstream out("정수 만개");

	default_random_engine dre;
	uniform_int_distribution<> uid(0, 10'0000);

	for (int i = 0; i < 1'0000; ++i)
	{
		out << uid(dre) << " ";
		if (i % 10 == 9)
			out << endl;
	}
	*/

	
	ifstream in(file);

	if (!in)
		cout << file << "을 열지 못하였습니다." << endl;
	vector<int> v;
	v.reserve(1'0000);
	int n{};

	while (in >> n)
		v.emplace_back(n);

	int count{ count_if(v.begin(),v.end(),[](int i) {
		if (0 <= i && i < 1'0000)
			return true;
		return false;
}) };
	cout << "[0,1'0000) 인 원소 개수: "<<count<<endl;
}