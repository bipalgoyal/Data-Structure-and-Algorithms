#pragma once
#ifndef ADDINTOMIDDLEOL_H
#define ADDINTOMIDDLEOL_H
#include "OrderedList.h"

template<class T>
class AddIntoMiddleOL : public OrderedList<T> {
public: 
	void AddItem(T val) {
		int* item = new int(val);
		int index = 12;

		while ((*this->items[index] > *item || this->items[index] == nullptr) && index != 0)
		{
			index--;
		}
		while ((*this->items[index] < *item && this->items[index + 1] != nullptr) && index < this->length)
		{
			index++;
		}
		if (this->items[index + 1] != nullptr)
		{
			for (int i = this->length - 1; i >= index + 1; i--)
			{
				this->items[i + 1] = this->items[i];
			}
		}

		this->items[index] = item;
		this->length++;
	}
};

#endif
