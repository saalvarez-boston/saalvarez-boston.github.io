// Program: nchoosek.cxx, by Sergio A. Alvarez
// Dynamic programming computation of combinatorial coefficient n choose k

#include <iostream>
#include "io.h"
using namespace std;

void initialize(int** & values, int n, int k);
void update(int** values, int n, int k);
int nCk(int n, int k);

int main() {
	printString("This program computes n choose k\n");
	int n = readInteger("Enter n: ");
	int k = readInteger("Enter k: ");
	if (n>=0 && k>=0 && k<=n) 
		cout << n << " choose " << k << " equals " << nCk(n, k) << endl;
	else
		cout << "n and k must be non-negative, with k <= n" << endl;
	return EXIT_SUCCESS;
}

void initialize(int** & values, int n, int k) { 
	values = new int*[n+1];
	for (int i=0; i<=n; i++)
		values[i] = new int[k+1];
	for (int i=0; i<=n-k; i++)
		values[i][0] = 1;
	for (int j=0; j<=k; j++)
		values[j][j] = 1;
}

void update(int** values, int n, int k) {
	for (int j=1; j<=k; j++) 
		for (int i=j+1; i<=n-k+j; i++) {
			values[i][j] = values[i-1][j-1] + values[i-1][j];
			cout << "values[" << i << "," << j << "] = ";
			cout << "values[" << i-1 << "," << j-1 << "] + ";
			cout << "values[" << i-1 << "," << j << "] = ";
			cout << values[i][j] << endl;
		}
}

int nCk(int n, int k) {
	int** values;
	initialize(values, n, k);
	update(values, n, k);
	return values[n][k];
}

