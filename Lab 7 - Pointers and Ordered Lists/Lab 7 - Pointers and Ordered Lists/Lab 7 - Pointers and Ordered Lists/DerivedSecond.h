#pragma once
#ifndef DERIVEDSECOND_H
#define DERIVEDSECOND_H

#include "OrderedList.h"

template<class T>
class DerivedSecond : public OrderedList<T> {
	//length refers to number of valid values present in the array currently
public:
	class FullOrderedListException {};
	class EmptyOrderedListException {};
	class NotFoundOrderedListException {};
	T RemoveItem(T val)
	{
		if (this->IsEmpty()) {
			throw EmptyOrderedListException();
		}
		int pos = 0;
		while (pos < size) {
			if (this->items[pos] != nullptr && *this->items[pos] == val) 
				break;
			pos++;
		}
		//are you at the last element, does it contain a valid value, and is that the value you're looking for?
		if (pos == size) 
			throw NotFoundOrderedListException();
		T data = *this->items[pos];
		this->items[pos] = nullptr;
		this->length--;
		return data;
	}

	void AddItem(T val)
	{
		if (this->IsFull()) {
			throw FullOrderedListException();
		}
		int pos = 0, countValidVal = 0;
		while (pos < size) {
			T nextVal;
			int blankspots = 0;
			while (pos < size && this->items[pos] == nullptr) {
				pos++;
				blankspots++;
			}
			countValidVal++;
			nextVal = *this->items[pos];
			if (nextVal > val) {
				//no blankspots
				if (blankspots == 0) {
					//move items until you find a blank spot
					int moveAhead = 1, moveBack = 1;
					bool useAhead;
					//find blank spot
					while (true) {
						if ((pos - moveBack >= 0) && this->items[pos - moveBack] == nullptr) {
							useAhead = false;
							break;
						}
						if ((pos + moveAhead < size) && this->items[pos + moveAhead] == nullptr) {
							useAhead = true;
							break;
						}
						moveAhead++;
						moveBack++;
					}
					if (useAhead) {
						//shift items ahead
						for (int i = pos + moveAhead; i > pos;i--) {
							this->items[i] = this->items[i - 1];
						}
						this->items[pos] = new T(val);
					}
					else {
						//shift items behind
						for (int i = pos - moveBack; i < pos; i++) {
							this->items[i] = this->items[i + 1];
						}
						this->items[pos-1] = new T(val);
					}
				}
				//there are blank spots
				else {
					int shift = (blankspots % 2 == 0) ? blankspots / 2 : blankspots / 2 + 1;
					this->items[pos - shift] = new T(val);
				}
				this->length++;
				break;
			}
			pos++;
		}
	}
};
#endif