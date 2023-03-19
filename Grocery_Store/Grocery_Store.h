
#define Grocery_Store_H

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "Users.h"
#include "Feedback.h"
#include "HelpingFunctions.h"
#include "menu.h"
#include "Product_Cata.h"

using namespace std;

Manager getManager(string cnic, string pass)
{
	Manager obj;
	ifstream infile;
	infile.open("manager.dat", ios::binary);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (obj.Login(cnic, pass))
		{
			ifstream inf;
			inf.open("managers_" + obj.getName() + ".dat", ios::binary);
			inf.close();
			infile.close();
			cout << "MESSAGE: Accessed!" << endl;
			return obj;
		}
	}
	infile.close();
	return obj;
}


class Grocery_Store {
private:
	int userType;
	int noAdmins, noManagers, noCustomers,noFeedbacks;
	Admin* admins;
	Manager* manager;
	Customer* customer;
	Feedback* feedbacks;
public:
	Grocery_Store();
	void Login(int _usertype);
	void Register(int _usertype);
	void showCustomers() const;
	void showManagers() const;
	~Grocery_Store();
};

//Implemetation of code outside

Grocery_Store::Grocery_Store()
{
	userType = 0;
	noAdmins = 0;
	noManagers = 0;
	noCustomers = 0;
	
	noFeedbacks = 0;
	admins = nullptr;
	manager = nullptr;
	customer = nullptr;
	feedbacks = nullptr;
}

void Grocery_Store::Register(int _usertype) {
	//admin registration Registration
	string cnic, name, password, contact, gender,location;
	if (_usertype==1)
	{
		Admin* temp_ad = nullptr;
		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic) || CheckCnicExisted<Admin>("admins.dat", cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter user name: ";
		getline(cin, name);
		cout << "Enter password: ";
		getline(cin, password);
		while (!ValidPassword(password))
		{
			cout << "Retry: ";
			getline(cin, password);
		}
		cout << "Enter Contact no: [03xxxxxxxxx] ";
		getline(cin, contact);
		temp_ad = new Admin[noAdmins];
		for (int i = 0; i < noAdmins; i++)
		{
			temp_ad[i] = admins[i];
		}
		delete[] admins;
		noAdmins++;
		admins = new Admin[noAdmins];
		for (int i = 0; i < noAdmins - 1; i++)
		{
			admins[i] = temp_ad[i];
		}
		delete[] temp_ad;
		admins[noAdmins - 1].setCnic(cnic);
		admins[noAdmins - 1].setName(name);
		admins[noAdmins - 1].setPassword(password);
		admins[noAdmins - 1].setContactNumber(contact);
		if (Write("admins.dat", admins[noAdmins - 1]))
		{
			cout << "MESSAGE: Admin Registered successfully!" << endl;
		}
		else
		{
			cout << "MESSAGE: Registration Failed!" << endl;
		}
	}

	else if (_usertype == 2)
	{
		string location, email, loction;
		Manager* temp_mg = nullptr;

		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic) || CheckCnicExisted<Manager>("manager.dat", cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter user name: ";
		getline(cin, name);
		cout << "Enter your email address: ";
		getline(cin, email);
		while (!ValidEmail(email) || CheckEmailExisted<Manager>("manager.dat", email))
		{
			cout << "Retry: ";
			getline(cin, email);
		}
		cout << "Enter password: ";
		getline(cin, password);
		while (!ValidPassword(password))
		{
			cout << "Retry: ";
			getline(cin, password);
		}
		cout << "Enter Contact no: [03xxxxxxxxx] ";
		getline(cin, contact);
		cout << "Enter Gender: [Male, Female, Others] ";
		getline(cin, gender);
		cout << "\n<< Adding Details >> " << endl;
		cout << "Enter your location: ";
		getline(cin, location);

		temp_mg = new Manager[noManagers];
		for (int i = 0; i < noManagers; i++)
			temp_mg[i] = manager[i];
		delete[] manager;
		noManagers++;
		manager = new Manager[noManagers];
		for (int i = 0; i < noManagers - 1; i++)
			manager[i] = temp_mg[i];
		delete[] temp_mg;

		manager[noManagers - 1].setCnic(cnic);
		manager[noManagers - 1].setEmail(email);
		manager[noManagers - 1].setName(name);
		manager[noManagers - 1].setPassword(password);
		manager[noManagers - 1].setContactNumber(contact);
		manager[noManagers - 1].setLocation(location);

		if (Write("manager.dat", manager[noManagers - 1]))
		{
			cout << "MESSAGE: Manager Registered successfully!" << endl;
		}
		else
		{
			cout << "MESSAGE: Registration Failed!" << endl;
		}
	}
	else if (_usertype == 3) 
	{
		Customer* temp_cus = nullptr;
		cin.ignore();
		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic) || CheckCnicExisted<Customer>("customers.dat", cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter user name: ";
		getline(cin, name);
		cout << "Enter password: ";
		getline(cin, password);
		while (!ValidPassword(password))
		{
			cout << "Retry: ";
			getline(cin, password);
		}
		cout << "Enter Contact no: [03xxxxxxxxx] ";
		getline(cin, contact);
		cout << "Enter your Location:";
		getline(cin, location);
		temp_cus = new Customer[noCustomers];
		for (int i = 0; i < noCustomers; i++)
		{
			temp_cus[i] = customer[i];
		}
		delete[] customer;
		noCustomers++;
		customer = new Customer[noCustomers];
		for (int i = 0; i < noCustomers - 1; i++)
		{
			customer[i] = temp_cus[i];
		}
		delete[] temp_cus;
		customer[noCustomers - 1].setCnic(cnic);
		customer[noCustomers - 1].setName(name);
		customer[noCustomers - 1].setPassword(password);
		customer[noCustomers - 1].setLocation(location);
		if (Write("customers.dat", customer[noCustomers - 1]))
		{
			cout << "MESSAGE: Customer Registered successfully!" << endl;
		}
		else
		{
			cout << "MESSAGE: Registration Failed!" << endl;
		}
	}
	
}

void Grocery_Store::Login(int _usertype) {
	
	/*in.open("noFeedbacks.dat", ios::binary);
	in.read((char*)&noFeedbacks, sizeof(noFeedbacks));
	in.close();*/
	/*in.open("feedbacks.dat", ios::binary);
	feedbacks = new Feedback[noFeedbacks];
	in.read((char*)&feedbacks[0], sizeof(Feedback) * noFeedbacks);
	in.close();*/
	int choice = 1, id = 0;
	string cnic = "", email = "", password = "";
	cin.ignore();
	switch (_usertype)
	{
	case 1:
		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter password: ";
		getline(cin, password);
		if (VerifyLogin<Admin>("admins.dat", cnic, password))
		{
			system("CLS");
			Admin adm;
			adm = getObject<Admin>("admins.dat", cnic, password);
			adminMenu();
			userType = 1;
			while (userType == 1)
			{
				cout << "Enter your choice: ";
				cin >> choice;
				if (choice == 1)
				{
					Manager obj;
					ifstream infile;
					infile.open("manager.dat", ios::binary);
					while (infile.read((char*)&obj, sizeof(obj))) {
						obj.displayUser();
					}
					infile.close();
				}
				else if (choice == 2)
				{
					Customer obj;
					ifstream infile;
					infile.open("customers.dat", ios::binary);
					while (infile.read((char*)&obj, sizeof(obj))) {
						obj.displayUser();
					}
					infile.close();
				}

				else if (choice == 3)
				{
					Product_Catalog obj;
					//cout << "Asdf:" << endl;
					int num;
					cout << "Enter number of products you want to add: ";
					cin >> num;
					
					obj.addProduct(num);
					
			
					
					/*Feedback obj;
					ifstream infile;
					infile.open("feedbacks.dat", ios::binary);
					while (infile.read((char*)&obj, sizeof(obj))) {
						cout << obj << endl;
					}
					infile.close();*/
				}
				else if (choice == 4) 
				{
					Product_Catalog obj;
					string str;
					cout << "Enter product name to remove:";
					cin >> str;
					
					if (obj.removeProduct(str))
					{
						cout << "Product removed successfully!" << endl;
					}
					else
					{
						cout << "Product not found!" << endl;
					}
					
				}
				else if (choice == 5)
				{
					Product_Catalog obj;
					cout << "Product Catalog:" << endl;
					obj.display_catalog();
				}
				
				else if (choice == 6)
				{
					userType = 0;
				}
			}
		}
		else
		{
			Sleep(2000);
		}
		break;

	case 2:
		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter password: ";
		getline(cin, password);
		if (VerifyLogin<Manager>("manager.dat", cnic, password))
		{
			system("CLS");
			Manager mg;
			//mg = getObject<Manager>("manager.dat", cnic, password);
			mg = getManager(cnic, password);
			cout << "Manager logged in successfully!" << endl;
			ManagerMenu();
			userType = 2;
			while (_usertype==2) 
			{
				cout << "Enter your choice: ";
				cin >> choice;
				if (choice == 1) 
				{
					Inventory inv;
					string product;
					cout << "Enter name of Item you want to update: ";
					cin >> product;
					inv.updateItmes(product);
				}
				else if (choice == 2) 
				{
					Inventory inv;
					int num;
					cout << "Enter the number of Items to add:";
					cin >> num;
					inv.addItems(num);
				}
				else if (choice == 3)
				{
					Inventory inv;
					string str;
					cout << "Enter product name to remove:";
					cin >> str;

					if (inv.removeItems(str))
					{
						cout << "Item removed successfully!" << endl;
					}
					else
					{
						cout << "Item not found!" << endl;
					}
				}
				else if (choice == 4)
				{
					Inventory inv;
					string str;
					cout << "Enter the Items name:";
					cin >> str;
					inv.searchItems(str);
				}
				else if (choice == 5) 
				{
					Inventory inv;
					inv.display_Invent();
				}
				else if (choice == 6)
				{
					_usertype = 0;
				}
			}
		}
		else
		{
		    Sleep(3000);
		}
		break;

	case 3:
		cout << "Enter your cnic number: [without dashes] ";
		getline(cin, cnic);
		while (!ValidCnic(cnic))
		{
			cout << "Retry: ";
			getline(cin, cnic);
		}
		cout << "Enter password: ";
		getline(cin, password);
		if (VerifyLogin<Customer>("customers.dat", cnic, password))
		{
			system("CLS");
			Customer doc;
			doc = getObject<Customer>("customers.dat", cnic, password);
			CustomerMenu();
			userType = 3;
			while (_usertype == 3)
			{
				cout << "Enter a choice:";
				cin >> choice;
				if (choice == 1)
				{
					Customer c;
					string name;
					cout << "Enter the name of the product:";
					cin >> name;
					c.searchProduct(name);
				}
				else if (choice == 2)
				{
					Customer c;
					bool x{};
					c.checkCart(x);
				}
				else if (choice == 3) 
				{
					Customer c;
					c.totalBills();
				}
				else if (choice == 4)
				{
					Customer c;
					c.feedback();
				}
				else if (choice == 5) {
					_usertype = 0;
				}
			}
		}
		else
		{
			Sleep(2000);
		}
		break;
	default:
		cout << "MESSAGE: Enter a valid choice!" << endl;
		Sleep(2000);
		break;
	}
}
Grocery_Store::~Grocery_Store()
{
	delete[] admins;
	delete[] manager;
	delete[] customer;
}