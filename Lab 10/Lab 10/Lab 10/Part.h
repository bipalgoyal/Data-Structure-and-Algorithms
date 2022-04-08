#pragma once
#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
using namespace std;

class Part
{
private:
	string SKU;
	string description;
	double price;
	string UOM;
	int quantityOnHand;
	int leadTime;
public:
	Part();
	Part(string);
	Part(string, string, double, string, int = 0);
	string GetPartInfo();
	double GetPrice();
	string GetSKU();
	bool InStock();
	bool Available(int, int, int);
	void DisplayPart();

	bool operator >(Part item);
	bool operator <(Part item);
	bool operator ==(Part item);
	bool operator !=(Part item);
	operator string();
};

#endif 

