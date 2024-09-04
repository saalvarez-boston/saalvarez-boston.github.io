// Program: RabinKarp.cxx, by Sergio A. Alvarez
// Rabin-Karp string matching

#include <iostream>
using namespace std;

class RabinKarpMatcher {

	public:

	// prime to be used for modular arithmetic calculations
	static const int q = 11;

	// number of symbols in the admissible alphabet
	static const int d = 4;

	// Creates a matcher for a given text string
	RabinKarpMatcher::RabinKarpMatcher(string text) {
		this -> text = string(text);
	}

	// returns the index of the first occurrence of the argument
	// as a substring of the recipient, or -1 if no such occurrences exist
	void RabinKarpMatcher::findOccurrences(string pattern) {
		int n = text.length();
		int m = pattern.length();
		int h = power(d, m-1, q); // computes power mod q
		int p = 0;
		int t = 0;
		for (size_t i = 0; i < m; i++) {
			p = (d*p + valueOf(pattern[i])) % q;
			t = (d*t + valueOf(text[i])) % q;
		}
		int matches = 0;
		for (size_t s = 0; s <= n-m; s++) {
			if (p == t) 
				if (pattern == text.substr(s,m)) {
					matches++;
					cout << "true match at shift " << s << endl;
				}
			t = (d*(t - valueOf(text[s])*h) + valueOf(text[s+m])) % q;
			if (t < 0) // needed to bring remainder into range 0...q-1
				t += q;
		}
		cout << matches << " matches found" << endl;
	}

	private:

	string text;

	int valueOf(char c) {
		if (c=='A')
			return 0;
		else if (c=='C')
			return 1;
		else if (c=='G')
			return 2;
		else if (c=='T')
			return 3;
		else
			return (size_t) c;
	}

	int valueOf(string s) {
		size_t value = 0;
		for (int pos=0; pos<s.length(); pos++)
			value = (d*value + valueOf(s[pos])) % q;
		return value;
	}

	int power(size_t base, size_t exp, size_t q) {
		if (exp == 0)
			return 1;
		size_t temp = power(base, exp/2, q) % q;
		if (exp%2 == 0) 
			return (temp*temp) % q;
		else
			return ((base%q)*temp*temp)%q;
	}

};

string getString(string prompt) {
	cout << prompt;
	string s;
	getline(cin, s, '\n');
	return s;
}

int main() {
	string text = getString("Enter text: ");
	string pattern = getString("Enter target substring: ");
	RabinKarpMatcher comp = RabinKarpMatcher(text);
	comp.findOccurrences(pattern);
	return EXIT_SUCCESS;
}

