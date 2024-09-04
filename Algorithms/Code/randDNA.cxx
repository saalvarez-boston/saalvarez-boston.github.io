// Program: randDNA.cxx, by Sergio A. Alvarez
// Generates pseudorandom sequences over the alphabet {A, C, G, T}

#include <iostream>
using namespace std;

int getInteger(string prompt) {
	cout << prompt;
	int temp;
	cin >> temp;
	return temp;
}

string randDNA(int n) {
	string s;
	double value;
	for (int i=0; i<n; i++) {
		value = rand()/double(RAND_MAX);
		if (value < 0.25)
			s += "A";
		else if (value < 0.50)
			s += "C";
		else if (value < 0.75)
			s += "G";
		else 
			s += "T";
	}
	return s;
}

void println(string s) {
	cout << s << endl;
}

int main() {
	println( randDNA( getInteger("Enter desired sequence length: ") ) );
	return EXIT_SUCCESS;
}

