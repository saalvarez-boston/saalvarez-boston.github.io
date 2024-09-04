// Program: Stack.h, by Sergio A. Alvarez
// Header file for an instantiable Stack<Item> template class.
// Note that the implementation file Stack.template is included directly 
// in this header file (with the #include directive near the end).
// Each Stack<Item> represents a linearly ordered sequence of Item values.
// Stack<Item> instances provide Last In First Out (LIFO) access to elements 
// via Item top(), void push(Item), and void pop() functions;
// a size_t size() function returns the number of elements of a Stack.
// Internal representation is based on a dynamically allocated array;
// constructor and destructor functions deal with dynamic memory issues.

// conditional definition avoids problems if several source files
// include this header file (for larger multi-file programs)
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class Item>
class Stack {

	public:

		static const size_t DEFAULT_CAPACITY = 10;

	/** 
	* constructors 
	*/
		// creates a Stack with the given initial capacity
		Stack(size_t);

		// creates a Stack with initial capacity DEFAULT_CAPACITY
		Stack();

		// copy constructor: creates a copy of the argument Stack
		Stack(const Stack&);

	/** 
	* destructor 
	*/
		// releases the memory allocated for this Stack
		~Stack();

	/** 
	* selectors
	*/
		// returns the number of elements of the recipient Stack
		size_t size() const;

		// returns true if and only if recipient has no elements
		bool isEmpty() const;

		// displays the elements of the recipient Stack
		void println() const;

		// returns the element at the top of the recipient Stack
		Item top() const;

	/** 
	* modifiers
	*/
		// adds the argument at the top of the recipient Stack
		void push(Item);

		// removes the element at the top of the recipient Stack
		void pop();

	private:
		// storage array for this Stack
		Item* data;
		// first available position in the data array
		size_t nextPos;
		// size of the data array
		size_t capacity;
		// helper function to increase the size of the data array
		void increaseCapacity();
};

#include "Stack.template"

#endif

