#pragma once
#ifndef ADDINTOMIDDLEOL_H
#define ADDINTOMIDDLEOL_H
#include "OrderedList.h"

template<class T>
class AddIntoMiddleOL : public OrderedList<T> {
public:
	class FullOrderedListException {};
	void AddItem(T val) {
		if (this->IsFull()) {
			throw FullOrderedListException();
		}
		int* item = new int(val);
		int index = size/2;
		while (index != 0 && (this->items[index - 1] == nullptr || *this->items[index - 1] > *item))
		{
			this->addEfficiency++;
			index--;
		}
		while (index < this->length && (this->items[index] != nullptr && *this->items[index] < *item))
		{
			this->addEfficiency++;
			index++;
		}
		if (this->items[index] != nullptr)
		{
			for (int i = this->length - 1; i >= index; i--)
			{
				this->addEfficiency++;
				this->items[i + 1] = this->items[i];
			}
		}

		this->items[index] = item;
		this->length++;
	}
};

#endif
