#include"default.h"
#include<forward_list>
#include"String.h"

int main() {
	forward_list<String> numbers{ "1","22","333" };

	auto bb = numbers.before_begin();	// bb�� "1"������ ��ġ�� ����Ŵ
	numbers.insert_after(bb, "0");		// ���� �տ� "0" ����

	numbers.emplace_front("-1");		// ���� �տ� -1 ���� ����

	int size = distance(numbers.cbegin(), numbers.cend()); // ������ ����

	forward_list<String>::iterator p{ numbers.begin() };
	advance(p, size - 1);		//String("333")�� ����Ű���� p�� �̵�

	auto last = numbers.emplace_after(p, "4444");
	// p ������ String("4444")�� ���� ����

	// �Լ��� ��ȯ���� �̿��ϸ� ��� ���Ҹ� �ڿ� �߰��� �� �ִ�.
	last = numbers.emplace_after(last, "5555");
	// ���� �ڿ� String("5555")�� ��������

	cout << "�����޽��� ����" << endl;
	cout << endl;

	cout << "forward_list�� ���� �� �ִ� �ִ� ���� ����: "
		<< numbers.max_size() << endl;
	cout << "forward_list�� ���� ��: "
		<< distance(numbers.begin(), numbers.end()) << endl;

	cout << endl;
	cout << "forward_list�� ���� ���" << endl;
	for (auto& number : numbers)
		cout << number << ' ';

	cout << endl;
	cout << endl;
}