#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string name;
	string qwd;

	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> qwd;
	system("cls");

	if (name == "54hk" && qwd == "123456") {
		cout << "1.��վ404����" << endl;
		cout << "2.��վ�۸Ĺ���" << endl;
		cout << "3.��վ������¼" << endl;
		cout << "4.DNS����" << endl;
		cout << "5.��������������" << endl;
	}
	else {
		cout << "�û���������������������룡" << endl;
	}

	system("pause");
	return 0;
}