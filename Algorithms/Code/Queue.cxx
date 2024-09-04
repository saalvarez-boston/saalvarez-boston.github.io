// Program: Queue.cxx, by Sergio A. Alvarez
// Implementation file for the Queue class

#include <iostream>
#include "Queue.h"
using namespace std;

	/** 
	* constructors 
	*/
		// creates a Queue with the given initial capacity
		Queue::Queue(size_t size) {
			data = new string[size];
			capacity = size;
			frontPos = 0;
			rearPos = 0;
		}

		// creates a Queue with initial capacity DEFAULT_CAPACITY
		Queue::Queue() {
			data = new string[DEFAULT_CAPACITY];
			capacity = DEFAULT_CAPACITY;
			frontPos = 0;
			rearPos = 0;
		}

		// copy constructor: creates a copy of the argument Queue
		Queue::Queue(const Queue& existing) {
			data = new string[existing.capacity];
			capacity = existing.capacity;
			frontPos = existing.frontPos;
			rearPos = existing.rearPos;
			for (int pos=0; pos<capacity; pos++)
				data[pos] = existing.data[pos];
		}

	/** 
	* destructor 
	*/
		// releases the memory allocated for this Queue
		Queue::~Queue() {
			delete [ ] data;
			capacity = 0;
			frontPos = 0;
			rearPos = 0;
		}

	/** 
	* selectors
	*/
		// returns the number of elements of the recipient Queue
		size_t Queue::size() const {
			return (capacity+rearPos-frontPos)%capacity;
		}

                // returns true if and only if the recipient has no elements
                bool Queue::isEmpty() const {
			return (size()==0);
		}

		// displays the elements of the recipient Queue
		void Queue::println() const {
			cout << "(rear)";
			for (int count=size(); count>=0; count--)
				cout << " " << data[(frontPos+count)%capacity];
			cout << " (front)" << endl;
		}

		// returns the element at the front of the recipient Queue
		string Queue::front() const {
			return data[frontPos];
		}

		// returns the element at the rear of the recipient Queue
		string Queue::rear() const {
			return data[(rearPos-1)%capacity];
		}

	/** 
	* modifiers
	*/
		// adds the argument at the rear of the recipient Queue
		void Queue::insert(string elem) {
			if (size() >= capacity-1)
				increaseCapacity();
			data[rearPos] = elem;
			rearPos = (rearPos+1)%capacity;
		}

		// removes the element at the front of the recipient Queue
		void Queue::remove() {
			frontPos = (frontPos+1)%capacity;
		}

	/** 
	* helper member functions
	*/
		// doubles the storage capacity of the recipient Queue
		void Queue::increaseCapacity() {
			string* newData = new string[2*capacity];
			for (int pos=0; pos<size(); pos++) 
				newData[pos] = data[(frontPos+pos)%capacity];
			size_t oldSize = size();
			delete [ ] data;
			data = newData;	// careful: this changes size()
			capacity = 2*capacity;
			frontPos = 0;
			rearPos = oldSize;
		}

