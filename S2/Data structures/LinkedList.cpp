#include "LinkedList.h"

// Functions definition
LinkedList::LinkedList(Node *head)
{
	this->head = head;
}
LinkedList::LinkedList(int val)
{
	Node *head = new Node(val);
	this->head = head;
}
void LinkedList::setHead(Node *head)
{
	this->head = head;
}
void LinkedList::append(int val)
{
	Node *node = new Node(val);
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
void LinkedList::insertAt(int pos, int val)
{
	Node *node = new Node(val);
	auto curr = this->head;
	int currPos = 0;
	if (pos == 0)
	{
		node->next = curr;
		this->setHead(node);
		return;
	}
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
void LinkedList::display()
{
	auto curr = this->head;
	int index = 0;
	std::cout << std::endl
			  << "| Index\t| Value\t|" << std::endl
			  << "|---------------|" << std::endl;
	while (curr)
	{
		std::cout << "|" << index << "\t|" << curr->value << "\t|" << std::endl;
		curr = curr->next;
		index++;
	}
}
int LinkedList::count()
{
	int c = 0;
	auto curr = this->head;
	while (curr)
	{
		curr = curr->next;
		c++;
	}
	return c;
}
int LinkedList::occurrencesCount(int val)
{
	int c = 0;
	auto curr = this->head;
	while (curr)
	{
		if (curr->value == val)
			c++;
		curr = curr->next;
	}
	return c;
}
void LinkedList::deleteFirst(int val)
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
				this->setHead(curr->next);
				delete curr;
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}
void LinkedList::deleteLast(int val)
{
	this->deleteNth(this->occurrencesCount(val), val);
}
void LinkedList::deleteAll(int val)
{
	while (this->occurrencesCount(val) != 0)
	{
		this->deleteFirst(val);
	}
}
void LinkedList::deleteNth(int n, int val)
{
	int currN = 0;
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
					this->setHead(curr->next);
					delete curr;
				}
				return;
			}
		}
		prev = curr;
		curr = curr->next;
	}
}
void LinkedList::deleteAt(int index)
{
	if (index == 0)
	{
		auto head = this->head;
		this->setHead(head->next);
		delete head;
	}
	int currIndex = 0;
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
int LinkedList::positionOfFirst(int val)
{
	int pos = 0;
	auto curr = this->head;
	while (curr)
	{
		if (curr->value == val)
			return pos;
		pos++;
		curr = curr->next;
	}
	std::cout << val << " does not exist in the list.";
	return -1;
}
int *LinkedList::positionsOf(int val)
{
	int const occ = this->occurrencesCount(val);
	if (occ == 0)
		return NULL;
	int *positions = new int[occ];
	int pos = 0;
	int i = 0;
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
int LinkedList::valueAt(int index)
{
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
