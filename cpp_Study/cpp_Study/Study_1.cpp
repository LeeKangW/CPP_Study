#include<iostream>

using namespace std;

class Calcu {
private:
	static int a;
	int b = 0;
public:
	static void Add();
};
int Calcu::a = 0;
void Calcu::Add() {
	a++;
	cout << "출력결과 : " << a << endl;

}

int main() {
	Calcu::Add();
	Calcu::Add();
	Calcu::Add();
}