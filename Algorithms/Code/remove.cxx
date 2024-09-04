// Program: remove.cxx, by Sergio A. Alvarez
// Recursively removes all occurrences of a target substring from a base string

#include <iostream>
using namespace std;

string remove(string base, string target);
string readString(string prompt);

int main() {
	string s = readString("Enter text: ");
	string t = readString("Enter target subtext: ");
	cout << "After removal: " << remove(s, t) << endl;
	return EXIT_SUCCESS;
}

string remove(string base, string target) {
        size_t findPos = base.find(target, 0);
        if (findPos==string::npos)
                return base;
        string prefix = base.substr(0, findPos);
        string suffix = base.substr(findPos+target.length(), base.length()-prefix.length()-target.length());
        return prefix + remove(suffix, target);
}

string readString(string prompt) {
        cout << prompt;
        string s;
        getline(cin, s, '\n');
        return s;
}

