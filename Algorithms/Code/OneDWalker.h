// OneDWalker.h, by Sergio A. Alvarez
// Header file for the C++ class OneDWalker whose instances 
// represent point objects that move randomly along a line.
// Note that this file contains only the class outline with 
// function prototypes; implementations are in a separate file.

#include <iostream>
using namespace std;

class OneDWalker {
	public:
	/**
	* public data members
	*/
		// default parameters; static means that they 
		// are shared by all OneDWalker instances
		static const int DEFAULT_LOCATION = 50;
		static const int AVERAGE_SPEED = 5;
	/**
	* constructors
	*/
		// creates a new OneDWalker with location DEFAULT_LOCATION
		OneDWalker();

	/**
	* selector member functions
	*/
		// returns the recipient's current location
		double getLocation() const;

		// prints the recipient's current location
		void printLocation() const;

		// prints the argument string on the current line in the
		// console window, starting at recipient's current location
		void drawLocation(string label) const;

	/**
	* modifier member functions
	*/
		// changes recipient's location by an amount
		// proportional to its speed
		void step();

		// changes the recipient's speed by a random amount
		// proportional to the value AVERAGE_SPEED
		void changeSpeed();

	private:
	/**
	* private data members; each OneDWalker has its own copies of
	* these variables (also called instance variables); they cannot 
	* be accessed from a client program, except indirectly by calling
	* the member functions of the class
	*/
		double x, dx;
};

