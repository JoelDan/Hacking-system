#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void login_page(void);
void Menu_realization(void);

int main(void) {
	login_page();
	Menu_realization();

	return 0;
}

//�˵�����
void memu(void) {
	cout << "1.��վ404����" << endl;
	cout << "2.��վ�۸Ĺ���" << endl;
	cout << "3.��վ������¼" << endl;
	cout << "4.��վ�����޸�" << endl;
	cout << "5.�˳�" << endl;
}

//�û����빦�ܱ��
int memuChoise(void) {
	int serial_number;    //�û�����ı��

	while (1) {
		cout << "��ѡ��";
		cin >> serial_number;

		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "��Ч���룬����������!" << endl;
			system("pause");
		} else {
			break;
		}
	}

	system("cls");
	return serial_number;
}

//404����
void attack404(void) {
	cout << "404����...." << endl;
	system("pause");
}

//��վ�۸Ĺ���
void tampering_attack(void) {
	cout << "��վ�۸Ĺ���...." << endl;
	system("pause");
}

//�鿴������¼
void attack_record(void) {
	cout << "�鿴������¼...." << endl;
	system("pause");
}

//��վ�����޸�
void attack_restore(void) {
	cout << "��վ�����޸�...." << endl;
	system("pause");
}

//ʵ�ֲ˵�ѡ���
void Menu_realization(void) {
	while (1) {
		memu();
		int serial_number = memuChoise();

		switch (serial_number) {
		case 1:
			attack404();
			break;
		case 2:
			tampering_attack();
			break;
		case 3:
			attack_record();
			break;
		case 4:
			attack_restore();
			break;
		case 5:
			return;
		default:
			cout << "��Ч���룬���������룡" << endl;
			system("pause");
			break;
		}
		system("cls");
	}
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
			break;
		} else {
			cout << "�û���������������������룡" << endl;
			system("pause");
		}
	}
}