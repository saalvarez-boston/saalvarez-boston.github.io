// OneDWalkerProgram.cxx, by Sergio A. Alvarez
// A C++ class whose instances represent point objects that move randomly 
// along a line. Includes a main function that creates a OneDWalkerProgram 
// instance and then moves it 30 times.

#include <iostream>
using namespace std;

class OneDWalkerProgram {
	private:
		double x, dx;
	public:

		static const int DEFAULT_LOCATION = 50;
		static const int AVERAGE_SPEED = 5;

		OneDWalkerProgram::OneDWalkerProgram() {
			this->x = DEFAULT_LOCATION;
			srand(time(0));
			this->changeSpeed();
		}

		double OneDWalkerProgram::getLocation() {
			return this->x;
		}

		void OneDWalkerProgram::printLocation() {
			printf("%f", this->getLocation());
		}

		void OneDWalkerProgram::drawLocation() {
			string s = "";
			for (int pos=0; pos<this->getLocation(); pos++)
				s += " ";
			cout << s << "*" << endl;
		}

		void OneDWalkerProgram::changeSpeed() {
			this->dx = 2*AVERAGE_SPEED*(rand()/(double)RAND_MAX-0.5);
		}

		void OneDWalkerProgram::step() {
			this->x += this->dx;
			this->changeSpeed();
		}

};

		int main() {
			OneDWalkerProgram zippy = OneDWalkerProgram();
			cout << "Starting location is "; 
			zippy.printLocation();
			cout << endl;
			for (int tick=0; tick<30; tick++) {
				zippy.step();
				zippy.drawLocation();
			}
			return EXIT_SUCCESS;
		}

