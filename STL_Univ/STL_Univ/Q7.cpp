#include<iostream>

using namespace std;

class Model {
	char* data;		// �����Ҵ��� �޸��� ���۹���
	size_t size;	// �޸��� ũ��
public:
	Model() { cout << "������" << endl; };
	Model(int num);
	~Model();
	Model(Model& other);
	Model& operator=(const Model& other);
	Model(Model&& other);
	Model& operator=(const Model&& other);
};
Model::Model(int num) :size(num)
{
	data = new char[sizeof(char) * size];

	cout << "������" << endl;
}
Model::~Model()
{
	delete[] data;
	cout << "�Ҹ���" << endl;
}
Model::Model(Model& other)
{
	cout << "���� ������" << endl;
}
Model& Model::operator=(const Model& other) {
	cout << "���� ���� ������" << endl;

	return*this;
}
Model::Model(Model&& other):data(nullptr),size(other.size) {
	/*

	�̵� ������
	-> C++11 ���� & �� && �� �����.
	&�� ���ʰ��̶�� �Ѵ�.

	���ʰ��� �̹� �Ҵ�� ������� �����ϸ� �ȴ�. �� int a = 3; �� ��, a�� ���ʰ��̴�.

	&& �� �����ʰ� �̶�� �Ѵ�.

	�����ʰ��� ������� ���̴�. ��, 1+2; �ϸ� 3 �� ������ ������µ�, �̸� ������ �� �̶� �Ѵ�.

	���� �����ڿ� ���� ��������, &&�� �Ű������� ���� �� ������� ������, ���� �� �����ϴ�.


	int a = 3;
	int& k = a; // ���ʰ��� ��, ���ʰ��� ����
	int& k = 3; // ���� -> ���� �� ������, 3�� �����ʰ��̱� ������ ����
	int&& k = 3; // �� �� ������ ���̶� ����
	int&& k = a; // ���� -> ������ �� = ���� ���̶� ����


	*/
	data = other.data;

	other.data = nullptr;
	other.size = 0;

	cout << size << endl;
	cout << data << endl;

	cout << other.size << endl;
	cout << other.data << endl;
}
Model& Model::operator=(const Model&& other) {
	cout << "�̵� ���� ������" << endl;
	return*this;
}



int main() {
	Model a{ 1000 };
	Model b = move(a);
}