// Program: linkedList2.cxx, by Sergio A. Alvarez
// Illustrates the creation of a linked list of nodes.
// Each node is a struct that contains an int value 
// as well as a pointer to the next node.
// Uses the external file io.cxx for input.

#include <iostream>
#include <cstdlib>
#include "io.h"		// Note that io.cxx must be provided
using namespace std;

struct Node {
	int value;
	Node* nextNode;
};

void createFirstNode(Node*& head, int value);
void appendNewNode(Node*& ptr, int value);
void printList(Node* ptr);

int main() {
	if (readString("Would you like to create a node? (yes/no): ") == "no")
		return EXIT_SUCCESS;
	Node* headPtr; 			// pointer to first Node
	createFirstNode(headPtr, readInteger("Enter an int to store in the first Node: "));
	Node* tailPtr = headPtr;	// pointer to last Node
	int count = 1;			// only one Node so far
	cout << "Initial list contains: ";
	printList(headPtr);
	while (readString("Another node? (yes/no): ") != "no") {
		appendNewNode(tailPtr, readInteger("Enter next value: "));
		cout << "List contains " << ++count << " nodes so far:" << endl;
		printList(headPtr);
	} 
	return EXIT_SUCCESS;
}

void createFirstNode(Node*& head, int value) {
	head = new Node;	
	head->nextNode = NULL;
	head->value = value;
}

void appendNewNode(Node*& ptr, int value) {
	ptr->nextNode = new Node;
	ptr = ptr->nextNode;
	ptr->value = value;
	ptr->nextNode = NULL;
}

void printList(Node* ptr) {
	while (ptr != NULL) {
		cout << ptr->value << "\t";
		ptr = ptr->nextNode;
	}
	cout << endl;
}

