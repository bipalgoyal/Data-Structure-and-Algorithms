#include "OrderedList.h"
#include <iostream>
using namespace std;

int main() {
	OrderedList<int> list;
	list.AddItem(3);
	list.AddItem(4);
	list.AddItem(5);
	list.AddItem(1);
	list.AddItem(1);
	list.AddItem(2);
	list.AddItem(3);
	list.AddItem(8);
	cout << list.RemoveItem(1) <<endl;
	cout << list.RemoveItem(8) <<endl;
	cout << list.RemoveItem(2) <<endl;
	cout << list.RemoveItem(1) <<endl;
	return 0;
}