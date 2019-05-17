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

//菜单功能
void memu(void) {
	cout << "1.网站404攻击" << endl;
	cout << "2.网站篡改攻击" << endl;
	cout << "3.网站攻击记录" << endl;
	cout << "4.网站攻击修复" << endl;
	cout << "5.退出" << endl;
}

//用户输入功能编号
int memuChoise(void) {
	int serial_number;    //用户输入的编号

	while (1) {
		cout << "请选择：";
		cin >> serial_number;

		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "无效输入，请重新输入!" << endl;
			system("pause");
		} else {
			break;
		}
	}

	system("cls");
	return serial_number;
}

//404攻击
void attack404(void) {
	cout << "404攻击...." << endl;
	system("pause");
}

//网站篡改攻击
void tampering_attack(void) {
	cout << "网站篡改攻击...." << endl;
	system("pause");
}

//查看攻击记录
void attack_record(void) {
	cout << "查看攻击记录...." << endl;
	system("pause");
}

//网站攻击修复
void attack_restore(void) {
	cout << "网站攻击修复...." << endl;
	system("pause");
}

//实现菜单选项功能
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
			cout << "无效输入，请重新输入！" << endl;
			system("pause");
			break;
		}
		system("cls");
	}
}

//登陆页面
void login_page(void) {
	string name;
	string qwd;

	while (1) {
		system("cls");
		cout << "请输入用户名：";
		cin >> name;

		cout << "请输入密码：";
		cin >> qwd;
		system("cls");

		if (name == "54hk" && qwd == "123456") {
			break;
		} else {
			cout << "用户名或密码错误，请重新输入！" << endl;
			system("pause");
		}
	}
}