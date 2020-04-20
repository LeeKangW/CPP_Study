#include"default.h"
#include<forward_list>
#include"String.h"

int main() {
	forward_list<String> numbers{ "1","22","333" };

	auto bb = numbers.before_begin();	// bb는 "1"이전의 위치를 가리킴
	numbers.insert_after(bb, "0");		// 제일 앞에 "0" 삽입

	numbers.emplace_front("-1");		// 제일 앞에 -1 생성 삽입

	int size = distance(numbers.cbegin(), numbers.cend()); // 원소의 갯수

	forward_list<String>::iterator p{ numbers.begin() };
	advance(p, size - 1);		//String("333")을 가리키도록 p를 이동

	auto last = numbers.emplace_after(p, "4444");
	// p 다음에 String("4444")를 생성 삽입

	// 함수의 반환값을 이용하면 계속 원소를 뒤에 추가할 수 있다.
	last = numbers.emplace_after(last, "5555");
	// 제일 뒤에 String("5555")를 생성삽입

	cout << "관찰메시지 없음" << endl;
	cout << endl;

	cout << "forward_list가 담을 수 있는 최대 원소 개수: "
		<< numbers.max_size() << endl;
	cout << "forward_list의 원소 수: "
		<< distance(numbers.begin(), numbers.end()) << endl;

	cout << endl;
	cout << "forward_list의 원소 출력" << endl;
	for (auto& number : numbers)
		cout << number << ' ';

	cout << endl;
	cout << endl;
}