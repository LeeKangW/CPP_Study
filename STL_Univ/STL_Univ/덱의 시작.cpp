#include"default.h"
#include<deque>
#include<algorithm>
#include"String.h"


int main() {
	deque<String> news;
	news.push_back(String{ "�� ���� �������� ���ܰ���" });
	news.push_front(String{ "�� ���͸� �˻翡 ������ ���� ����" });

	news.emplace_back("�Ϻ� ������ ���� ���� �ܰ�");
	news.emplace_back("�������� ��޻��� �ʹ� �ʾ�..");

	cout << "���� �޽��� off" << endl;
	cout << endl;

	cout << "deque�� ����� ��� ���� ���" << endl;

	cout << endl;

	for (const String& news : news)
		cout << news << endl;

	cout << endl;

	// ���� �� ������������ ����
	sort(news.begin(), news.end(), [](const String& a, const String& b) {
		return a.size() < b.size();
		});

	// ��� ���
	cout << "���� �� �������� ����" << endl;
	cout << endl;
	for (int i = 0; i < news.size(); ++i)
		cout << news[i] << endl;
	cout << endl;

	//����� �ݴ�� ���
	cout << "���� �� �������� ����" << endl;
	cout << endl;
	for (auto i = news.begin(); i < news.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;
}