#pragma once
class Inventory{
private:
	double quantity;
	int units;
	char name[50];
public:
	Inventory();
	Inventory(string _name,double _quantity, int _units);
	void setName(string _name);
	string getName();
	void setQuantity(double _quantity);
	void setUnits(int _units);
	double getQuantity();
	int getUnits();
	void addItems(int num);
	bool removeItems(string name);
	void searchItems(string name);
	void updateItmes(string name);
	void display_Invent();
};

Inventory::Inventory()
{
	quantity = 0;
	units = 0;
}
Inventory::Inventory(string _name,double _quantity, int _units)
{
	quantity = _quantity;
	units = _units;
}

void Inventory::setQuantity(double _quantity)
{
	cout << "Enter the quantity of the product to add in Inventory:";
	cin >> _quantity;
	quantity = _quantity;
}

void Inventory::setUnits(int _units)
{
	cout << "Enter the units of the product to add in Inventory:";
	cin >> _units;
	units = _units;
}
void Inventory::setName(string _name)
{
	cout << "Enter the name of the product to add in Inventory:";
	cin >> _name;
	strcpy_s(name, _name.c_str());
}

string Inventory::getName()
{
	return name;
}

double Inventory::getQuantity()
{
	return quantity;
}

int Inventory::getUnits()
{
	return units;
}

void Inventory::updateItmes(string name)
{
	int items;
	cout << "Enter the number of items to update:";
	cin >> items;
	Inventory* inv;
	inv = new Inventory[items];
	for (int i = 0; i < items; i++) 
	{
		cout << "Enter the units of products to update:";
		cin >> units;
		cout << "Enter the quantity of the product to update:";
		cin >> quantity;
		inv[i].setUnits(units);
		inv[i].setQuantity(quantity);
	}
	ofstream fout;
	fout.open("Inventory.dat", ios::binary | ios::app);
	for (int i = 0; i < items; i++)
	{
		fout.write((char*)&inv[i], sizeof(inv[i]));
	}
	fout.close();
}

void Inventory::addItems(int num)
{
	string n;
	double q;
	Inventory* inv;
	inv = new Inventory[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Enter the name of Item to add:";
		cin >> n;
		cout << "Enter the quantity of the product to add:";
		cin >> q;
		inv[i].setName(n);
		inv[i].setQuantity(q);
		
	}
	ofstream fout;
	fout.open("Inventory.dat", ios::binary | ios::app);
	for (int i = 0; i < num; i++)
	{
		fout.write((char*)&inv[i], sizeof(inv[i]));
	}
	fout.close();
}

bool Inventory::removeItems(string name)
{
	ifstream fin;
	fin.open("Inventory.dat", ios::binary);
	ofstream fout;
	fout.open("temp.dat", ios::binary);
	Inventory* inv;
	inv = new Inventory;
	bool x{};
	while (fin.read((char*)&inv, sizeof(inv)))
	{
		if (inv->getName() != name)
		{
			fout.write((char*)&inv, sizeof(inv));
			x = false;
		}
		else
		{
			x = true;
		}
	}
	fin.close();
	fout.close();
	remove("Inventory.dat");
	rename("temp.dat", "Inventory.dat");
	return x;
}

void Inventory::searchItems(string name)
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

void Inventory::display_Invent()
{
	ifstream fin;
	fin.open("Inventory.dat", ios::binary);
	Inventory* inv;
	inv = new Inventory;
	while (fin.read((char*)&inv, sizeof(inv)))
	{
		cout << "Name:" << inv->getName() << endl;
		cout << "Quantity:" << inv->getQuantity() << endl;
		cout << "Units:" << inv->getUnits() << endl;
	}
	fin.close();
}

