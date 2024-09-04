// walkerClient.cxx, by Sergio A. Alvarez
// Sample client program of the OneDWalker class.
// Creates and moves a OneDWalker.

#include <iostream>
#include "OneDWalker.h"
using namespace std;

bool hitMiddle(OneDWalker w) {
        return round(w.getLocation())==40;
}

int main() {
        cout << endl << "This program moves a random walker until it" << endl;
        cout << "reaches the middle of the screen." << endl;
        OneDWalker middler = OneDWalker();
        int steps = 0;
        while (!hitMiddle(middler)) {
                middler.step();
                middler.drawLocation("*");
                steps++;
        }
        cout << endl << "Done! That took " << steps << " steps" << endl;
        return EXIT_SUCCESS;
}

