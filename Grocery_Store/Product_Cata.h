#pragma once

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

class Product_Catalog {
private:
	char name[50];
	double price;
public:
	Product_Catalog() {
		name[50] = NULL;
		price = 0;

	}
	Product_Catalog(string _name, double _price);
	void setPrice(double _price);
	void setName(string _name);
	string getName();
	double getPrice();
	void addProduct(int num);
	bool removeProduct(string name);
	void display_catalog();
};

Product_Catalog::Product_Catalog(string _nam, double _price) {

	strcpy_s(name, _nam.c_str());

	price = _price;
}
void Product_Catalog::setName(string _name)
{
	cout << "Enter the name of the product to add in Catalog:";
	cin >> _name;
	strcpy_s(name, _name.c_str());
}


void Product_Catalog::setPrice(double _price)
{
	cout << "Enter the price of the product:";
	cin >> price;
}
string Product_Catalog::getName()
{
	return name;
}


double Product_Catalog::getPrice()
{
	return price;
}
int number;
void Product_Catalog::addProduct(int num)
{
	string n;
	double pr;
	Product_Catalog* obj;
	obj = new Product_Catalog[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Enter the name of the product to add in Catalog:";
		cin >> n;
		cout << "Enter the price of the produc:";
		cin >> pr;
		obj[i].setName(n);
		obj[i].setPrice(pr);
	}
	ofstream fout;
	fout.open("Product_Catalog.bin", ios::binary | ios::app);
	for (int i = 0; i < num; i++)
	{
		fout.write((char*)&obj[i], sizeof(obj[i]));
	}
	fout.close();

}

bool Product_Catalog::removeProduct(string name)
{

	Product_Catalog obj;
	ifstream fin;
	fin.open("Product_Catalog.bin", ios::binary);
	ofstream fout;
	fout.open("temp.bin", ios::binary);
	bool x{};
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getName() != name)
		{
			fout.write((char*)&obj, sizeof(obj));
			x= false;
		}
		else {
			x = true;
		}
	}
	fin.close();
	fout.close();
	remove("Product_Catalog.bin");
	rename("temp.bin", "Product_Catalog.bin");
	return x;
}
    



void Product_Catalog::display_catalog()
{
	Product_Catalog obj;
	ifstream fin;
	fin.open("Product_Catalog.bin", ios::binary);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		cout << "Name of the product:" << obj.getName() << endl;
		cout << "Price of the product:" << obj.getPrice() << endl;
	}
	fin.close();

}
