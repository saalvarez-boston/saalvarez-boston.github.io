// timer.cxx, by Sergio A. Alvarez
// Example of working with real time via the system clock

#include <iostream>
using namespace std;

int main() {
	time_t timeNow, startSeconds;
	while (true) {
		startSeconds = timeNow;
		while (startSeconds==timeNow) 
			time(&timeNow);
		cout << ctime(&timeNow) << endl;
	}
	return EXIT_SUCCESS;
}

