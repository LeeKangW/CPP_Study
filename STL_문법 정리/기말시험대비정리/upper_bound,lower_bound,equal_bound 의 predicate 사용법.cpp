#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sample {
	int num{};
public:
	Sample(int n) :num{ n } {};
	int getNum() const { return num; }
	void show() const {
		cout << num << endl;
	}
};
int main() {

	vector<Sample> v;
	v.emplace_back(1);
	v.emplace_back(1);
	v.emplace_back(2);
	v.emplace_back(4);
	v.emplace_back(4);
	v.emplace_back(7);
	v.emplace_back(8);

	auto it = lower_bound(v.begin(), v.end(), Sample(1), [](const Sample& a, const Sample& b) {
		return a.getNum() < b.getNum();
		});
	it->show();
	auto it2 = upper_bound(v.begin(), v.end(), Sample(1), [](const Sample& a, const Sample& b) {
		return a.getNum() < b.getNum();
		});
	it2->show();

	auto [하한,상한] = equal_range(v.begin(), v.end(), Sample(1), [](const Sample& a, const Sample& b) {
		return a.getNum() < b.getNum();
		});
	하한->show();
	상한->show();

	auto b = binary_search(v.begin(),v.end(),Sample(100), [](const Sample& a, const Sample& b) {
		return a.getNum() < b.getNum();
		});
	cout << boolalpha << b << endl;
}