#include <Windows.h>
#include <iomanip>
#include<iostream>
#include "Grocery_Store.h"
#include "menu.h"
#include <cstring>

using namespace std;

int main()
{
	system("color F0");
	int choice = 1;
	Grocery_Store ms;
	while (choice != 0)
	{
		mainMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			ms.Register(1);
			choice = 1;
			Sleep(2000);
			break;
		case 2:
			ms.Register(2);
			choice = 1;
			Sleep(2000);
			break;
		case 3:
			ms.Register(3);
			choice = 1;
			Sleep(2000);
			break;
		case 4:
			ms.Login(1);
			choice = 1;
			Sleep(2000);
			break;
		case 5:
			ms.Login(2);
			choice = 1;
			Sleep(2000);
			break;
		case 6:
			ms.Login(3);
			choice = 1;
			Sleep(2000);
			break;
		case 7:
			system("CLS");
			cout << "Enter any key to go back to main menu: ";
			cin >> choice;
			choice = 1;
			break;
		default:
			choice = 0;
			break;
		}
		system("CLS");
	}
	return 0;
}