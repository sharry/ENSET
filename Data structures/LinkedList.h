// Accessing: O(n)
// Inserting: Beggining: O(1) Middle & End: O(n)
// Deleting : Beggining: O(1) Middle & End: O(n)

#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		// Value of the node
		T value;
		// Address of the next node
		Node *next;
		// Make a new node
		Node(T value)
		{
			this->value = value;
			this->next = NULL;
		}
	};
	Node *head;

public:
	// Constructors
	LinkedList(T val)
	{
		Node *head = new Node(val);
		this->head = head;
	}
	LinkedList()
	{
		this->head = NULL;
	}
	// Print to the console the elements of the list
	void display()
	{
		auto curr = this->head;
		while (curr)
		{
			std::cout << curr->value;
			if (curr->next)
				std::cout << " -> ";
			curr = curr->next;
		}
	}
	// Append to the end of the list
	void append(T val)
	{
		Node *node = new Node(val);
		if (!this->head)
		{
			this->head = node;
			return;
		}
		auto curr = this->head;
		while (curr)
		{
			if (!curr->next)
			{
				curr->next = node;
				return;
			}
			curr = curr->next;
		}
	}
	// Insert at at given position
	void insertAt(size_t pos, T val)
	{
		Node *node = new Node(val);
		auto curr = this->head;
		if (pos > this->count())
			return;
		if (pos == 0)
		{
			node->next = curr;
			this->head = node;
			return;
		}
		size_t currPos = 0;
		while (curr)
		{
			if (pos - currPos == 1)
			{
				if (curr->next)
				{
					auto tmp = curr->next;
					curr->next = node;
					node->next = tmp;
				}
				else
					curr->next = node;
				return;
			}
			currPos++;
			curr = curr->next;
		}
	}
	// Count the total number of elements
	size_t count()
	{
		size_t c = 0;
		auto curr = this->head;
		while (curr)
		{
			curr = curr->next;
			c++;
		}
		return c;
	}
	// Count the number of occurrences of an element
	size_t occurrencesCount(T val)
	{
		size_t c = 0;
		auto curr = this->head;
		while (curr)
		{
			if (curr->value == val)
				c++;
			curr = curr->next;
		}
		return c;
	}
	// Delete the last element and return its value
	T pop()
	{
		auto curr = this->head;
		Node *prev = NULL;
		T val;
		while (curr)
		{
			if (!curr->next)
			{
				val = curr->value;
				if (prev)
				{
					prev->next = NULL;
					delete curr;
				}
				else
					this->head = NULL;
				return val;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
	}
	// Delete first node with the given value
	void deleteFirst(T val)
	{
		Node *curr = this->head;
		Node *prev = NULL;
		while (curr)
		{
			if (curr->value == val)
			{
				if (prev)
				{
					prev->next = curr->next;
					delete curr;
				}
				else
				{
					this->head = curr->next;
					delete curr;
				}
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	// Delete last node with the given value
	void deleteLast(T val)
	{
		this->deleteNth(this->occurrencesCount(val), val);
	}
	// Delete All nodes with the given value
	void deleteAll(T val)
	{
		while (this->occurrencesCount(val) != 0)
		{
			this->deleteFirst(val);
		}
	}
	// Delete n-th node with the given value
	void deleteNth(size_t n, T val)
	{
		size_t currN = 0;
		auto curr = this->head;
		Node *prev = NULL;
		while (curr)
		{
			if (curr->value == val)
			{
				currN++;
				if (currN == n)
				{
					if (prev)
					{
						prev->next = curr->next;
						delete curr;
					}
					else
					{
						this->head = curr->next;
						delete curr;
					}
					return;
				}
			}
			prev = curr;
			curr = curr->next;
		}
	}
	// Delete the node at given index
	void deleteAt(size_t index)
	{
		if (index > this->count() || index < 0)
			return;
		if (index == 0)
		{
			auto head = this->head;
			this->head = head->next;
			delete head;
			return;
		}
		size_t currIndex = 0;
		Node *curr = this->head;
		Node *prev = NULL;
		while (curr)
		{
			if (currIndex == index)
			{
				if (prev)
				{
					prev->next = curr->next;
					delete curr;
				}
				return;
			}
			currIndex++;
			prev = curr;
			curr = curr->next;
		}
	}
	// Position of the first node with the value val
	int positionOfFirst(T val)
	{
		size_t pos = 0;
		auto curr = this->head;
		while (curr)
		{
			if (curr->value == val)
				return pos;
			pos++;
			curr = curr->next;
		}
		return -1;
	}
	// All positions of nodes with the given value
	size_t *positionsOf(T val)
	{
		auto occ = this->occurrencesCount(val);
		if (occ == 0)
			return NULL;
		size_t *positions = new size_t[occ];
		size_t pos = 0;
		size_t i = 0;
		auto curr = this->head;
		while (curr)
		{
			if (curr->value == val)
			{
				positions[i] = pos;
				i++;
			}
			pos++;
			curr = curr->next;
		}
		return positions;
	}
	// Value of the node at the given index
	T valueAt(size_t index)
	{
		if (index > this->count() || index < 0)
			return NULL;
		size_t currIndex = 0;
		auto curr = this->head;
		while (curr)
		{
			if (currIndex == index)
				return curr->value;
			currIndex++;
			curr = curr->next;
		}
	}
	// Sort the list in ascending or descending order
	void sort(bool desc = false)
	{
		Node *cur1 = head;
		Node *cur2 = head;

		size_t count = this->count();
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < count - 1; j++)
			{
				if (desc)
				{
					if (cur1->value > cur2->value)
					{
						T temp = cur1->value;
						cur1->value = cur2->value;
						cur2->value = temp;
					}
				}
				else
				{
					if (cur1->value < cur2->value)
					{
						T temp = cur1->value;
						cur1->value = cur2->value;
						cur2->value = temp;
					}
				}
				cur2 = cur2->next;
			}
			cur2 = head;
			cur1 = head->next;
			for (size_t k = 0; k < i; k++)
			{
				cur1 = cur1->next;
			}
		}
	}
	// Reverse the list;
	void reverse()
	{
		Node *head = new Node(this->pop());
		while (this->head)
		{
			auto curr = head;
			while (curr)
			{
				if (!curr->next)
				{
					curr->next = new Node(this->pop());
					break;
				}
				curr = curr->next;
			}
		}
		this->head = head;
	}
	// Shuffle the list to random ordering
	void shuffle()
	{
		const size_t count = this->count();
		auto arr = this->toArray();
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(arr, arr + count, std::default_random_engine(seed));
		auto curr = this->head;
		size_t i = 0;
		while (curr)
		{
			curr->value = arr[i];
			curr = curr->next;
			i++;
		}
	}
	// Retuns the minimum value in the list
	T min()
	{
		auto curr = this->head;
		T minVal = curr->value;
		while (curr)
		{
			if (curr->value < minVal)
				minVal = curr->value;
			curr = curr->next;
		}
		return minVal;
	}
	// Retuns the maximum value in the list
	T max()
	{
		auto curr = this->head;
		T maxVal = curr->value;
		while (curr)
		{
			if (curr->value > maxVal)
				maxVal = curr->value;
			curr = curr->next;
		}
		return maxVal;
	}
	// Merge two lists
	void mergeWith(LinkedList<T> *list)
	{
		auto curr = this->head;
		while (curr)
		{
			if (!curr->next)
			{
				curr->next = list->head;
				return;
			}
			curr = curr->next;
		}
	}
	// Convert the list to an array
	T *toArray()
	{
		auto curr = this->head;
		T *arr = new T[this->count()];
		size_t i = 0;
		while (curr)
		{
			arr[i] = curr->value;
			curr = curr->next;
			i++;
		}
		return arr;
	}
	// Shift the list with given offset, positive offset shifts forward
	void shift(int offset = 1)
	{
		size_t n = this->count();
		offset = offset - ((offset / n) * n);
		offset = n + offset;
		offset = offset - ((offset / n) * n);
		if (offset == 0)
			return;
		else
		{
			auto arr = this->toArray();
			auto curr = this->head;
			size_t i = 0;
			while (curr)
			{
				curr->value = i - offset < 0 ? arr[i - offset + n] : arr[i - offset];
				curr = curr->next;
				i++;
			}
		}
	}
};