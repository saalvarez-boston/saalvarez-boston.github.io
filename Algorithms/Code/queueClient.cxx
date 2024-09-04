// Program: queueClient.cxx, by Sergio A. Alvarez
// Sample client program of the Queue class

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q;
	cout << "Enter words on separate lines, followed by END" << endl;
	string word;
	cin >> word;
	while (word != "END") {
		q.insert(word);
		cout << "Queue now contains ";
		q.println();
		cout << "Queue has length " << q.size() << endl;
		cin >> word;
	}
	cout << "Text stored in queue as ";
	q.println();
	while (!q.isEmpty()) {
		cout << "Removing element at front of queue" << endl;
		q.remove();
		cout << "Queue now contains ";
		q.println();
		cout << "Queue has length " << q.size() << endl;
	}
	return EXIT_SUCCESS;
}


