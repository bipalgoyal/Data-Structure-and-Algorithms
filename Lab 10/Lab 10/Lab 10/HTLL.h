#pragma once
#ifndef HTLL_H
#define HTLL_H

#include "HashTable.h"
#include "DoubleOrderedLinkedList.h"

template<class T>
class HTLL : public HashTable<T> {
private:
	DoubleOrderedLinkedList<T>* items;
public:
	int addEfficiency;
	int findEfficiency;
	class NotFound{};

	HTLL(int Space = 100) {
		addEfficiency = 0;
		findEfficiency = 0;
		HashTable<T>::size = Space;
		items = new DoubleOrderedLinkedList<T>[HashTable<T>::size];
	}

	void AddItem(T inVal) {
		int spot = HashTable<T>::Hash(inVal);
		items[spot].AddItem(inVal);
		addEfficiency += items[spot].addEfficiency;
		HashTable<T>::length++;
	}
	T GetItem(T key) {
		int spot = HashTable<T>::Hash(key);
		node<T>* retNode = items[spot].GetItem(key);
		findEfficiency += items[spot].findEfficiency;
		if (retNode == nullptr) {
			throw NotFound();
		}
		return retNode->data;
	}
	T RemoveItem(T key) {
		int spot = HashTable<T>::Hash(key);
		node<T>* retNode = items[spot].RemoveItem(key);
		if (retNode == nullptr) {
			throw NotFound();
		}
		return retNode->data;
	}
};

#endif