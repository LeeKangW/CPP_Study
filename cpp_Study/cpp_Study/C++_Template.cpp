#include<iostream>
#include<string>

using namespace std;

// 클래스로 사용
template<typename T1,typename T2>
class Print {
private:
	// 멤버 변수로도 사용 가능하다.
	T1 result;
	T2 result2;
public:
	static void print(T1 a, T2 b);
};
// 외부 정의 시 한번 더 작성해줘야 한다.
template<typename T1, typename T2>
void Print<T1, T2>::print(T1 a, T2 b) {
	cout << a << "   " << b << endl;
}
/* 
// 템플릿 특수화
// 특수한 자료형에 대해서 다르게 처리하고 싶을 때 사용하는 방법.

	사용 방법
	template가 정의되어 있을 때, 같은 함수에 대해서, 재정의 하고 싶은 데이터 타입을 넣고 재정의 하면 된다.
	T3 를 없애고 넣고싶은 데이터 타입을 넣으면 된다.

*/
template<typename T3>
T3 sum(T3 a, T3 b) {
	cout << " a + b : ";
	return a + b;
}

template<>
string sum<string>(string a, string b) {
	string str = "string 문자열은 더할 수 없습니다.";
	cout << "string a:"<<a << endl;
	cout << "string b:"<<b << endl;
	return str;
}

template<>
const char* sum<const char*>(const char* a, const char* b) {
	const char* str = "char* 형은 더할 수 없습니다.";
	cout << "const char* a: " << a << endl;
	cout << "const char* b: " << b << endl;
	return str;
}



int main() {
	Print<int, int>::print(1, 2);
	Print<int, string>::print(1, "ok");
	Print<string, string>::print("템플릿","사용법");
	Print<double, double>::print(1.4, 3.14);
		
	cout << endl << endl;

	int a = 10;
	int b = 20;
	string str1 = "템플릿";
	string str2 = "특수화";
	const char* ch1 = "템플릿";
	const char* ch2 = "특수화";
	cout << sum(a, b) << endl<<endl;
	cout << sum(str1, str2) << endl << endl;
	cout << sum(ch1, ch2) << endl << endl;

	return 0;
}