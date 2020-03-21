#include<iostream>

using namespace std;

class Model {
private:
	static int id;
	int my_id = 0;
public:
	Model();
	~Model();
	Model(const Model& model);
	Model& operator=(const Model& model);
	Model(const Model&& model);
	Model& operator=(const Model&& model);
};
int Model::id = 0;
Model::Model() {
	my_id = 0;
	my_id = id;
	id +=1;
	cout << "������ id : "<<my_id << endl;
}
Model::~Model()
{
	cout << "�Ҹ�� id : " << my_id << endl;
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
	Model a[10];
}