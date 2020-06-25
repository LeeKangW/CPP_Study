#include<iostream>
#include<functional>
using namespace std;

class Sample {
	static int num;
	int id;
public:
	Sample() {
		id = num;
		++num;
	}
	~Sample() { cout << id<<"의 소멸자" << endl; }
	
	void show()const {
		cout << id << endl;
	}
};
int Sample::num{ 1 };
int main() {
	unique_ptr<Sample[]> s{ new Sample[3] };
	// 원래는 밑에와 같이 쓰는게 정석
	// 람다로 해도 되고 함수로 해도 되고
	unique_ptr<Sample, function<void(Sample*)>>s2 { new Sample[3],[](Sample* s) 
		{delete[]s; } };

	//Sample* s = new Sample[3];
	for (int i = 0; i < 3; ++i) {
		s[i].show();
		(s2.get() + i)->show();  // get() 으로 주소롤 받은 다음 처리.
	}
	//delete[] s;

}