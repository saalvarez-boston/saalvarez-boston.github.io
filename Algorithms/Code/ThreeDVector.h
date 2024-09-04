// Program: ThreeDVector.h, by Sergio A. Alvarez
// Header file for a 3-d vector class with overloaded 
// + (sum), * (dot product), and ^ (cross product) operators

#include <iostream>
using namespace std;

class ThreeDVector {
	public:
	/** 
	* constructors 
	*/
		// creates a ThreeDVector with the given coordinates
		ThreeDVector::ThreeDVector(double, double, double);

	/** 
	* selector member functions
	*/
		// returns the length (magnitude) of the recipient ThreeDVector
		double length() const;

		// displays the coordinates of the recipient ThreeDVector
		void println() const;

		// returns the first coordinate of the recipient ThreeDVector
		double getFirst() const;

		// returns the second coordinate of the recipient ThreeDVector
		double getSecond() const;

		// returns the third coordinate of the recipient ThreeDVector
		double getThird() const;

		// returns a new ThreeDVector that contains the vector sum of 
		// the recipient ThreeDVector and the parameter ThreeDVector
		ThreeDVector operator +(ThreeDVector) const;

		// returns the dot product of the recipient ThreeDVector 
		// and the parameter ThreeDVector
		double operator *(ThreeDVector) const;

		// returns a new ThreeDVector resulting from scaling the 
		// recipient ThreeDVector by the numerical parameter
		ThreeDVector operator *(double scalar) const;

		// returns a new ThreeDVector that contains the cross product
		// of the recipient ThreeDVector and the parameter ThreeDVector
		ThreeDVector operator ^(ThreeDVector) const;

	private:
		// coordinates of this ThreeDVector
		double x, y, z;
};

