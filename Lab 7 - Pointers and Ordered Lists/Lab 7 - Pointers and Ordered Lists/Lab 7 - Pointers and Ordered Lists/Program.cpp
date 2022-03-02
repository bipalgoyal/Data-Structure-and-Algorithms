#include "OrderedList.h"
#include "AddIntoMiddleOL.h"
#include <iostream>
using namespace std;

int main() {
	AddIntoMiddleOL<int> list;
	list.AddItem(3);
	list.AddItem(4);
	list.AddItem(5);
	list.AddItem(1);
	list.AddItem(1);
	list.AddItem(2);
	list.AddItem(3);
	list.AddItem(8);
	list.AddItem(10);
	list.AddItem(6);
	list.AddItem(25);
	list.AddItem(14);
	list.AddItem(7);
	list.AddItem(45);
	return 0;
}