#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void memu(void);
void login_page(void);

int main(void) {

	login_page();

	system("pause");
	return 0;
}

//�˵�����
void memu(void) {
		cout << "1.��վ404����" << endl;
		cout << "2.��վ�۸Ĺ���" << endl;
		cout << "3.��վ������¼" << endl;
		cout << "4.DNS����" << endl;
		cout << "5.��������������" << endl;
	}

//��½ҳ��
void login_page(void) {
	string name;
	string qwd;

	while (1) {
		system("cls");
		cout << "�������û�����";
		cin >> name;

		cout << "���������룺";
		cin >> qwd;
		system("cls");


		if (name == "54hk" && qwd == "123456") {
			memu();
			break;
		}
		else {
			cout << "�û���������������������룡" << endl;
			system("pause");
		}

	}
}