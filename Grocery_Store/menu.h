#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

//This menu shows the Main menu for all the Users
void mainMenu() {
	cout << "\t\t _____________________________________________________________________________" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                              Welcome to Grocery_Store                       |" << endl;
	cout << "\t\t|                               <Punjab Cash and Carry>                       |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                            1 - Register as Admin                            |" << endl;
	cout << "\t\t|                            2 - Register as Manager                          |" << endl;
	cout << "\t\t|                            3 - Register as Customer                         |" << endl;
	cout << "\t\t|                            4 - Login as Admin                               |" << endl;
	cout << "\t\t|                            5 - Login as Manager                             |" << endl;
	cout << "\t\t|                            6 - Login as Customer                            |" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                          Press any other key to exit                        |" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
	cout << "\t\t Enter your choice: ";
}

///This Menu is visible for the admin of the store only
void adminMenu() {
	cout << "\t\t -----------------------------------------------------------------------------" << endl;
	cout << "\t\t|                              Admin Menu                                     |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                           1 - Access Managers                               |" << endl;
	cout << "\t\t|                           2 - Access Customers                              |" << endl;
	cout << "\t\t|                           3 - Add Product                                   |" << endl;
	cout << "\t\t|                           4 - Remove Product                                |" << endl;
	cout << "\t\t|                           5 - Display Products                              |" << endl;
	cout << "\t\t|                           6 - Logout                                        |" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
}

///This Menu is visible for the Manager of the store only
void ManagerMenu()
{
	cout << "\t\t -----------------------------------------------------------------------------" << endl;
	cout << "\t\t|                              Manager Menu                                   |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                          1 - Update Inventory Items                         |" << endl;
	cout << "\t\t|                          2 - Add Inventory Items                            |" << endl;
	cout << "\t\t|                          3 - Delete Inventpory Items                        |" << endl;
	cout << "\t\t|                          4 - Search Inventory Items                         |" << endl;
	cout << "\t\t|                          5 - View Inventory Items                           |" << endl;
	cout << "\t\t|                          6 - Logout                                         |" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
}

///This Menu is visible for the Customer of the store only
void CustomerMenu()
{
	cout << "\t\t -----------------------------------------------------------------------------" << endl;
	cout << "\t\t|                              Customer Menu                                  |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|                       1 - Search Products                                   |" << endl;
	cout << "\t\t|                       2 - Check Cart                                        |" << endl;
	cout << "\t\t|                       3 - Show total Bills                                  |" << endl;
	cout << "\t\t|                       4 - Give Feedback                                     |" << endl;
	cout << "\t\t|                       5 - Logout                                            |" << endl;
	cout << "\t\t|                                                                             |" << endl;
	cout << "\t\t|_____________________________________________________________________________|" << endl;
}

#endif // !MENU_H
