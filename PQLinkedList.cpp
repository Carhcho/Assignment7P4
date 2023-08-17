#include "PQLinkedList.h"


PQLinkedList::PQLinkedList() {
	head = NULL;
	tail = NULL;
	cout << sizeof(Node) << endl;
}

PQLinkedList::~PQLinkedList() {
	destroyList();
}

void PQLinkedList::destroyList() {
	Node* currNode = head;
	Node* nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

void PQLinkedList::displayList() {
	Node* currNode = head;

	while (currNode != NULL) {
		cout << currNode->value << " ";
		currNode = currNode->next;
	}
}

void PQLinkedList::appendNode(int newValue) {
	// make a new Node
	Node* newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;

	// 2 cases
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		// list is not empty
		tail->next = newNode;
		tail = newNode;
	}
}


int PQLinkedList::dequeue() {
	// check to make sure there is something to delete
	int value = -1;
	if (head != NULL) {
		Node* nodeToDelete = head;
		head = head->next;
		value = nodeToDelete->value;
		delete nodeToDelete;
		number++; //this number means the number of times the operation dequeue accessed the elements on the list.
		if (head == NULL) {
			tail = NULL;
			number++;
		}
	}
	return value;
}

void PQLinkedList::enqueue(int newValue) {
	// make a new Node
	Node* newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;

	// 2 cases, first if the list is empty meaning head = NULL, then both head and tail will point to the new node.
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		number++;
	}
	else {
		// Second, when the list is not empty
		Node* currNode = head;
		Node* prevNode = NULL;
		//Sorts the list by giving priority to the smallest number as requested in the problem page.
		while (currNode != NULL && currNode->value < newValue) {
			prevNode = currNode;
			currNode = currNode->next;
			number++;
		}
		//checks prevNode for 2 cases, 1 if is NULL making newNode the head and currentNode next and 2 connecting newNode after prevNode and currentNode after newNode.
		if (prevNode == NULL) {
			head = newNode;
			newNode->next = currNode;
			number++;
		}
		else {
			prevNode->next = newNode;
			newNode->next = currNode;
			//and assign tail to newNode is it is at the end of the list.
			if (newNode->next == NULL) {
				tail = newNode;
				number++;
			}
		}
	}
}

int PQLinkedList::count()
{
	return number;
}
