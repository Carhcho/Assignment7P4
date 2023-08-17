#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;


class PQLinkedList {
protected:
	
	struct Node {
		int value; // data value Node stores
		struct Node* next; // points to next Node in list
	};

	Node* head; // list head pointer
	Node* tail; // list tail pointer

public:
	PQLinkedList(); // constructor
	~PQLinkedList(); // destructor

	void displayList();
	void appendNode(int); // insert at end
	int dequeue();
	void destroyList();
	void enqueue(int);
	int count(); // this operation counts the number of times elements are accessed during enqueue and dequeue operations using the counter number.
	int number = 0;
};

#endif