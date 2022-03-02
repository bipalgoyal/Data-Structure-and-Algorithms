#pragma once
#ifndef ADDINTOMIDDLEOL_H
#define ADDINTOMIDDLEOL_H
#include "OrderedList.h"

template<class T>
class AddIntoMiddleOl : public OrderedList<T> {
public: 
	void AddItem(T val) {
		int* item = new int(val);
		int index = 12;

		while ((*item[index] < *item || item[index] == nullptr) && index != 0)
		{
			index--;
		}
		if (item[index + 1] != nullptr)
		{
			for (int i = index; i < 25; i++)
			{
				int* tempVal = *item[i + 1];
				item[]
			}
		}
	}
};

#endif
