#include"default.h"
#include"String.h"
#include<algorithm>
#include<iterator>

class B_inst {
	String s;
public:
	explicit B_inst(String& s) :s{ s } {}

	B_inst& operator*() {

		return *this;
	};
	B_inst& operator=(char c) {
		// c를 pushback
		cout << "네 " << c << "를 추가합니다." << endl;
		return *this;
	};
	void operator++() {

	};
};

template<class Iter, class >

int main() {
	// 키보드에서 입력한 값으로 s를 채워라.
	// - String을 char를 저장하는 컨테이너로 생각한다는 의미
	String s;
	copy(istreambuf_iterator<char>{cin}, {}, B_inst(s));

	cout << s << endl;
}