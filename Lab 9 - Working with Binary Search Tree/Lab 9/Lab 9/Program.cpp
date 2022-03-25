#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(3);
	tree.Insert(1);
	tree.Insert(2);
	cout << endl << endl << tree.Size();
	cout << endl << endl << tree.PrintTree();
	tree.Remove(3);
	cout << endl << endl << tree.Size();
	cout << endl << endl << tree.PrintTree();

	//tree.Insert(5);
	//tree.Insert(3);
	//tree.Insert(7);
	//tree.Insert(1);
	//tree.Insert(33);
	//tree.Insert(9);
	//tree.Insert(2);
	//tree.Insert(89);
	//cout << endl << endl << tree.Size();
	//cout << endl << endl << tree.PrintTree();
	//tree.Remove(33);
	//cout << endl << endl << tree.Size();
	//cout << endl << endl << tree.PrintTree();
	/*tree.EmptyTree();
	cout << endl << endl << tree.Size();
	cout << endl << endl << tree.PrintTree();*/
	return 0;
}