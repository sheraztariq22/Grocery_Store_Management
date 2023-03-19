
#include <iostream>
#include "Users.h"
using namespace std;

class Payment {
private:
	double amount;
public:
	Payment(double _amount = 0)
	{
		amount = _amount;
	}
	void setAmount(double _amount)
	{
		amount = _amount;
	}
	double getAmount() 
	{
		return amount;
	}
	void makePayment()
	{
		cout << "Payment of " << amount << " has been made." << endl;
	}
};

class BankPayment : public Payment {
private:
	string bankName;
	string accountNumber;
public:
	BankPayment(string _bankName = "NULL", string _accountNumber = "NULL", double _amount = 0) : Payment(_amount) {
		bankName = _bankName;
		accountNumber = _accountNumber;
	}
	void setBankName(string _bankName) {
		bankName = _bankName;
	}
	void setAccountNumber(string _accountNumber) {
		accountNumber = _accountNumber;
	}
	string getBankName() {
		return bankName;
	}
	string getAccountNumber() {
		return accountNumber;
	}
	void makePayment() {
		cout << "Payment of " << getAmount() << " has been made to " << bankName << " through account number " << accountNumber << endl;
	}
};

class CreditCardPayment : public Payment {

private:
	char cardType[16];
	char cardNumber[16];
	char expiryDate[16];
public:
	CreditCardPayment(string _cardType = "NULL", string _cardNumber = "NULL", string _expiryDate = "NULL", double _amount = 0) : Payment(_amount) {
		strcpy_s(cardType, _cardType.c_str());
		strcpy_s(cardNumber, _cardNumber.c_str());
		strcpy_s(expiryDate, _expiryDate.c_str());
	}
	void setCardType(string _cardType)
	{
		strcpy_s(cardType, _cardType.c_str());
	}
	void setCardNumber(string _cardNumber)
	{
		strcpy_s(cardNumber, _cardNumber.c_str());
	}
	void setExpiryDate(string _expiryDate) 
	{
		strcpy_s(expiryDate, _expiryDate.c_str());
	}
	string getCardType()
	{
		return cardType;
	}
	string getCardNumber()
	{
		return cardNumber;
	}
	string getExpiryDate()
	{
		return expiryDate;
	}
	void makePayment()
	{
		cout << "Payment of " << getAmount() << " has been made to " << cardType << " through card number " << cardNumber << " with expiry date " << expiryDate << endl;
	}
};

void CashOnDelivery()
{
	string location;
	cout << "Enter the location of delivery: ";
	cin >> location;
	Customer customer;
	
	if (location == customer.getLocation())
	{
		cout << "The delivery charges in same city is 30" << endl;
	}
	else
	{
		cout << "The delivery charges on different city is 50" << endl;
	}
	
}