#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
using namespace std;

template<class T>
class Node {
public:
	bool deleted;
	T* item;
	Node()
	{
		item = nullptr;
		deleted = false;
	}
	~Node() {
	}
};

template<class T>
class HashTable {
protected:
	Node<T>* values;
	int size;
	int length;
	int Hash(string inVal)
	{
		int ASCII = 0;
		for (int i = 0; i < inVal.length(); i++)
		{
			ASCII += int(inVal[i]);
		}
		return ASCII % size;
	}

public:
	int addEfficiency;
	int findEfficiency;
	class FullHashTable {};
	HashTable(int Size = 100)
	{
		addEfficiency = 0;
		findEfficiency = 0;
		size = Size;
		values = new Node<T>[size];
	}

	~HashTable()
	{
		delete[] values;
	}

	int GetLength() {
		return length;
	}

	bool IsFull() {
		return (length >= size);
	}
	/*
		Collissions options
		- Rehash
		- LL for each spot
		- Move over (Probing)
			. linear probing (move to next available spot)
			. quadratic probing (move to random spot)
			. random probing (seed should be hash(spot))
		- 2-D array
	*/
	void AddItem(T* inVal) {
		if (IsFull())
		{
			throw FullHashTable();
		}
		int spot = Hash(*inVal);
		addEfficiency++;
		while (values[spot].item != nullptr && !values[spot].deleted) {
			spot = (spot + 1) % size;
			addEfficiency++;
		}
		values[spot].item = inVal;
		length++;
	}

	T* GetItem(T* inVal) {
		int spot = Hash(*inVal);
		//cout << "Hash: " << spot <<endl;
		findEfficiency++;
		int count = spot;
		while (values[spot].item != nullptr && (*(values[spot].item) != *(inVal) || values[spot].deleted)) {
			findEfficiency++;
			spot = (spot + 1) % size;
			if (count == spot) {
				return nullptr;
			}
		}
		return values[spot].item;
	}

	T* RemoveItem(T* key)
	{
		if (GetItem(key) == nullptr) {
			return nullptr;
		}
		int spot = Hash(*key);
		while (values[spot].item != nullptr && *(values[spot].item) != *key) {
			spot = (spot + 1) % size;
		}
		values[spot].deleted = true;
		length--;
		return values[spot].item;
	}


	bool operator ==(HashTable<T> table)
	{
		if (this->length == table.GetLength()) {
			return true;
		}
		else {
			return false;
		}
	}
	/*
		H(x) = 1st Letter
		A = 0 % SIZE
		B = 1 % SIZE
		C = 2 % SIZE
			.
			.
			.
	*/
};

#endif
