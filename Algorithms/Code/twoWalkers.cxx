// twoWalkers.cxx, by Sergio A. Alvarez
// Sample client program of the OneDWalker class.
// Random race between two OneDWalkers.

#include <iostream>
#include "OneDWalker.h"
using namespace std;

bool reachedGoal(OneDWalker w) {
	return w.getLocation() < 5 || w.getLocation() > 75;
}

int main() {
	cout << "Welcome to the random race!" << endl;
	cout << "Random walker r will race random walker s" << endl;
	cout << "Whichever racer reaches one of the edges of the screen first, wins!" << endl;
	cout << "Press enter to start the race" << endl;
	char s;
	cin.get(s);
	OneDWalker speedy = OneDWalker();
	OneDWalker racer = OneDWalker();
	while (!reachedGoal(speedy) && !reachedGoal(racer)) {
		speedy.step();
		speedy.drawLocation("s");
		racer.step();
		racer.drawLocation(string("r"));
	}
	if (!reachedGoal(speedy))
		cout << endl << "r wins!" << endl;
	else if (!reachedGoal(racer))
		cout << endl << "s wins!" << endl;
	else
		cout << endl << "it's a tie!" << endl;
	return EXIT_SUCCESS;
}

