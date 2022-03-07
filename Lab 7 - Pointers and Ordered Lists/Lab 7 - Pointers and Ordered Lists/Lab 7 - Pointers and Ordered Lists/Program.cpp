#include "OrderedList.h"
#include "AddIntoMiddleOL.h"
#include "DerivedSecond.h"
#include <iostream>
using namespace std;
const int mainSize = 50;

struct Random {
	int val;
	bool isRemoved;
};
int main() {
	int addTotalForOrderedLists = 0, addTotalForAddIntoMiddle = 0, addTotalForDervicedSecond = 0;
	int removeTotalForOrderedLists = 0, removeTotalForAddIntoMiddle = 0, removeTotalForDervicedSecond = 0;
	for (int j = 0; j < 100; j++) {
		srand(time(0));
		OrderedList<int> orderedlist;
		AddIntoMiddleOL<int> addIntoMiddle;
		DerivedSecond<int> derivedSecond;
		Random arr[mainSize];

		//add random integers to your lists
		for (int i = 0; i < mainSize; i++) {
			int randomVal = rand() % 100 + 1;
			try {
				orderedlist.AddItem(randomVal);
			}
			catch (OrderedList<int>::FullOrderedListException) {
				//cout << "Full Ordered List" << endl;
			}
			try {
				addIntoMiddle.AddItem(randomVal);
			}
			catch (AddIntoMiddleOL<int>::FullOrderedListException) {
				//cout << "Full Middle List" << endl;
			}
			try {
				derivedSecond.AddItem(randomVal);
			}
			catch (DerivedSecond<int>::FullOrderedListException) {
				//cout << "Full Dervied Second List" << endl;
			}
			if (i < mainSize) {
				arr[i].val = randomVal;
				arr[i].isRemoved = false;
			}
		}

		//randomly remove integers from your lists
		bool allRemoved = false;
		while (!allRemoved) {
			int randomVal = rand() % mainSize;
			if (!arr[randomVal].isRemoved) {
				orderedlist.RemoveItem(arr[randomVal].val);
				addIntoMiddle.RemoveItem(arr[randomVal].val);
				derivedSecond.RemoveItem(arr[randomVal].val);
				arr[randomVal].isRemoved = true;
			}
			allRemoved = true;
			for (int i = 0; i < mainSize; i++) {
				if (!arr[i].isRemoved) {
					allRemoved = false;
					break;
				}
			}
		}

		addTotalForOrderedLists += orderedlist.getAddEfficiency();
		addTotalForAddIntoMiddle += addIntoMiddle.getAddEfficiency();
		addTotalForDervicedSecond += derivedSecond.getAddEfficiency();
		removeTotalForOrderedLists += orderedlist.getRemoveEfficiency();
		removeTotalForAddIntoMiddle += addIntoMiddle.getRemoveEfficiency();
		removeTotalForDervicedSecond += derivedSecond.getRemoveEfficiency();
	}
	std::cout << "--Efficiency for ordered lists-- " << endl;
	std::cout << "Efficiency for adding ordered lists: " << addTotalForOrderedLists << endl;
	std::cout << "Efficiency for removing ordered lists: " << removeTotalForOrderedLists << endl;
	std::cout << "Total Efficiency: " << addTotalForOrderedLists + removeTotalForOrderedLists << endl << endl;


	std::cout << "--Efficiency for add into middle lists--" << endl;
	std::cout << "Efficiency for adding add into middle lists: " << addTotalForAddIntoMiddle << endl;
	std::cout << "Efficiency for removing add into middle lists: " << removeTotalForAddIntoMiddle << endl;
	std::cout << "Total Efficiency: " << addTotalForAddIntoMiddle + removeTotalForAddIntoMiddle << endl << endl;


	std::cout << "--Efficiency for adding into empty spot lists--" << endl;
	std::cout << "Efficiency for adding adding into empty spot lists: " << addTotalForDervicedSecond << endl;
	std::cout << "Efficiency for removing adding into empty spot lists: " << removeTotalForDervicedSecond << endl;
	std::cout << "Total Efficiency: " << addTotalForDervicedSecond + removeTotalForDervicedSecond << endl << endl;
	return 0;
}