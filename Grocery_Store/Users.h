
#define USER_H
#include <iostream>
#include <cstring>
#include <fstream>

#include "Feedback.h"
#include "Inventory.h"
#include "HelpingFunctions.h"

using namespace std;

class User {
protected:
	int id;
	char cnic[14];
	char name[50];
	char password[50];
	char contact[13];
	char gender[50];
	bool isLoggedIn;
public:
	User(int _id = 1, string _cnic = "0000000000000", string _name = "Unknown", string _pass = "12345Aa@", string _contact = "03000000000", string _g = "Male");
	bool Login(string _n, string _p);
	void setId(int _id);
	void setName(string _name);
	void setPassword(string _pass);
	void setCnic(string _cnic);
	void setGender(string _g);
	void setContactNumber(string _c);
	void setLoginState(bool login);
	void SetGender(string _g);
	int getId();
	string getName();
	string getPassword();
	string getCnic();
	string getGender();
	void Logout();
	void displayUser() const;
	~User(){}
};

class Admin : public User {
public:
	Admin(int _id = 1, string _cnic = "0000000000000", string _name = "Admin", string _pass = "Admin@123");
	//Product_Catalog* product;
	~Admin();
};


class Manager : public User {
protected:
	char email[50];
	char location[50];
	char contact[13];
	Inventory* inventory;
	
public:
	//Schedule* schedules;
	Manager(int _id = 1, string _cnic = "0000000000000",string _email = "null",  string _name = "Manager", string _pass = "Manager@1", string _loc = "Islamabad",  string _contact = "03xxxxxxxxx");
	void setEmail(string _email);
	void setInventory(Inventory* inv);
	void setDetails();
	void setContact(string _contact);
	void setLocation(string _loc);
	string getLocation();
	string getEmail();
	string getContact();
	void displayUser() const;
	~Manager();
};

class Customer: public User{
protected:
	char location[50];
	//double amount;
public:
	Customer( int _id=1,string _cnic = "0000000000000", string _name = "Patient", string _pass = "customer@1", string _loc = "Islamabad");
	void setLocation(string _loc);
	void searchProduct(string name);
	void AddtoCart();
	bool checkCart(bool _cart);
	void getFeedback();
	void totalBills();
	string getLocation();
	void feedback();
	bool PaymentCheck(int check_pay);
	bool pay(int total_bill);
	void displayUser() const;
	~Customer();
};

//outline implementation of code outside

//-----------User can be anyone----------
User::User(int _id, string _cnic , string _name, string _pass, string _contact, string _g)
{
	id = _id;
	strcpy_s(name, _name.c_str());
	strcpy_s(cnic, _cnic.c_str());
	strcpy_s(password, _pass.c_str());
	strcpy_s(contact, _contact.c_str());
	strcpy_s(gender, _g.c_str());
	isLoggedIn = false;
}
bool User:: Login(string _n, string _p) 
{
	if (strcmp(_n.c_str(), cnic) == 0 && strcmp(_p.c_str(), password) == 0)
	{
		isLoggedIn = true;
		return 1;
	}
	else {
		return 0;
	}
}
void User:: setId(int _id) {
	id = _id;
}
void User:: setName(string _name) {
	strcpy_s(name, _name.c_str());
}
void User:: setPassword(string _pass) {
	strcpy_s(password, _pass.c_str());
}
void User::setCnic(string _cnic) {
	strcpy_s(cnic, _cnic.c_str());
}
void User::setContactNumber(string _c)
{
	strcpy_s(contact, _c.c_str());
}
void User::setGender(string _g) {
	strcpy_s(gender, _g.c_str());
}

int User:: getId() {
	return id;
}
string User::getName() {
	return name;
}
string User:: getPassword() {
	return password;
}
string User:: getCnic() {
	return cnic;
}
string User::getGender() {
	return gender;
}
void User::setLoginState(bool login) {
	isLoggedIn = login;
}
void User:: Logout() {
	isLoggedIn = false;
}

//-----------------Random Users were Displayed here--------------------------
void User::displayUser() const 
{
	cout << "\t\t\t _____________________________________________________________________________________" << endl;
	cout << "\t\t\t|            Name: " << name
		<< "\n\t\t\t|            Id = " << id;
	cout << "\n\t\t\t _____________________________________________________________________________________" << endl;

}


//Admin starts here----------------
Admin::Admin(int _id, string _cnic, string _name, string _pass) :User(_id, _cnic, _name, _pass) {}

Admin::~Admin()
{

}


//---------------Managers statrs here---------------
Manager::Manager(int _id, string _cnic, string _name, string _pass , string _email , string _loc,string _contact) :User(_id, _cnic, _name, _pass)
{
	inventory = nullptr;
	strcpy_s(location, _loc.c_str());
	strcpy_s(email, _email.c_str());
	strcpy_s(contact, _contact.c_str());
	id = _id;

}
void Manager::setLocation(string _loc) {
	strcpy_s(location, _loc.c_str());
}
void Manager::setEmail(string _email) {
	strcpy_s(email, _email.c_str());
}

//void Manager:: setInventory(Inventory* inv) {
//	cout << "LOve";
//}

void Manager::setContact(string _contact) {
	strcpy_s(contact, _contact.c_str());
}
string Manager::getLocation() {
	return location;
}
	
string Manager::getEmail() {
	return email;
}


void Manager::displayUser() const {
	
	cout << "\t\t\t _____________________________________________________________________________________" << endl;
	cout << "\t\t\t|     Manager Name: " << name
		 << "\n\t\t\t|            Id = " << id;
	cout << "\n\t\t\t|    Manger Location: " << location;
	cout << "\n\t\t\t _____________________________________________________________________________________" << endl;

}

Manager::~Manager() {
	//delete[] inventorty;
}

//------Customer Starts here---------------
Customer::Customer(int _id, string _cnic, string _name, string _pass, string _loc) :User(_id, _cnic, _name, _pass)
{
	strcpy_s(location, _loc.c_str());
	//amount = 0.0;
}
void Customer:: setLocation(string _loc) {
	strcpy_s(location, _loc.c_str());
}

void Customer::searchProduct(string name)
{
	ifstream fin;
	fin.open("Inventory.dat", ios::binary);
	Inventory* inv;
	inv = new Inventory;
	while (fin.read((char*)&inv, sizeof(inv)))
	{
	    if (inv->getName() == name)
		{
			cout << "Name:" << inv->getName() << endl;
			cout << "Quantity:" << inv->getQuantity() << endl;
			cout << "Units:" << inv->getUnits() << endl;
		}
		else
		{
				cout << "Item not found" << endl;
		}
	}
	fin.close();

}
	
bool Customer::checkCart(bool _cart)
{
	
	if (_cart == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
void Customer::totalBills() {
	int total = 0;
	
	/*if (cart.size() > 0)
	{
		for (int i = 0; i < cart.size(); i++)
		{
			total += cart[i].getPrice();
		}
		cout << "Total Bill: " << total << endl;
	}
	else
	{
		cout << "Cart is empty" << endl;
	}*/
}

void Customer::feedback() {
	string feedback;
	cout << "Enter your feedback: ";
	cin >> feedback;
	ofstream fout;
	fout.open("Feedback.dat", ios::binary | ios::app);
	fout.write((char*)&feedback, sizeof(feedback));
	fout.close();
	fout << feedback << endl;
	fout.close();
}

string Customer::getLocation() {
	return location;
}

bool Customer:: PaymentCheck(int check_pay) {
	return 1;
}
bool Customer::pay(int total_bill) {
	return 1;
}

void Customer::displayUser() const {
	cout << "\t\t|            Name: " << name
		<< "\n\t\t|            Id = " << id
		<< "\n\t\t|            Address: " << location
		<< "\n\t\t|            Contact: " << contact
		<< "\n\t\t|            Gender = " << gender;
	cout << "\n\t\t _____________________________________________________________________________________" << endl;

}

Customer :: ~Customer() {

}