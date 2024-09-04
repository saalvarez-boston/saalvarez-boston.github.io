// Program: reverse.cxx, by Sergio A. Alvarez
// Recursively reverses a string in two different ways:
// the first version prints the characters in reverse order,
// the second version assembles the reversed string and prints it

#include <iostream>
using namespace std;

void printReverse(string);
void printReverse2(string);
string reverse(string);
string readString(string prompt);

int main() {
	cout << "This program reverses a string in two different ways" << endl;
	printReverse( readString("Enter a string: ") );
	cout << endl;
	cout << reverse(readString("Enter a string: ")) << endl;
}

void printReverse(string s) {
	if (s.length() == 0) {
	}
	else {
		cout << s.substr(s.length()-1, 1);
		printReverse(s.substr(0, s.length()-1));
	}
}

// cleaner way to write the printReverse function
void printReverse2(string s) {
	if (s.length() > 0) {
		cout << s.substr(s.length()-1, 1);
		printReverse(s.substr(0, s.length()-1));
	}
}

// note below in the reverse function that you can *not* omit the base case 
// as in the second version printReverse2 above; that is because the reverse
// function below *must* explicitly return an empty string in the base case
string reverse(string s) {
	if (s.length() == 0) 
		return "";
	else 
		return s.substr(s.length()-1, 1) + reverse( s.substr(0, s.length()-1) );
}

string readString(string prompt) {
        cout << prompt;
        string value;
        cin >> value;
        return value;
}

