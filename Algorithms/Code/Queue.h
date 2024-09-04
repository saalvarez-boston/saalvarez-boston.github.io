// File: Queue.h, by Sergio A. Alvarez.
// Header file for an instantiable Queue class.
// Each Queue represents a linearly ordered sequence of string values.
// Queues provide First In First Out (FIFO) access to elements via functions
// string front(), string rear(), void insert(string), and void remove();
// a size_t size() function returns the number of elements of a Queue.
// Internal representation is based on a dynamically allocated array;
// constructor and destructor functions deal with dynamic memory issues.

#include <iostream>
using namespace std;

class Queue {

	public:

		static const size_t DEFAULT_CAPACITY = 5;

	/** 
	* constructors 
	*/
		// creates a Queue with the given initial capacity
		Queue(size_t);

		// creates a Queue with initial capacity DEFAULT_CAPACITY
		Queue();

		// copy constructor: creates a copy of the argument Queue
		Queue(const Queue&);

	/** 
	* destructor 
	*/
		// releases the memory allocated for this Queue
		~Queue();

	/** 
	* selectors
	*/
		// returns the number of elements of the recipient Queue
		size_t size() const;

		// returns true if and only if the recipient has no elements
		bool isEmpty() const;

		// displays the elements of the recipient Queue
		void println() const;

		// returns the element at the front of the recipient Queue
		string front() const;

		// returns the element at the rear of the recipient Queue
		string rear() const;

	/** 
	* modifiers
	*/
		// adds the argument at the rear of the recipient Queue
		void insert(string);

		// removes the element at the front of the recipient Queue
		void remove();

	private:
		// storage array for this Queue
		string* data;
		// position of the front element in the data array
		size_t frontPos;
		// first position after the rear element in the data array
		size_t rearPos;
		// size of the data array
		size_t capacity;
		// helper method to increase the size of the data array
		void increaseCapacity();
};

