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
	~Sample() { cout << id<<"�� �Ҹ���" << endl; }
	
	void show()const {
		cout << id << endl;
	}
};
int Sample::num{ 1 };
int main() {
	unique_ptr<Sample[]> s{ new Sample[3] };
	// ������ �ؿ��� ���� ���°� ����
	// ���ٷ� �ص� �ǰ� �Լ��� �ص� �ǰ�
	unique_ptr<Sample, function<void(Sample*)>>s2 { new Sample[3],[](Sample* s) 
		{delete[]s; } };

	//Sample* s = new Sample[3];
	for (int i = 0; i < 3; ++i) {
		s[i].show();
		(s2.get() + i)->show();  // get() ���� �ּҷ� ���� ���� ó��.
	}
	//delete[] s;

}