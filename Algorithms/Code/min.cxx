// Program: min.cxx, by Sergio A. Alvarez
// Finds the minimum value in a random array of Items.
// Illustrates template functions.

#include <iostream>
using namespace std;

template <class Item>
// assumes that the array a is nonempty
Item smallest(Item* a, int length) {
	Item bestSoFar = a[0];
	for (int pos=1; pos<length; pos++)
		if (a[pos] < bestSoFar)
			bestSoFar = a[pos];
	return bestSoFar;
}

template <class Item>
void printlnArray(Item* a, int length) {
	for (int pos=0; pos<length-1; pos++)
		cout << a[pos] << ", ";
	cout << a[length-1] << endl;
}

int main() {
	double* values = new double[5];
	srand(time(0));
	for (int pos=0; pos<5; pos++)
		values[pos] = rand()/(double)RAND_MAX;
	cout << "Random array generated: ";
	printlnArray(values, 5);
	cout << "Smallest value in array is " << smallest(values, 5) << endl;
	string* words = new string[4];
	words[0] = "once";
	words[1] = "upon";
	words[2] = "a";
	words[3] = "time";
	cout << "Words array generated: ";
	printlnArray(words, 4);
	cout << "Smallest value in array is " << smallest(words, 4) << endl;
	return EXIT_SUCCESS;
}

