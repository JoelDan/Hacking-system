#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>   //getch()ʹ��
#include "hacker.h"

using namespace std;

#define WIDTH 45
#define HEIGHT 20

//��ʼ��
void init(void) {
	//�޸��ն˴�С
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);

	system(cmd);
}

void printInMiddle(string msg) {
	int leftSpace = (WIDTH - msg.length()) / 2;

		for (int i = 0; i < leftSpace; i++) {
			cout << " ";
		}

		cout << msg << endl;
}

//�˵�����
void memu(void) {
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ������¼",
		"4.��վ�����޸�",
		"5.�˳�"
	};
	
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menuCount; i++) {
		if(menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	//��ӡ����
	printInMiddle("----�ڿ͹���ϵͳ----");

	int leftSpace = (WIDTH - max) / 2;
	for (int i = 0; i < menuCount; i++) {
		for (int i = 0; i < leftSpace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}

	cout << endl;
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
	char id[64];   //��վ��ID
	char response[MAXSIZE]; //�����󣬴ӷ��������صĽ��

	printInMiddle("---��վ404����---");
	cout << "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout << "����ִ��404����..." << endl;

	//���𹥻�
	hk_404(id, response);

	//ת������,��UTF8����ת��ΪGBK����
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

//��վ�۸Ĺ���
void tampering_attack(void) {
	char id[64];   //��վ��ID
	char response[MAXSIZE]; //�����󣬴ӷ��������صĽ��
	string attackText;

	printInMiddle("---��վ�۸Ĺ���---");
	cout << "��������Ҫ������ID��";
	scanf_s("%s", id, sizeof(id));
	cout << "��������Ҫд������ݣ�";
	cin >> attackText;

	GBKToUTF8(attackText);
	hk_tamper(id, (char *)attackText.c_str(), response);
	cout << "����ִ����ҳ�۸Ĺ���..." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	system("pause");
}

//�鿴������¼
void attack_record(void) {
	char id[64];   //��վ��ID
	char response[MAXSIZE]; //�����󣬴ӷ��������صĽ��

	cout << "��������Ҫ�鿴������¼��ID��";
	scanf_s("%s", id, sizeof(id));

	printInMiddle("---�鿴������¼---");
	hk_record(id, response);
	cout << "���ڲ鿴������¼...." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

//��վ�����޸�
void attack_restore(void) {
	char id[64];   //��վ��ID
	char response[MAXSIZE]; //�����󣬴ӷ��������صĽ��

	cout << "��������Ҫ�޸���ID��";
	scanf_s("%s", id, sizeof(id));
	hk_restore(id, response);
	cout << "�����޸���վ...." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
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

//ʵ�����������
void input_pwd(char pwd[], int size) {
	char c;
	int i = 0;

	while (1){
		//��������س��������ء�\r��
		c = _getch(); //�������
		if (c == '\r') {
			pwd[i] = 0;   //'\0'
			break;
		}
		pwd[i++] = c;
		cout << "*";
	}

	cout << endl;
}

//��½ҳ��
void login_page(void) {
	string name;
	char pwd[32];

	while (1) {
		system("cls");
		printInMiddle("------��½------");
		cout << "�������û�����";
		cin >> name;

		cout << "���������룺";
		//cin >> pwd;
		//ʵ�����������
		input_pwd(pwd, sizeof(pwd));
		system("cls");

		if (name == "54hk" && !strcmp(pwd, "123456")) {
			break;
		} else {
			cout << "�û���������������������룡" << endl;
			system("pause");
		}
	}
}

int main(void) {
	init();
	login_page();
	Menu_realization();

	return 0;
}