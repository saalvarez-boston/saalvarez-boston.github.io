// Program: countOccurrences, by Sergio A. Alvarez
// Counts the number of times that a target string occurs as a 
// substring of a given string, using the string member function find

#include <iostream>
using namespace std;

size_t numOccurrences(string s, string pattern);
void printReverse(string);
string reverse(string);
string readString(string prompt);

int main() {
	cout << "This program counts the occurrences of a target string within a search string" << endl;
	string s = readString("Enter the string in which to search: ");
	string p = readString("Enter the target substring: ");
	cout << "Number of occurrences is " << numOccurrences(s, p) << endl;
}

void printReverse(string s) {
	if (s.length() == 0) {
	}
	else {
		cout << s[s.length()-1];
		printReverse(s.substr(0, s.length()-1));
	}
}

string reverse(string s) {
	if (s.length() == 0) {
		return "";
	}
	else {
		return s.substr(s.length()-1, 1) + reverse( s.substr(0, s.length()-1) );
	}
}

size_t numOccurrences(string s, string pattern) {
	int count = 0;
	int low = s.find(pattern, 0);
	while (low != string::npos) {
		count++;
		low = s.find(pattern, low+1);
	}
	return count;
}

string readString(string prompt) {
	cout << prompt;
	string s; 
	getline(cin, s, '\n');
	return s;
}

// the following is an alternate version of readString
string readString2(string prompt) {
	cout << prompt;
	string s; 
	char token;
	cin.get(token);
	while (token != '\n') {
		s += string(1, token);
		cin.get(token);
	}
	return s;
}

