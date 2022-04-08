#include "Part.h"
#include <ctime>

Part::Part()
{
	SKU = "";
	description = "";
	price = 0;
	UOM = "";
	quantityOnHand = 0;
}

Part::Part(string SKU)
{
	this->SKU = SKU;
	description = "";
	price = 0;
	UOM = "";
	quantityOnHand = 0;
}

Part::Part(string SKU, string description, double price, string UOM, int quantityOnHand)
{
	leadTime = 3;
	this->SKU = SKU;
	this->description = description;
	this->price = price;
	this->UOM = UOM;
	this->quantityOnHand = quantityOnHand;
}

void Part::DisplayPart() {
	cout << GetPartInfo() << endl;
	cout << "Price: " << GetPrice() << endl;
}
string Part::GetPartInfo()
{
	return "SKU: " + SKU + " - Description: " + description;
}
double Part::GetPrice()
{
	return price;
}
bool Part::InStock()
{
	if (quantityOnHand > 0)
	{
		return true;
	}
	return false;
}
bool Part::Available(int year, int month, int day)
{
	if (InStock())
	{
		return true;
	}
	struct tm now;
	time_t t = time(0);
	localtime_s(&now, &t);
	int currYear = now.tm_year + 1900;
	int currMonth = now.tm_mon + 1;
	int currDay = now.tm_mday;

	currDay = currDay + leadTime;

	return year > currYear || (year == currYear && month > currMonth) || (year == currYear && month == currMonth && day > currDay);
}

bool Part::operator>(Part item)
{
	return this->SKU > item.SKU;
}

bool Part::operator<(Part item)
{
	return this->SKU < item.SKU;
}

bool Part::operator==(Part item)
{
	return this->SKU == item.SKU;
}

bool Part::operator!=(Part item)
{
	return this->SKU != item.GetSKU();
}

string Part::GetSKU() {
	return this->SKU;
}

Part::operator string() {
	return this->SKU;
}