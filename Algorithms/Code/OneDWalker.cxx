// OneDWalker.cxx, by Sergio A. Alvarez
// Implementation file for the OneDWalker class.

#include <iostream>
#include "OneDWalker.h"
using namespace std;

OneDWalker::OneDWalker() {
	this->x = DEFAULT_LOCATION;
	srand(time(0));
	this->changeSpeed();
}

double OneDWalker::getLocation() const {
	return this->x;
}

void OneDWalker::printLocation() const {
	printf("%f", this->getLocation());
}

void OneDWalker::drawLocation(string label) const {
	string s = "";
	for (int pos=0; pos<this->getLocation(); pos++)
		s += " ";
	cout << s << label << endl;
}

void OneDWalker::step() {
	this->x += this->dx;
	this->changeSpeed();
}

void OneDWalker::changeSpeed() {
	this->dx = 2*AVERAGE_SPEED*(rand()/(double)RAND_MAX-0.5);
}

