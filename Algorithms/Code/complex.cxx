// Program: complex.cxx, by Sergio A. Alvarez
// Complex number class with overloaded + and * operators

#include <iostream>
using namespace std;

class Complex {
	private:
		double re;
		double im;
	public:
		Complex::Complex(double real, double imaginary) {
			re = real;
			im = imaginary;
		}

		Complex Complex::operator +(Complex other) {
			return Complex(re + other.re, im + other.im);
		}

		Complex Complex::operator *(Complex b) {
			return Complex(re*b.re - im*b.im, re*b.im + im*b.re);
		}

		void Complex::println() {
			cout << re << " + i*" << im << endl;
		}

};

int main() {
	Complex i = Complex(0, 1);
	i.println();
	(i*i).println();
	(i+i).println();
	return EXIT_SUCCESS;
}

