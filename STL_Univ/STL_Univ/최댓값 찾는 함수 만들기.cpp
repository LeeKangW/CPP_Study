#include"default.h"
#include"String.h"
#include<algorithm>

template<class T>
T my_max_element(T b,T e);

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };

	auto p = my_max_element(str.begin(), str.end());

	cout << "�ִ�: " << *p << endl;
}

template<class T>
T my_max_element(T b, T e) {
	
	/*
	//�˻��� ���Ұ� ���ٸ�
	if (b == e)
		return e;	// ������ ��ġ�� ����

	// ���� ó�� ������ ���� �ִ밪���� �ʱ�ȭ
	auto max_value = *b;
	// ���� ó�� ������ ��ġ�� �ִ��� ��ġ�� �ʱ�ȭ
	T max_position = b;

	while (b != e) {
		if (max_value < *b) {
			max_position = b;
			max_value = *b;
		}
		++b;
	}
	return max_position; // �ִ��� ��ġ�� ����
	*/

	if (b == e)
		return e;

	T max = b;

	while (++b != e)
		if (*max < b)
			max = b;

	return max;
}
