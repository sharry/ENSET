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
#include <string>
#include <sstream>

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
	size_t _count;

public:
	// Constructors
	LinkedList(T val)
	{
		Node *head = new Node(val);
		this->head = head;
		this->_count = 1;
	}
	LinkedList()
	{
		this->head = NULL;
		this->_count = 0;
	}
	// Append to the end of the list
	void append(T val)
	{
		Node *node = new Node(val);
		if (!this->head)
		{
			this->head = node;
			this->_count++;
			return;
		}
		auto curr = this->head;
		while (curr)
		{
			if (!curr->next)
			{
				curr->next = node;
				this->_count++;
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
			this->_count++;
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
				this->_count++;
				return;
			}
			currPos++;
			curr = curr->next;
		}
	}
	// Count the total number of elements
	size_t count()
	{
		return _count;
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
		this->_count--;
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
				this->_count--;
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
					this->_count--;
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
			this->_count--;
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
				this->_count--;
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
	T at(int index)
	{
		int n = this->count();
		if ((index < 0 ? -1 * index : index) >= n)
			throw std::invalid_argument("Index out of range");
		index = (n + index % n) % n;
		int currIndex = 0;
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
		this->_count += list->count();
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
		int n = this->count();
		offset = (n + offset % n) % n;
		if (offset == 0)
			return;
		else
		{
			auto arr = this->toArray();
			auto curr = this->head;
			int i = 0;
			while (curr)
			{
				curr->value = i - offset < 0 ? arr[i - offset + n] : arr[i - offset];
				curr = curr->next;
				i++;
			}
		}
	}
	// Adds all the elements of an array into a string, separated by the specified separator string
	std::string join(const char *seperator)
	{
		std::ostringstream strm;
		auto curr = this->head;
		while (curr)
		{
			strm << curr->value;
			if (curr->next)
				strm << seperator;
			curr = curr->next;
		}
		return strm.str();
	}
	// Check whether the list has an element with the given value
	bool has(T val)
	{
		auto curr = this->head;
		while (curr)
		{
			if (curr->value == val)
				return true;
			curr = curr->next;
		}
		return false;
	}
	// Fill the list with the given value in the given interval (inclusive)
	void fill(T val, int start = 0, int end = -1)
	{
		int n = this->count();
		end = (n + end % n) % n;
		start = (n + start % n) % n;
		if (start > end)
			return;
		auto curr = this->head;
		int i = 0;
		while (curr)
		{
			if (i >= start && i <= end)
				curr->value = val;
			i++;
			curr = curr->next;
		}
	}
};