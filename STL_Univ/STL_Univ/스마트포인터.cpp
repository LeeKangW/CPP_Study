#include<iostream>
#include<functional>

using namespace std;

void custom(int* p)
{
	delete[] p;
}
int main() {
#pragma region 스마트 포인터
	unique_ptr<int, function<void(int*)>>p{ new int[3],custom };
	unique_ptr<int, function<void(int*)>>p2{ new int[3],[](int* p) {delete[] p; } };
#pragma endregion

}
