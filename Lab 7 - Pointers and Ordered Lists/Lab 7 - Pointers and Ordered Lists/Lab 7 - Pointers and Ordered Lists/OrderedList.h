#pragma once
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

const int size = 50;

//ascending order list
template<class T>
class OrderedList
{
protected:
	T *items[size];
	int length;
	int addEfficiency;
	int removeEfficiency;
public:
	class FullOrderedListException {};
	class EmptyOrderedListException {};
	class NotFoundOrderedListException {};

	OrderedList()
	{
		length = 0;
		addEfficiency = 0;
		removeEfficiency = 0;
		for (int i = 0; i < size; i++) {
			items[i] = nullptr;
		}
	};
	~OrderedList()
	{
		for (int i = 0; i < size; i++) {
			if (items[i] != nullptr) {
				delete items[i];
			}
		}
	};

	void AddItem(T val)
	{
		if (IsFull()) {
			throw FullOrderedListException();
		}
		T *item = new T(val);
		if (Length() == 0) {
			items[0] = item;
			addEfficiency++;
			length++;
			return;
		}
		int count = -1;
		while (items[count+1] != nullptr && !(*items[count + 1] > *item)) {
			addEfficiency++;
			count++;
		}
		if (count + 1 != length) {
			for (int i = length - 1; i >= count + 1; i--) {
				addEfficiency++;
				items[i + 1] = items[i];
			}
		}
		items[count + 1] = item;
		length++;
	};

	T RemoveItem(T val)
	{
		if (IsEmpty()) {
			throw EmptyOrderedListException();
		}
		int pos = 0;
		while (items[pos] != nullptr && *items[pos] != val) {
			removeEfficiency++;
			pos++;
		}
		if (pos == length && *items[pos] != val) {
			throw NotFoundOrderedListException();
		}
		T data = *items[pos];
		for (int i = pos; i < length; i++) {
			removeEfficiency++;
			items[i] = items[i + 1];
		}
		items[length - 1] = nullptr;
		length--;
		return data;
	};

	void MakeEmpty() {
		for (int i = 0; i < size; i++) {
			items[i] = nullptr;
		}
		length = 0;
	};

	int Length() {
		return length;
	};
	bool IsFull() {
		return length >= size;
	};
	bool IsEmpty() {
		return length <= 0;
	};

	int getAddEfficiency() {
		return this->addEfficiency;
	}

	int getRemoveEfficiency() {
		return this->removeEfficiency;
	}

	bool operator ==(OrderedList<T> list) 
	{
		if (this->length == list.Length()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator >(OrderedList<T> list)
	{
		if (this->length > list.Length()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator <(OrderedList<T> list)
	{
		if (this->length < list.Length()) {
			return true;
		}
		else {
			return false;
		}
	}
};
#endif

