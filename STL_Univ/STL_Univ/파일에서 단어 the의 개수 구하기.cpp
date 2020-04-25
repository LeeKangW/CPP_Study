#include"default.h"
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>


string file{ "STL Wiki.txt"s };

int main() {
	ifstream in(file);

	if (!in) {
		cout << file << "이 없음." << endl;
	}
	int ch;
	string s;
	vector<string> v;

	while ((ch = in.get()) != EOF) {
		if (ch != ' ' && ch != '\n') {
			s.push_back(ch);
		}
		else if (ch == ' ') {
			v.push_back(s);
			s.clear();
		}
	}

	int count = 0;

	count = count_if(v.begin(), v.end(), [](string a) {
			return a == "the";
			// return a.compare("the") == 0;  // 이런 방법도 있다.
			});

	/* 이렇게도 찾을 수 있긴 함...
	for (auto i = v.begin(); i != v.end(); ++i) {
		if (*i == "the") {
			count += 1;
		}
	}
	*/
	cout << "STL Wiki.txt에는 모두 "<< count <<"개의 the가 있습니다."<< endl;
}