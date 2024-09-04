// Program: oinks.cxx, by Sergio A. Alvarez
// Two approaches to printing multiple "oink"s recursively 

#include <iostream>
using namespace std;

void oinks(int);
void oinks2(int);
int readInteger(string);

int main() {
        oinks( readInteger("How many oinks? ") );
}

void oinks(int n) {
        if (n <= 0) {
        }
        else {
                cout << "oink ";
                oinks(n-1);
        }
}

void oinks2(int n) {
        if (n > 0) {
                cout << "oink ";
                oinks(n-1);
        }
}

int readInteger(string prompt) {
        cout << prompt;
        int value;
        cin >> value;
        return value;
}

