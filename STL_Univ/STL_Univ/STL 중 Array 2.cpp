#include"default.h"
#include<array>
#include"String.h"


int main() {

	array<String, 5> words{ "corona,""virus","world","crisis","pandemic" };

	cout << words[0] << endl;	//�迭�� ���� ����

	auto p = words.begin();		 // words�� ù ���Ҹ� ����Ű�� �ݺ���
	cout << *p << endl;			// �ݺ��� p�� ����Ű�� ���� �ٷ� ù��° ����

	++p;						// ���� ���ҷ� �̵�
	cout << *p << endl; 

	for (int i = 0; i < words.size(); ++i) // ��� �����̳ʴ� size ����� ����
		cout << words[i] << " ";
	cout << endl;

	for (const String& word : words)			// range-based for�� ��ȸ
		cout << word << " ";
	cout << endl;

	// ������ ��� ��츦 ���� �����ϰ� �ʹٸ�

	try {
		// �̷��� ���� �ȵǰ�
		// cout << "�̰� ���� �����ݾ�?" << words[-1] << endl;
		cout << "�̰� ���� �����ݾ�?" << words.at(-1) << endl;
		// ���� ������ endl�� ��µ��� ������!
	}
	catch (const exception& e) {
		cout << "C++ ���� ���ܸ� ����ϴٴ�? -" << e.what() << endl;
	}
}