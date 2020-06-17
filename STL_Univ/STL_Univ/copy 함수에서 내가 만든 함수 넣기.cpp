#include"default.h"
#include"String.h"

class B_inst {
	String& s;
public:
	explicit B_inst(String& s) :s{ s } {}

	B_inst& operator*() {
		return *this;
	}
	B_inst& operator=(char c) {
		// c를 푸시하면 된다.
		cout << "네 " << c << "를 추가합니다." << endl;
		s.push_back(c);
		return *this;
	}
	B_inst& operator=(const B_inst& rhs){
		// 비주얼 스튜디오 때문에 들어간 것.
		return *this;
	}
	void operator++() {

	}
};
int main() {
	// 키보드에서 입력한 글자로 s를 채워라.
	// - String을 char를 저장하는 컨테이너로 생각한다는 의미
	String s;
	copy(istreambuf_iterator<char>{cin}, {}, B_inst(s));

	cout << s.size() << endl;
	cout << s << endl;
}