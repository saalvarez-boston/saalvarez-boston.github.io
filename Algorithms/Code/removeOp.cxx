// Program: removeOp.cxx, by Sergio A. Alvarez
// Operator overloading version of the remove.cxx program
// Recursively removes all occurrences of a target substring from a base string

#include <iostream>
using namespace std;

class Superstring {

	public:

	Superstring(string s) {
		base = s;
	}

	string operator -(string target) {
        	size_t findPos = base.find(target, 0);
        	if (findPos==string::npos)
                	return base;
        	string prefix = base.substr(0, findPos);
        	string suffix = base.substr(findPos+target.length(), base.length()-target.length());
        	return prefix + (Superstring(suffix) - target);
	}

	private:
	string base;

};

string readString(string prompt) {
        cout << prompt;
        string s;
        getline(cin, s, '\n');
        return s;
}

int main() {
	Superstring s = Superstring(readString("Enter text: "));
	string t = readString("Enter target subtext: ");
	cout << "After removal: " << s - t << endl;
	return EXIT_SUCCESS;
}

