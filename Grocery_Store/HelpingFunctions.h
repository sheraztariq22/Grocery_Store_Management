#pragma once
#ifndef HELPF_H
#define HELPF_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Helping functions
// Function to check for valid password entry
bool ValidPassword(string _pass) 
{
	int len = _pass.length(); 
	bool hasCaptial = false, hasSmall = false, hasSpecial = false, hasNumber = false;
	if (len < 8)
	{
		cout << "MESSAGE: Password must contain at least 8 characters !" << endl;
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (_pass[i] >= 48 && _pass[i] <= 57)
		{
			hasNumber = true;
		}
		if (_pass[i] >= 97 && _pass[i] <= 122)
		{
			hasSmall = true;
		}
		if (_pass[i] >= 65 && _pass[i] <= 90)
		{
			hasCaptial = true;
		}
		if (_pass[i] >= 21 && _pass[i] <= 47 || _pass[i] >= 58 && _pass[i] <= 64 || _pass[i] >= 91 && _pass[i] <= 96 || _pass[i] >= 123 && _pass[i] <= 126)
		{
			hasSpecial = true;
		}
	}
	if (hasCaptial == 0)
	{
		cout << "MESSAGE: Password must contain at least 1 capital letter !" << endl;
	}
	if (hasSmall == 0)
	{
		cout << "MESSAGE: Password must contain at least 1 small letter !" << endl;
	}
	if (hasSpecial == 0)
	{
		cout << "MESSAGE: Password must contain at least 1 special letter !" << endl;
	}
	if (hasNumber == 0)
	{
		cout << "MESSAGE: Password must contain at least 1 number !" << endl;
	}
	if (hasCaptial && hasSmall && hasSpecial && hasNumber)
	{
		return 1;
	}
	else {
		return 0;
	}
}
// Function to check for valid Cnic entry
bool ValidCnic(string _cnic) {
	int len = _cnic.length();
	if (len < 13 || len > 13)
	{
		cout << "MESSAGE: The Length of cnic must be 13 digits!" << endl;
		return false;
	}
	else {
		for (int i = 0; i < 13; i++)
		{
			if (_cnic[i] < 48 || _cnic[i] > 57)
			{
				cout << "MESSAGE: Invalid cnic entered!" << endl;
				return false;
			}
		}
		return true;
	}
}
// Function to check validity of email
bool ValidEmail(string _email) {
	bool hasAt = false, hasDot = false;
	for (int i = 0; i < _email.length(); i++)
	{
		if (hasAt && _email[i] == 64)
			hasAt = false;
		if (_email[i] == 64)
			hasAt = true;
		if (hasAt && _email[i] == 46)
			hasDot = true;
	}
	if (hasAt && hasDot)
	{
		return 1;
	}
	else {
		cout << "MESSAGE: wrong email format, correct format is abc@domain.xyz" << endl;
		return 0;
	}
}
// Function to check if cnic already exists
template < typename T>
bool CheckCnicExisted(string path, string _cnic) {
	T obj{};
	ifstream infile;
	infile.open(path, ios::binary | ios::in);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (strcmp(_cnic.c_str(), obj.getCnic().c_str()) == 0)
		{
			cout << "MESSAGE: This cnic is already registered!" << endl;
			infile.close();
			return 1;
		}
	}
	infile.close();
	return 0;
}
template <typename T>
bool CheckIdExisted(string path, int id) {
	T obj{};
	ifstream infile;
	infile.open(path, ios::binary | ios::in);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (id == obj.getId())
		{
			cout << "MESSAGE: This Id is already in use, choose another unique id!" << endl;
			infile.close();
			return 1;
		}
	}
	infile.close();
	return 0;
}
template <typename T>
bool CheckEmailExisted(string path, string _email) {
	T obj{};
	ifstream infile;
	infile.open(path, ios::binary | ios::in);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (strcmp(_email.c_str(), obj.getEmail().c_str()) == 0)
		{
			cout << "MESSAGE: This email is already registered!" << endl;
			infile.close();
			return 1;
		}
	}
	infile.close();
	return 0;
}
// Function to write the objects into files (Binary File handling)
template <typename T>
bool Write(string path, T obj) {
	ofstream outfile;
	outfile.open(path, ios::binary | ios::app);
	outfile.write((char*)&obj, sizeof(obj));
	outfile.close();
	if (!outfile.good())
	{
		return false;
	}
	else
	{
		return true;
	}
}
// Function to verify the credentials of user from files
template <typename T>
bool VerifyLogin(string path, string cnic, string pass)
{
	T obj{};
	ifstream infile;
	infile.open(path, ios::binary);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (obj.Login(cnic, pass))
		{
			infile.close();
			cout << "MESSAGE: Logged in!" << endl;
			return 1;
		}
	}
	cout << "MESSAGE: Wrong credentials!" << endl;
	infile.close();
	return 0;
}
// Function to read the required object from file
template <typename T>
T getObject(string path, string cnic, string pass)
{
	T obj{};
	ifstream infile;
	infile.open(path, ios::binary);
	while (infile.read((char*)&obj, sizeof(obj))) {
		if (obj.Login(cnic, pass))
		{
			infile.close();
			cout << "MESSAGE: Accessed!" << endl;
			return obj;
		}
	}
	infile.close();
	return obj;
}

#endif // !HELPF_H