// File: Accumulator.cxx, by Sergio A. Alvarez
// Sample class with operator overloading

#include <iostream>
using namespace std;

class Accumulator {
	public:
		Accumulator(int amount) {
			total = amount;
		}
		int operator += (int delta) {
			total += delta;
			return total;
		}
		void printlnTotal() {
			cout << total << endl;
		}
	private:
		int total;
};

int main() {
	Accumulator a = Accumulator(5);
	cout << "accumulator starts at ";
	a.printlnTotal();
	cout << "adding 2..." << endl;
	a += 2;
	cout << "sum is now ";
	a.printlnTotal();
	cout << "adding 17..." << endl;
	a += 17;
	cout << "sum is now ";
	a.printlnTotal();
	return EXIT_SUCCESS;
}

