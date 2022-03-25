#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<string>
using namespace std;

template<typename T>
class node
{
public:
	T data;
	node* left, * right;
	node(T val) 
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
	~node() {
		left = nullptr;
		right = nullptr;
	}
};



template<class T>
class BinarySearchTree
{
public:
	node<T>* root;
public:
	class NotFound {};
	class AlreadyExists {};
	BinarySearchTree()
	{
		root = nullptr;
	}
	~BinarySearchTree()
	{
	}

	//balance tree
	void Insert(T val) 
	{
		if (this->Find(val) != nullptr)
			throw AlreadyExists();
		node<T>* n = new node<T>(val);
		if (root == nullptr) {
			root = n;
			return;
		}
		node<T>* curr = root;
		while ((curr->left != nullptr && curr->data >= val) || (curr->right != nullptr && curr->data < val)) {
			if (curr->data < val)
				curr = curr->right;
			else
				curr = curr->left;
		}
		if (curr->data < val) {
			curr->right = n;
		}
		else {
			curr->left = n;
		}
	};

	string PrintTree() {
		return InternalPrintTree(root);
	}
	string InternalPrintTree(node<T>* curr) {
		if (curr == nullptr) {
			return "";
		}
		string retval = "";
		retval += to_string(curr->data) + "(";
		if (curr->left != nullptr) {
			retval += to_string(curr->left->data);
		}
		retval += ",";
		if (curr->right != nullptr) {
			retval += to_string(curr->right->data);
		}
		retval += ") \n";
		retval += InternalPrintTree(curr->left);
		retval += InternalPrintTree(curr->right);
		return retval;
	}
	
	node<T>* Find(T key) {
		node<T>* curr = root;
		while (curr != nullptr && curr->data != key) {
			if (key < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		if (curr == nullptr) return nullptr;
		return curr ;
	};
	
	int Size() {
		return InternalSize(root);
	}
	int InternalSize(node<T>* curr) {
		if (curr == nullptr) {
			return 0;
		}
		int size = 1;
		size += InternalSize(curr->left);
		size += InternalSize(curr->right);
		return size;
	};

	node<T>* GetAllAscending() {
		
	};
	
	node<T>* GetAllDescending();
	
	void EmptyTree() {
		InternalEmptyTree(root);
		root = nullptr;
	};

	void InternalEmptyTree(node<T>* curr) {
		if (curr == nullptr) {
			return ;
		}
		node<T>* left = curr->left;
		node<T>* right = curr->right;
		delete curr;
		InternalEmptyTree(left);
		InternalEmptyTree(right);
	}
	/*
		leaf with 0 child - done
		node with 1 child - done
		node with 2 child - done
		root with no child
		root with 1 child
		root with 2 child
	*/
	//reblanacing left
	node<T>* Remove(T key) {
		if (this->Find(key) == nullptr) {
			throw NotFound();
		}
		node<T>* curr = root; 
		node<T>* prev = nullptr;
		while (curr != nullptr && curr->data != key) {
			prev = curr;
			if (key < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		//if root is the element to be removed
		if (curr == root) {
			//root with 0 child
			if (curr->left == nullptr && curr->right == nullptr) {
				root = nullptr;
				return curr;
			}
			//root with 1 child
			if (curr->left == nullptr || curr->right == nullptr) {
				if (curr->left != nullptr) {
					root = curr->left;
				}
				else {
					root = curr->right;
				}
				return curr;
			}
			//root with 2 child
			if (curr->left != nullptr && curr->right != nullptr) {
				node<T>* replace = curr->left;
				while (replace->right != nullptr) {
					replace = replace->right;
				}
				node<T>* retval = curr;
				curr->data = Remove(replace->data)->data;
				return retval;
			}
		}
		//for leaf
		if (curr->left == nullptr && curr->right == nullptr) {
			if (prev->left == curr)
				prev->left = nullptr;
			else
				prev->right = nullptr;
			return curr;
		}
		//for when deleting node only has 1 child
		if (curr->left == nullptr || curr->right == nullptr) {
			if (prev->left = curr) {
				if (curr->left != nullptr)
					prev->left = curr->left;
				else
					prev->left = curr->right;
			}
			else {
				if (curr->left != nullptr)
					prev->right = curr->left;
				else
					prev->right = curr->right;
			}
			return curr;
		}
		//for when deleting node has 2 childs
		if (curr->left != nullptr && curr->right != nullptr) {
			node<T>* replace = curr->left;
			while (replace->right != nullptr) {
				replace = replace->right;
			}
			node<T>* retval = curr;
			curr->data = Remove(replace->data)->data;
			return retval;
		}
	};
	
	/*void RotateLeft(node* parent, node* nR, node* nL)
	{
		parent->right = nR;
		nL->right = nR->left;
		nR->left = nL;
	}

	void RotateRight(node* gp, node* pivot)
	{
		node<T>* temp;
		if (gp->data > pivot->data) {
			temp = gp->left;
			gp->left = pivot;
		}
		else {
			temp = gp->right;
			gp->right = pivot;
		}
		temp->left = pivot->right;
		pivot->right = temp;
	}*/
	/*

cases

R- head
L - head
R - goonleft
R - go on right
L - go on right
L - goonleft

*/
	//int Height(node* curr) { //I'd call this weight
	//	if (curr == nullptr) return 0;
	//	int R, L;
	//	R = 1 + Height(curr->right);
	//	L = 1 + Height(curr->left);

	//	//add call to rotate

	//	if (R > L) return R;
	//	return L;
	//}
};
#endif