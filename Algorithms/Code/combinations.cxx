// Program: combinations.cxx, by Sergio A. Alvarez
// Two recursive ways to compute n choose k.
// Note that the second version (combo2), which
// uses the factorial function, is prone to overflow.

#include <iostream>
#include "io.h"
using namespace std;

int combos(int, int);
int combos2(int, int);
int factorial(int);

int main() {
	cout << "This program computes n choose k" << endl;
	int n = readInteger("Enter n: "); 
	int k = readInteger("Enter k: ");
	cout << combos(n, k) << endl;
	cout << combos2(n, k) << endl;
}

int combos(int n, int k) {
	if (k <= 0 || k >= n) 
		return 1;
	else 
		return combos(n-1, k) + combos(n-1, k-1);
}

int combos2(int n, int k) {
	return factorial(n)/factorial(k)/factorial(n-k);
}

int factorial(int n) {
	if (n <= 0)
		return 1;
	else
		return n*factorial(n-1);
}

