// Program: ThreeDVector.cxx, by Sergio A. Alvarez
// Implementation file for a 3-d vector class with overloaded 
// + (sum), * (dot product), and ^ (cross product) operators

#include <iostream>
#include "ThreeDVector.h"
using namespace std;

        /**
        * constructors
        */
                // creates a ThreeDVector with the given coordinates
		ThreeDVector::ThreeDVector(double first, double second, double third) {
			x = first; y = second; z = third;
		}

        /**
        * selectors
        */
                // returns the length (magnitude) of the recipient ThreeDVector
		double ThreeDVector::length() const {
			return sqrt(x*x + y*y + z*z);
		}

                // displays the coordinates of the recipient ThreeDVector
		void ThreeDVector::println() const {
			cout << "(" << x << ", " << y << ", " << z << ")" << endl;
		}

                // returns the first coordinate of the recipient ThreeDVector
                double ThreeDVector::getFirst() const {
			return x;
		}

                // returns the second coordinate of the recipient ThreeDVector
                double ThreeDVector::getSecond() const {
			return y;
		}

                // returns the third coordinate of the recipient ThreeDVector
                double ThreeDVector::getThird() const {
			return z;
		}

                // returns a new ThreeDVector that contains the vector sum of
                // the recipient ThreeDVector and the parameter ThreeDVector
		ThreeDVector ThreeDVector::operator +(ThreeDVector other) const {
			return ThreeDVector(x + other.x, y + other.y, z + other.z);
		}

                // returns the dot product of the recipient ThreeDVector
                // and the parameter ThreeDVector
		double ThreeDVector::operator *(ThreeDVector b) const {
			return x*b.x + y*b.y + z*b.z;
		}

                // returns a new ThreeDVector resulting from scaling the
                // recipient ThreeDVector by the numerical parameter
		ThreeDVector ThreeDVector::operator *(double scalar) const {
			return ThreeDVector(scalar*x, scalar*y, scalar*z);
		}


                // returns a new ThreeDVector that contains the cross product
                // of the recipient ThreeDVector and the parameter ThreeDVector
		ThreeDVector ThreeDVector::operator ^(ThreeDVector b) const {
			return ThreeDVector(y*b.z - z*b.y, -(x*b.z - z*b.x), x*b.y - y*b.x);
		}

