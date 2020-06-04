#include"default.h"
#include<forward_list>
#include<list>
#include<deque>
#include<array>
#include<vector>
#include<iterator>
#include"String.h"

template <class Iter>
void showCategory(const Iter&);

int main() {
	istream_iterator<char> in_iter;
	ostream_iterator<short> out_iter{ cout };
	forward_list<int>::iterator forward_list_iter;
	list<float>::iterator list_iter;
	deque<double>::iterator deque_iter;
	array<String, 0>::iterator array_iter;
	vector<vector<char>>::iterator vector_iter;

	showCategory(in_iter);
	showCategory(out_iter);
	showCategory(forward_list_iter);
	showCategory(list_iter);
	showCategory(deque_iter);
	showCategory(array_iter);
	showCategory(vector_iter);
	cout << "������ Ÿ��" << endl;
	int* a = nullptr;
	showCategory(a);


}

template<class Iter>
void showCategory(const Iter& t) {
	cout << typeid(iterator_traits<Iter>::iterator_category).name() << endl;
}