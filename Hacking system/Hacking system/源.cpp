#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>   //getch()使用
#include "hacker.h"

using namespace std;

#define WIDTH 45
#define HEIGHT 20

//初始化
void init(void) {
	//修改终端大小
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

//菜单功能
void memu(void) {
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击记录",
		"4.网站攻击修复",
		"5.退出"
	};
	
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menuCount; i++) {
		if(menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	//打印标题
	printInMiddle("----黑客攻击系统----");

	int leftSpace = (WIDTH - max) / 2;
	for (int i = 0; i < menuCount; i++) {
		for (int i = 0; i < leftSpace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}

	cout << endl;
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
	char id[64];   //网站的ID
	char response[MAXSIZE]; //攻击后，从服务器返回的结果

	printInMiddle("---网站404攻击---");
	cout << "请输入准备攻击的网站ID：";
	scanf_s("%s", id, sizeof(id));
	cout << "正在执行404攻击..." << endl;

	//发起攻击
	hk_404(id, response);

	//转换编码,把UTF8编码转换为GBK编码
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

//网站篡改攻击
void tampering_attack(void) {
	char id[64];   //网站的ID
	char response[MAXSIZE]; //攻击后，从服务器返回的结果
	string attackText;

	printInMiddle("---网站篡改攻击---");
	cout << "请输入你要攻击的ID：";
	scanf_s("%s", id, sizeof(id));
	cout << "请输入你要写入的内容：";
	cin >> attackText;

	GBKToUTF8(attackText);
	hk_tamper(id, (char *)attackText.c_str(), response);
	cout << "正在执行网页篡改攻击..." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	system("pause");
}

//查看攻击记录
void attack_record(void) {
	char id[64];   //网站的ID
	char response[MAXSIZE]; //攻击后，从服务器返回的结果

	cout << "请输入你要查看攻击记录的ID：";
	scanf_s("%s", id, sizeof(id));

	printInMiddle("---查看攻击记录---");
	hk_record(id, response);
	cout << "正在查看攻击记录...." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

//网站攻击修复
void attack_restore(void) {
	char id[64];   //网站的ID
	char response[MAXSIZE]; //攻击后，从服务器返回的结果

	cout << "请输入你要修复的ID：";
	scanf_s("%s", id, sizeof(id));
	hk_restore(id, response);
	cout << "正在修复网站...." << endl;

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
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

//实现密码的输入
void input_pwd(char pwd[], int size) {
	char c;
	int i = 0;

	while (1){
		//如果读到回车符，返回‘\r’
		c = _getch(); //不会回显
		if (c == '\r') {
			pwd[i] = 0;   //'\0'
			break;
		}
		pwd[i++] = c;
		cout << "*";
	}

	cout << endl;
}

//登陆页面
void login_page(void) {
	string name;
	char pwd[32];

	while (1) {
		system("cls");
		printInMiddle("------登陆------");
		cout << "请输入用户名：";
		cin >> name;

		cout << "请输入密码：";
		//cin >> pwd;
		//实现密码的输入
		input_pwd(pwd, sizeof(pwd));
		system("cls");

		if (name == "54hk" && !strcmp(pwd, "123456")) {
			break;
		} else {
			cout << "用户名或密码错误，请重新输入！" << endl;
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