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
		// c�� Ǫ���ϸ� �ȴ�.
		cout << "�� " << c << "�� �߰��մϴ�." << endl;
		s.push_back(c);
		return *this;
	}
	B_inst& operator=(const B_inst& rhs){
		// ���־� ��Ʃ��� ������ �� ��.
		return *this;
	}
	void operator++() {

	}
};
int main() {
	// Ű���忡�� �Է��� ���ڷ� s�� ä����.
	// - String�� char�� �����ϴ� �����̳ʷ� �����Ѵٴ� �ǹ�
	String s;
	copy(istreambuf_iterator<char>{cin}, {}, B_inst(s));

	cout << s.size() << endl;
	cout << s << endl;
}