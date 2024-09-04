// Program: balancedParens.cxx, by Sergio A. Alvarez
// Uses a stack to determine whether the parentheses are balanced
// in a string containing a parenthesized arithmetic expression 

#include <iostream>
#include "Stack.h"
using namespace std;

bool isBalanced(string expr);
string readLine(string prompt);

int main() {
	if (isBalanced(readLine("Enter a parenthesized expression to test: ")))
		cout << "Nicely done - parentheses are balanced!" << endl;
	else
		cout << "Parentheses are unbalanced!" << endl;
	return EXIT_SUCCESS;
}

bool isBalanced(string expr) {
	Stack<char> s;
	for (int pos=0; pos<expr.length(); pos++)
		if (expr[pos]=='(')
			s.push(expr[pos]);
		else if (expr[pos]==')')
			if (!s.isEmpty())
				s.pop();
			else
				return false;
	return s.isEmpty();
}

string readLine(string prompt) {
	cout << prompt;
	string s;
	getline(cin, s, '\n');
	return s;
}

