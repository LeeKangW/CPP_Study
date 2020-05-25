#include<iostream>
#include<unordered_set>
#include<set>
#include"String.h"

using namespace std;

// ���ø� Ư��ȭ�� ���� hash�� string ���� ���� ������ hash �Լ��� ����.
template<>
struct hash<String> 
{
	unsigned int operator()(const String& s) const {
		return hash<string>()(s.getString());
	}
};
int main() {
	// unordered�� ���� ���ؼ� hash �Լ��� �ʿ��ϴ�.
	unordered_set<String> us{ "��ŷ����","Ȱ���","��","�ִ�","����","��ǻ��" };
	
	// �̰ͺ��� ���� ã���ִ� �����̳ʴ� ����.
	while (true) {
		cout << "ã���� ���Ҵ�? ";
		String s;
		cin >> s;

		auto p=us.find(s);
		
		if (p != us.end())
			cout << s << "�� ã�ҽ��ϴ�." << endl;
		else
			cout << s << "�� ���� �����Դϴ�." << endl;
	}

	/*
	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << "[" << i << "]";
		if (us.bucket_size(i)) {
			for (auto p = us.begin(i); p != us.end(i); ++p)
				cout << " --> " << *p;

		}
		cout << endl;
	}
	*/
}