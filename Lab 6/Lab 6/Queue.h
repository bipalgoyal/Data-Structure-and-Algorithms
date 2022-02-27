#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
template<class T>
class Queue
{
public:
	T* items;
	int back; //if there are 5 items
	int size;
public:
	class FullQueueException {};
	class EmptyQueueException {};

	Queue(int size)
	{
		back = 0;
		this->size = size;
		items = new T[size];
	};
	~Queue()
	{
		delete[] items;
	};

	void Push(T item)
	{
		if (IsFull()) {
			throw FullQueueException();
		}
		items[back] = item;
		back++;
	};

	T Pop()
	{
		if (IsEmpty()) {
			throw EmptyQueueException();
		}
		T data = items[0];
		for (int i = 0; i < back - 1; i++) {
			items[i] = items[i + 1];
		}
		back--;
		return data;
	};

	void Empty() {
		delete[] items;
		items = new T[size];
		back = 0;
	};

	int Length() {
		return back;
	};
	bool IsFull() {
		return back >= size;
	};
	bool IsEmpty() {
		return back <= 0;
	};
};
#endif

