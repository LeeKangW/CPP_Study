#include"default.h"
#include"String.h"

int main() {
	cout<<typeid(iterator_traits<String::iterator>::iterator_category).name()<<endl;
}