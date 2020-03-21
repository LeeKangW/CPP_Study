#include<iostream>

using namespace std;

class Model {
	char* data;		// �����Ҵ��� �޸��� ���۹���
	size_t size;	// �޸��� ũ��
public:
	Model() { cout << "������" << endl; };
	Model(int num);
	~Model();
	Model(const Model& model);
	Model& operator=(const Model& model);
	Model(const Model&& model);
	Model& operator=(const Model&& model);
};
Model::Model(int num):size(num)
{ 
	data = new char[sizeof(char) * size];
	
	cout << "������" << endl; 
}
Model::~Model()
{ 
	delete[] data;
	cout << "�Ҹ���" << endl; 
}
Model::Model(const Model& model) 
{
	cout << "���� ������" << endl;
}
Model& Model::operator=(const Model& model) {
	cout << "���� ���� ������" << endl;
	
	return*this;
}
Model::Model(const Model&& model) {
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
	cout << "�̵� ������" << endl;
}
Model& Model::operator=(const Model&& model) {
	cout << "�̵� ���� ������" << endl;
	return*this;
}



int main() {
	Model a;
	Model b{ 1000 };

	Model c = b;
	a = c;
}