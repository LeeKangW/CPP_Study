#include"save.h"


void save(string_view str) { // save ����

	size_t size = filesystem::file_size(str);

	unique_ptr<char[]>p{ new char[size] };
	
	ifstream in(str);

	in.read(p.get(), size);

	ofstream out("���� ����.txt", ios::binary | ios::app);

	auto tp = chrono::system_clock::now();
	auto ct = chrono::system_clock::to_time_t(tp);
	auto lt = localtime(&ct);

	out.imbue(locale("korean"));

	out << put_time(lt, "%c - (%A)") << endl;

	out.write(p.get(), size);

#pragma region  ���� ���
	/*
// ������ ���� ������ ���� -> "���������.cpp"

	ifstream in(str);
	//���� ������ ������ ������ ���� -> ������ �����̸��� "��������.txt" ��� ����
	ofstream out("���� ����.txt", ios::app); // ios::app ���ٿ�����
	//���������.cpp�� ��� ������ �о� ��������.txt ���Ͽ� ����Ѵ�.
	int c;
	out << endl;
	while ((c = in.get()) != EOF)
		out << (char)c;

	cout << str << "�� ��������.txt�� �����Ͽ����ϴ�." << endl;
	*/
#pragma endregion

	

}