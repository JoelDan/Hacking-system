#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string name;
	string qwd;

	cout << "ÇëÊäÈëÓÃ»§Ãû£º";
	cin >> name;

	cout << "ÇëÊäÈëÃÜÂë£º";
	cin >> qwd;
	system("cls");

	if (name == "54hk" && qwd == "123456") {
		cout << "1.ÍøÕ¾404¹¥»÷" << endl;
		cout << "2.ÍøÕ¾´Û¸Ä¹¥»÷" << endl;
		cout << "3.ÍøÕ¾¹¥»÷¼ÇÂ¼" << endl;
		cout << "4.DNS¹¥»÷" << endl;
		cout << "5.·þÎñÆ÷ÖØÆô¹¥»÷" << endl;
	}
	else {
		cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
	}

	system("pause");
	return 0;
}