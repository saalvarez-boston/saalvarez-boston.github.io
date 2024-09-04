// File: euclidGCD.cxx, by Sergio A. Alvarez
// Times Euclid's gcd algorithm on pseudorandom data

#include <iostream>
using namespace std;

// number of tests over which to average the execution time
const int numaverage = 1000000;

// prints string prompt and returns integer entered by user
int getInteger(string prompt) {
   cout << prompt;
   int num;
   cin >> num;
   return num;
}

// the classical gcd algorithm as described in class
int Euclid(int m, int n) {
   int temp;
   while (m>0) {
      temp = m;
      m = n%m;
      n = temp;
   }
   return n;
}

int main() {
   cout << "This program tests Euclid's gcd algorithm on random data" << endl;
   cout << "WARNING: the C++ pseudorandom number generator on the current\n";
   cout << "platform limits the effective maximum digit count to ";
   cout << int(log10((double)RAND_MAX)) << "." << endl;
   cout << "Greater digit counts will yield incorrect test results." << endl;
   int maxlog = getInteger("Enter maximum number of digits to be used: ");
   srand(time(0));       // seed pseudorandom number generator
   clock_t start, stop;  // timing variables
   int maxnum, m, n, gcd;// numerical variables
   for (int i=1; i<=maxlog; i++) {
      cout << "For " << i << "-digit numbers:" << endl;
      maxnum = int(pow(10,(double)i));
      start = clock();   // start timing
      for (int j=0; j<numaverage; j++) {
         m = rand() % maxnum;  // generate pseudorandom data
         n = rand() % maxnum;  // as inputs to Euclid gcd function
         gcd = Euclid(m, n);
      }
      stop = clock();    // end timing
      cout << "Time in seconds averaged over " << numaverage << " tests: ";
      cout << double(stop-start)/double(CLOCKS_PER_SEC)/double(numaverage);
      cout << endl;
   }
   return EXIT_SUCCESS;
}
