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

//²Ëµ¥¹¦ÄÜ
void memu(void) {
		cout << "1.ÍøÕ¾404¹¥»÷" << endl;
		cout << "2.ÍøÕ¾´Û¸Ä¹¥»÷" << endl;
		cout << "3.ÍøÕ¾¹¥»÷¼ÇÂ¼" << endl;
		cout << "4.DNS¹¥»÷" << endl;
		cout << "5.·þÎñÆ÷ÖØÆô¹¥»÷" << endl;
	}

//µÇÂ½Ò³Ãæ
void login_page(void) {
	string name;
	string qwd;

	while (1) {
		system("cls");
		cout << "ÇëÊäÈëÓÃ»§Ãû£º";
		cin >> name;

		cout << "ÇëÊäÈëÃÜÂë£º";
		cin >> qwd;
		system("cls");


		if (name == "54hk" && qwd == "123456") {
			memu();
			break;
		}
		else {
			cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
			system("pause");
		}

	}
}