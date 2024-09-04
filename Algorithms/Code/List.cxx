// Program: List.cxx, by Sergio A. Alvarez
// Implementation file for first version of the List class

#include <iostream>
#include "List.h"
using namespace std;

	/** 
	* constructors 
	*/
		// creates a List with the given initial capacity
		List::List(int initCap) {
			capacity = initCap; 
			data = new int[initCap];
			nextPos = 0;
		}

		// creates a List with initial capacity DEFAULT_CAPACITY
		List::List() {
			capacity = DEFAULT_CAPACITY; 
			data = new int[DEFAULT_CAPACITY];
			nextPos = 0;
		}

		// copy constructor: creates a copy of the argument List
		List::List(const List& given) {
			capacity = given.capacity;
			data = new int[capacity];
			nextPos = given.nextPos;
			for (int pos=0; pos<nextPos; pos++)
				data[pos] = given.data[pos];
		}

	/** 
	* destructor 
	*/
		// releases the memory allocated for this List
		List::~List() {
			delete [ ] data;
			capacity = 0;
			nextPos = 0;
		}

	/** 
	* selectors
	*/
		// returns the number of elements of the recipient List
		size_t List::length() const {
			return nextPos;
		}

		// displays the elements of the recipient List
		void List::println() const {
			for (int pos=0; pos<nextPos; pos++) 
				cout << " " << data[pos];
			cout << endl;
		}

		// returns element of recipient List with the given location
		int List::get(size_t pos) const {
			return data[pos];
		}

	/** 
	* modifiers
	*/
		// adds the argument at the end of the recipient List
		void List::append(int elem) {
			if (nextPos >= capacity)
				increaseCapacity();
			data[nextPos] = elem;
			nextPos++;
		}

		void List::increaseCapacity() {
			int* newData = new int[2*capacity];
			for (int pos=0; pos<nextPos; pos++) 
				newData[pos] = data[pos];
			delete [ ] data;
			data = newData;
			capacity = 2*capacity;
		}

