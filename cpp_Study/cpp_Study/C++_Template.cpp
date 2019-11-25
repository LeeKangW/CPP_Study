#include<iostream>
#include<string>

using namespace std;

// Ŭ������ ���
template<typename T1,typename T2>
class Print {
private:
	// ��� �����ε� ��� �����ϴ�.
	T1 result;
	T2 result2;
public:
	static void print(T1 a, T2 b);
};
// �ܺ� ���� �� �ѹ� �� �ۼ������ �Ѵ�.
template<typename T1, typename T2>
void Print<T1, T2>::print(T1 a, T2 b) {
	cout << a << "   " << b << endl;
}
/* 
// ���ø� Ư��ȭ
// Ư���� �ڷ����� ���ؼ� �ٸ��� ó���ϰ� ���� �� ����ϴ� ���.

	��� ���
	template�� ���ǵǾ� ���� ��, ���� �Լ��� ���ؼ�, ������ �ϰ� ���� ������ Ÿ���� �ְ� ������ �ϸ� �ȴ�.
	T3 �� ���ְ� �ְ���� ������ Ÿ���� ������ �ȴ�.

*/
template<typename T3>
T3 sum(T3 a, T3 b) {
	cout << " a + b : ";
	return a + b;
}

template<>
string sum<string>(string a, string b) {
	string str = "string ���ڿ��� ���� �� �����ϴ�.";
	cout << "string a:"<<a << endl;
	cout << "string b:"<<b << endl;
	return str;
}

template<>
const char* sum<const char*>(const char* a, const char* b) {
	const char* str = "char* ���� ���� �� �����ϴ�.";
	cout << "const char* a: " << a << endl;
	cout << "const char* b: " << b << endl;
	return str;
}



int main() {
	Print<int, int>::print(1, 2);
	Print<int, string>::print(1, "ok");
	Print<string, string>::print("���ø�","����");
	Print<double, double>::print(1.4, 3.14);
		
	cout << endl << endl;

	int a = 10;
	int b = 20;
	string str1 = "���ø�";
	string str2 = "Ư��ȭ";
	const char* ch1 = "���ø�";
	const char* ch2 = "Ư��ȭ";
	cout << sum(a, b) << endl<<endl;
	cout << sum(str1, str2) << endl << endl;
	cout << sum(ch1, ch2) << endl << endl;

	return 0;
}