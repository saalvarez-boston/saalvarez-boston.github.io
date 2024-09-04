#include <iostream>
#include "List.h"
using namespace std;

int readInteger(string prompt) {
	int value;
	cout << prompt;
	cin >> value;
	return value;
}

int main() {
	List seq = List(5);
	cout << "New List created" << endl;
	cout << "List contains: ";
	seq.println();
	cout << "List has length " << seq.length() << endl;
	int elem = readInteger("Enter an integer to add to the list: ");
	seq.append(elem);
	cout << "Added " << elem << " to list" << endl;
	cout << "List contains: ";
	seq.println();
	cout << "List has length " << seq.length() << endl;
	return EXIT_SUCCESS;
}

