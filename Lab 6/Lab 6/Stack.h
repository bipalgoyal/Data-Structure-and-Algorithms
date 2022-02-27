#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
template<class T>
class Stack
{
public:
	T **items;
	int length; 
	T *top;
	int size;
public:
	class FullStackException {};
	class EmptyStackException {};

	Stack(int size) 
	{
		length = 0;
		top = NULL;
		this->size = size;
		items = new T*[size];
	};
	~Stack() 
	{
		delete[] items;
	};

	void Push(T *item) 
	{
		if (IsFull()) {
			throw FullStackException();
		}
		items[length] = item;
		top = item;
		length++;
	};

	T* Pop()
	{
		if (IsEmpty()) {
			throw EmptyStackException();
		}
		length--;
		top = items[length];
		return items[length];
	};

	T* Top() {
		if (IsEmpty()) {
			throw EmptyStackException();
		}
		return top;
	};

	void Empty() {
		for (int i = length-1; i >= 0 ; i--) {
			delete items[i];
			length--;
		}
		//delete[] items;
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
};
#endif

