#include"default.h"
#include<vector>
#include"String.h"


int main() {

	vector<String> v;
	v.reserve(2);
	//v.push_back(String("코로나"));
	v.emplace_back("코로나");

	cout << "------- 원소 추가 -------" << endl;
	//v.push_back(String("바이러스"));
	v.emplace_back("바이러스");
	//원소를 관리하는 컨테이너는 범위기반 for를 사용하자.
	for (String& s : v)
		cout << s << endl;

}