// Program: vectorClient.cxx, by Sergio A. Alvarez
// Sample client program of the ThreeDVector class

#include <iostream>
#include "ThreeDVector.h"
using namespace std;

int main() {
	ThreeDVector a = ThreeDVector(1, 0, 0);
	cout << "Vector a has first coordinate " << a.getFirst() << ", second coordinate " << a.getSecond() << ", last coordinate " << a.getThird() << endl;
	cout << "a can also be written as ";
	a.println();
	ThreeDVector b = ThreeDVector(0, 1, 0);
	cout << "Vector b is ";
	b.println();
	cout << "The cross product of a and b is ";
	(a^b).println();
	cout << "The sum of a and b is ";
	(a+b).println();
	cout << "and their dot product is " << a*b << endl;
	cout << "On the other hand, scaling the sum by 3 yields ";
	((a+b)*3).println();
	return EXIT_SUCCESS;
}

