#pragma once
#ifndef DOUBLEORDEREDLINKEDLIST_H
#define DOUBLEORDEREDLINKEDLIST_H

#include "Part.h"

template<typename T>
struct node
{
	T data;
	node* next = nullptr;
	node* prev = nullptr;
};

template<class T>
class DoubleOrderedLinkedList
{
private:
	node<T>* head;
	node<T>* see;
	int size;
public:
	int addEfficiency;
	int findEfficiency;
	class LinkedListEmptyException {};
	class OutOfBoundsException {};

	DoubleOrderedLinkedList()
	{
		head = nullptr;
		see = nullptr;
		size = 0;
		addEfficiency = 0;
		findEfficiency = 0;
	}
	~DoubleOrderedLinkedList()
	{
		delete(head);
		delete(see);
	}

	void DisplayList()
	{
		node<T>* cur = head;
		int count = 1;
		while (cur != nullptr)
		{
			cout << "---------------------------------------------------------" << endl;
			cout << "Content of Item #" << count << ":" << endl;
			cur->data.DisplayPart();
			cout << "---------------------------------------------------------" << endl;
			cur = cur->next;

		}
	}

	void AddItem(T item)
	{
		addEfficiency = 0;
		node<T>* temp = new node<T>();
		temp->data = item;
		temp->next = nullptr;
		temp->prev = nullptr;
		if (head == nullptr)
		{
			head = temp;
			addEfficiency++;
		}
		else if (head->data > temp->data)
		{
			temp->next = head;
			temp->next->prev = temp;
			head = temp;
			addEfficiency++;
		}
		else
		{
			node<T>* curr = head;
			addEfficiency++;
			while (curr->next != nullptr && curr->next->data < temp->data)
			{
				curr = curr->next;
				addEfficiency++;
			}

			temp->next = curr->next;
			if (curr->next != nullptr)
			{
				temp->next->prev = temp;
			}
			curr->next = temp;
			temp->prev = curr;
		}
		size++;
	}
	node<T>* RemoveItem(T item)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		node<T>* temp = new node<T>();
		temp->data = item;
		temp->next = nullptr;
		temp->prev = nullptr;
		node<T>* curr = head;

		if (temp->data == head->data)
		{
			temp = head;
			head = head->next;
			size--;
			return temp;
		}

		while (curr->next != nullptr && curr->next->data != temp->data)
		{
			curr = curr->next;
		}
		if (curr->next == nullptr)
		{
			return nullptr;
		}
		temp = curr->next;
		if (temp->next != nullptr)
		{
			curr->next = temp->next;
			temp->next->prev = curr;
		}
		else
		{
			curr->next = nullptr;
		}
		size--;
		return temp;
	}

	node<T>* GetItem(T item)
	{
		findEfficiency = 0;
		if (head == nullptr)
		{
			return nullptr;
		}
		node<T>* temp = new node<T>();
		temp->data = item;
		temp->next = nullptr;
		temp->next = nullptr;


		findEfficiency++;
		if (head->data == temp->data)
		{
			return head;
		}

		node<T>* curr = head;
		while (curr->next != nullptr && curr->data != temp->data)
		{
			findEfficiency++;
			curr = curr->next;
		}
		if (curr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return curr;
		}
	}

	bool IsEmpty()
	{
		return size == 0;
	}
	int Size()
	{
		return size;
	}

	node<T>* SeeNext()
	{
		if (head == nullptr)
		{
			throw LinkedListEmptyException();
		}
		if (see == nullptr)
		{
			see = head;
			return see;
		}
		if (see->next == nullptr)
		{
			return nullptr;
		}
		see = see->next;
		return see;
	}
	node<T>* SeePrev()
	{
		if (head == nullptr)
		{
			throw LinkedListEmptyException();
		}
		if (see == nullptr)
		{
			see = head;
			while (see->next != nullptr)
			{
				see = see->next;
			}
			return see;
		}
		if (see->prev == nullptr)
		{
			return nullptr;
		}
		see = see->prev;
		return see;
	}
	node<T>* SeeAt(int location)
	{
		location--;
		if (location >= size)
		{
			throw OutOfBoundsException();
		}
		see = head;
		for (int i = 0; i < location; i++)
		{
			see = see->next;
		}
		return see;
	}
	void Reset()
	{
		see = nullptr;
	}
};
#endif