#include"default.h"
#include"String.h"

String g{ "COVID-19" };			// g는 DATA,"COVID-19"는 HEAP에 복사
int main() {
	
	String s{ "COVID-19" };		// s는 STACK,"COVID-19"는 HEAP에 복사

	int n{ 2020 };

	cout << "지역변수 n의 번지 -" << &n << endl; // n은 STACK

}