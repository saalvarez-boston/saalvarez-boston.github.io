// Program: List.h, by Sergio A. Alvarez
// Header file for first version of an instantiable List class
// Each List represents a linearly ordered sequence of int values.
// Lists provide random (indexed) access to elements using int get(size_t),
// as well as insertion at the end of the List using void append(int);
// a size_t length() function returns the number of elements of a List.
// Internal representation is based on a dynamically allocated array;
// constructor and destructor functions deal with dynamic memory issues.

#include <iostream>
using namespace std;

class List {

	public:

		static const size_t DEFAULT_CAPACITY = 10;

	/** 
	* constructors 
	*/
		// creates a List with the given initial capacity
		List(int);

		// creates a List with initial capacity DEFAULT_CAPACITY
		List();

		// copy constructor: creates a copy of the argument List
		List(const List&);

	/** 
	* destructor 
	*/
		// releases the memory allocated for this List
		~List();

	/** 
	* selectors
	*/
		// returns the number of elements of the recipient List
		size_t length() const;

		// displays the elements of the recipient List
		void println() const;

		// returns element of recipient List with the given location
		int get(size_t) const;

	/** 
	* modifiers
	*/
		// adds the argument at the end of the recipient List
		void append(int);

	private:
		// storage array for this List
		int* data;
		// first available position in the data array
		size_t nextPos;
		// size of the data array
		size_t capacity;
		// helper method to increase the size of the data array
		void increaseCapacity();
};

