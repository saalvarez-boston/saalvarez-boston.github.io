// Program: mcIntegral.cxx, by Sergio A. Alvarez
// Approximates the definite integral of x^2 using Monte Carlo simulation

#include <iostream>
using namespace std;

int readInteger(string prompt) {
	cout << prompt;
	int temp;
	cin >> temp;
	return temp;
}

double readDouble(string prompt) {
	cout << prompt;
	double temp;
	cin >> temp;
	return temp;
}

void readParameters(double & a, double & b, int & n) {
	cout << "This program uses Monte Carlo simulation to estimate" << endl;
	cout << "the integral of x^2 over a specified range for x" << endl;
	n = readInteger("Enter number of iterations: ");
	a = readDouble("Enter lower limit for x: ");
	b = readDouble("Enter upper limit for x: ");
}

double square(double x) {
	return x*x;
}

double stdev(int n) {
	return 1.0/sqrt(4.0*n);
}

double monteCarlo(double f(double), double a, double b, int n, double & r) {
	int count = 0;
	double x, y;
	double M = max(f(a), f(b));
	srand(time(0));
	for (int i=0; i<n; i++) {
		x = a + (b-a)*rand()/double(RAND_MAX);
		y = M*rand()/double(RAND_MAX);
		if (y <= f(x))
			count++;
	}
	r = M*(b-a)*stdev(n);
	return M*(b-a)*count/(double)n;
}

void reportResults(double pEstimate, double a, double b, int n, double r) {
	cout << "Monte Carlo estimate of the integral of x^2" << endl;
	cout << "from x=" << a << " to x=" << b; 
	cout << " based on " << n << " iterations is ";
	cout << pEstimate << endl;
	cout << "95% confidence interval for estimate is ";
	cout << "[" << pEstimate - 2*r << ",";
	cout << pEstimate + 2*r << "]" << endl;
}

int main() {
	int n; double a, b, radius;
	readParameters(a, b, n);
	double estimate = monteCarlo(&square, a, b, n, radius);
	reportResults(estimate, a, b, n, radius);
	return EXIT_SUCCESS;
}

