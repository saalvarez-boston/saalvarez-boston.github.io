// Program: stackOfChars.cxx, by Sergio A. Alvarez
// Sample client program of the Stack<Item> template class

#include <iostream>
#include "Stack.h"
using namespace std;

string readLine(string prompt);

int main() {
	Stack<char> s;
	string text = readLine("Enter some text: ");
	for (size_t pos=0; pos<text.length(); pos++)
		s.push(text[pos]);
	cout << "Text stored on stack as ";
	s.println();
	for (size_t pos=0; pos<text.length(); pos++) {
		cout << "Comparing " << s.top() << " with " << text[pos] << endl;
		if (s.top() != text[pos]) {
			cout << "Sorry, that's not a symmetric string" << endl;
			return EXIT_SUCCESS;
		}
		cout << "\tCharacters match" << endl;
		s.pop();
		cout << "Popping stack top: ";
		s.println();
		cout << "Original text remaining: ";
		cout << text.substr(pos+1, text.length()-pos) << endl;
	}
	cout << "Yes - a symmetric string!" << endl;
	return EXIT_SUCCESS;
}

string readLine(string prompt) {
	cout << prompt;
	string s;
	getline(cin, s, '\n');
	return s;
}

