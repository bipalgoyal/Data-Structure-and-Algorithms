#include "HashTable.h"
#include "Part.h"
#include "HTLL.h"
#include <iostream>

class Random {
public:
	int data;
	bool isUsed;
	Random() {
		data = 0;
		isUsed = false;
	}
};
void LabTenTaskThree();
void LabTenTaskFour();
void LabTenTaskFive();
int Hash(string inVal)
{
	int ASCII = 0;
	for (int i = 0; i < inVal.length(); i++)
	{
		ASCII += int(inVal[i]);
	}
	return ASCII % 100000;
}
int main() 
{
	//LabTenTaskThree();
	//LabTenTaskFour();
	LabTenTaskFive();
	return 0;
}

void LabTenTaskThree() {
	HashTable<Part> list;
	string SKU;
	string description;
	double price;
	string UOM;
	int quantityOnHand;
	int choice;
	int location;

	while (true)
	{
		std::cout << "Choose a function: " << endl
			<< "1. AddItem" << endl
			<< "2. GetItem" << endl
			<< "3. RemoveItem" << endl
			<< "4. Quit" << endl;
		std::cout << "Choice: ";
		cin >> choice;

		std::cout << "---------------------------------------------------------" << endl;

		Part* part = new Part();
		Part* temp;

		switch (choice)
		{
		case 1:
			//AddItem
			std::cout << "Enter the following information: " << endl;
			std::cout << "SKU: ";
			cin >> SKU;
			std::cout << "Description: ";
			cin.ignore();
			getline(cin, description);
			std::cout << "Price: ";
			cin >> price;
			std::cout << "Unit of Measure: ";
			cin >> UOM;
			std::cout << "Input Quantity on Hand (0-no, 1-yes)? ";
			cin >> quantityOnHand;
			if (quantityOnHand == 1)
			{
				std::cout << "Quantity on Hand: ";
				cin >> quantityOnHand;
				part = new Part(SKU, description, price, UOM, quantityOnHand);
				list.AddItem(part);
			}
			else
			{
				part = new Part(SKU, description, price, UOM);
				list.AddItem(part);
			}
			break;
		case 2:
			//GetItem
			std::cout << "Enter SKU: ";
			cin >> SKU;
			part = new Part(SKU);
			temp = list.GetItem(part);
			if (temp == nullptr)
			{
				std::cout << "Part not found." << endl;
			}
			else
			{
				part = temp;
				std::cout << "Following part found: " << endl;
				std::cout << part->GetPartInfo() << endl;
				std::cout << "Price: " << part->GetPrice() << endl;
			}
			break;
		case 3:
			//Remove Item
			std::cout << "Enter SKU: ";
			cin >> SKU;
			part = new Part(SKU);
			temp = list.RemoveItem(part);
			if (temp == nullptr)
			{
				std::cout << "Part not found." << endl;
			}
			else
			{
				part = temp;
				std::cout << "Following part removed: " << endl;
				std::cout << part->GetPartInfo() << endl;
				std::cout << "Price: " << part->GetPrice() << endl;
			}
			break;
		case 4:
			//Quit
			return;
		}
		std::cout << "---------------------------------------------------------" << endl;
	}
}

void LabTenTaskFour() {
	HTLL<Part> list;
	string SKU;
	string description;
	double price;
	string UOM;
	int quantityOnHand;
	int choice;
	int location;

	while (true)
	{
		std::cout << "Choose a function: " << endl
			<< "1. AddItem" << endl
			<< "2. GetItem" << endl
			<< "3. RemoveItem" << endl
			<< "4. Quit" << endl;
		std::cout << "Choice: ";
		cin >> choice;

		std::cout << "---------------------------------------------------------" << endl;

		Part part;
		Part temp;

		switch (choice)
		{
		case 1:
			//AddItem
			std::cout << "Enter the following information: " << endl;
			std::cout << "SKU: ";
			cin >> SKU;
			std::cout << "Description: ";
			cin.ignore();
			getline(cin, description);
			std::cout << "Price: ";
			cin >> price;
			std::cout << "Unit of Measure: ";
			cin >> UOM;
			std::cout << "Input Quantity on Hand (0-no, 1-yes)? ";
			cin >> quantityOnHand;
			if (quantityOnHand == 1)
			{
				std::cout << "Quantity on Hand: ";
				cin >> quantityOnHand;
				part = Part(SKU, description, price, UOM, quantityOnHand);
				list.AddItem(part);
			}
			else
			{
				part = Part(SKU, description, price, UOM);
				list.AddItem(part);
			}
			break;
		case 2:
			//GetItem
			std::cout << "Enter SKU: ";
			cin >> SKU;
			part = Part(SKU);
			try {
				temp = list.GetItem(part);
				part = temp;
				std::cout << "Following part found: " << endl;
				std::cout << part.GetPartInfo() << endl;
				std::cout << "Price: " << part.GetPrice() << endl;
			}
			catch (HTLL<Part>::NotFound) {
				std::cout << "Part not found." << endl;
			}
			break;
		case 3:
			//Remove Item
			std::cout << "Enter SKU: ";
			cin >> SKU;
			part = Part(SKU);
			try {
				temp = list.RemoveItem(part);
				part = temp;
				std::cout << "Following part removed: " << endl;
				std::cout << part.GetPartInfo() << endl;
				std::cout << "Price: " << part.GetPrice() << endl;
			}
			catch (HTLL<Part>::NotFound) {
				std::cout << "Part not found." << endl;
			}
			break;
		case 4:
			//Quit
			return;
		}
		std::cout << "---------------------------------------------------------" << endl;
	}
}

void LabTenTaskFive()
{
	//Change CAP to 50, 150, 200, and 250 for task 5
	const int CAP = 250;

	srand(95710);
	HashTable<Part> hashTable(CAP);
	HTLL<Part> HTLL(CAP);
	Random randVal[CAP];
	for (int i = 0; i < CAP; i++) {
		randVal[i].data = i;
		randVal[i].isUsed = false;
	}
	int i = 0;
	while(i<CAP) {
		int randomSku = rand() % CAP; //keeping it between 1 & 50 to increase chances of collission
		if (!randVal[randomSku].isUsed) {
			i++;
			hashTable.AddItem(new Part(to_string(randomSku)));
			HTLL.AddItem(Part(to_string(randomSku)));

			//Use to print your hashTable (make values public in HashTable.h
			/*
			for (int j = 0; j < CAP; j++) {
				if (hashTable.values[j].item != nullptr)
					cout << hashTable.values[j].item->GetSKU() << "|";
				else
					cout << "|";
			}
			cout << endl;
			*/

			Part* ret = hashTable.GetItem(new Part(to_string(randomSku)));
			Part retval = HTLL.GetItem(Part(to_string(randomSku)));
			randVal[randomSku].isUsed = true;
		}
	}
	cout << "Add Efficiency for HashTable: " << hashTable.addEfficiency << endl;
	cout << "Find Efficiency for HashTable: " << hashTable.findEfficiency << endl;
	cout << "Add Efficiency for HTLL: " << HTLL.addEfficiency << endl;
	cout << "Find Efficiency for HashTable: " << hashTable.findEfficiency << endl;
}