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
		// c�� pushback
		cout << "�� " << c << "�� �߰��մϴ�." << endl;
		return *this;
	};
	void operator++() {

	};
};

template<class Iter, class >

int main() {
	// Ű���忡�� �Է��� ������ s�� ä����.
	// - String�� char�� �����ϴ� �����̳ʷ� �����Ѵٴ� �ǹ�
	String s;
	copy(istreambuf_iterator<char>{cin}, {}, B_inst(s));

	cout << s << endl;
}