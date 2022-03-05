#include "OrderedList.h"
#include "AddIntoMiddleOL.h"
#include "DerivedSecond.h"
#include <iostream>
using namespace std;

int main() {
	try {
		DerivedSecond<int> list;
		list.items[0] = new int(0);
		list.items[1] = new int(1);
		list.items[2] = new int(2);
		list.items[3] = new int(3);
		list.items[4] = new int(5);
		list.items[5] = new int(6);
		list.items[7] = new int(8);
		list.items[8] = new int(9);
		list.AddItem(4);
		/*list.items[0] = new int(0);
		list.items[2] = new int(1);
		list.items[3] = new int(3);
		list.items[4] = new int(4);
		list.items[5] = new int(5);
		list.AddItem(2);*/
		/*list.items[0] = new int(0);
		list.items[1] = new int(1);
		list.items[5] = new int(5);
		list.AddItem(2);
		list.AddItem(3);*/
		/* cout << list.RemoveItem(2) << endl;
		cout << list.RemoveItem(4) << endl;
		cout << list.RemoveItem(5) << endl;
		cout << list.RemoveItem(9) << endl;*/
		cout << "Some test";
	}
	catch (DerivedSecond<int>::NotFoundOrderedListException) {
		cout << "Not found";
	}
	catch (DerivedSecond<int>::EmptyOrderedListException) {
		cout << "Empty";
	}
	/*AddIntoMiddleOL<int> list;
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
	list.AddItem(45);*/
	return 0;
}