#pragma once
#include <iostream>
#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H

const int numItems = 10;
template<class T>
class EntertainmentCollection
{
private:
	T items[numItems];
	int length;
public:
	class FullEntertainmentCollection
	{};
	class EmptyEntertainmentCollection
	{};

	EntertainmentCollection() {
		length = 0;
	};

	void Add(T *item) {
		if (IsFull())
		{
			throw FullEntertainmentCollection();
		}
		items[length] = *item;
		length++;
	};
	T Remove() {
		if (IsEmpty()) {
			throw EmptyEntertainmentCollection();
		}
		length--;
		return items[length];
	};
	
	int CurrentSize() {
		return length;
	};
	bool IsFull() {
		return length >= numItems;
	};
	bool IsEmpty() {
		return length <= 0;
	};
};

#endif

