// Accessing: O(n)
// Inserting: Beggining: O(1) Middle & End: O(n)
// Deleting : Beggining: O(1) Middle & End: O(n)

#include <iostream>
#include <memory>

// Data structures
struct Node
{
	// Value of the node
	int value;
	// Address of the next node
	Node* next;
	// Make a new node
	Node(int value)
	{
		this->value = value;
		this->next = NULL;
	}
};

class LinkedList
{
private:
	Node* head;
public:
	// Constructors
	LinkedList(Node*);
	LinkedList(int);
	// Set the list head
	void setHead(Node*);
	// Print to the console the elements of the list
	void display();
	// Append to the end of the list
	void append(int);
	// Insert at pos
	void insertAt(int, int);
	// Count the total number of elements
	int count();
	// Count the number ocurrences of an element
	int occurrencesCount(int);
	// Delete first node with the value val
	void deleteFirst(int);
	// Delete last node with the value val
	void deleteLast(int);
	// Delete All nodes with the value val
	void deleteAll(int);
	// Delete the node at given index
	void deleteAt(int);
	// Delete n-th node with the value val
	void deleteNth(int, int);
	// Position of the first node with the value val
	int positionOfFirst(int);
	// All positions of nodes with the value val
	int* positionsOf(int);
	// Value in the node the a given index
	int valueAt(int);
	// Sort the list;
};