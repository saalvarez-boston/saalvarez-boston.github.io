// Clock.cxx, by Sergio A. Alvarez
// A simple C++ class that represents a (static) clock
// that reports times in an hour:minutes text format.
// You have to set and advance the time on the clock.
// A sample main function is included that sets the time
// to 11:45 and advances the time minute by minute for 30 minutes.
// Provided merely as an example of objected-oriented syntax in C++.

#include <iostream>
using namespace std;

class Clock {
        private:
                int minutesSinceMidnight;
        public:
                Clock::Clock(int hour, int minutes) {
                        this->minutesSinceMidnight = (hour%12)*60 + minutes;
                }

                int Clock::getHour() {
                        int hr = (this->minutesSinceMidnight/60)%12;
                        if (hr==0)
                                hr = 12;
                        return hr;
                }

                int Clock::getMinutes() {
                        return (this->minutesSinceMidnight)%60;
                }

                void Clock::advanceMinutes(int howMany) {
                        this->minutesSinceMidnight += howMany;
                }

                void Clock::println() {
                        if (this->getMinutes() < 10)
                                printf("%d:0%d\n", this->getHour(), this->getMinutes());
                        else
                                printf("%d:%d\n", this->getHour(), this->getMinutes());
                }

};

                int main() {
                        Clock tocker = Clock(11, 45);
                        cout << "Start time is ";
                        tocker.println();
                        for (int tick=0; tick<30; tick++) {
                                tocker.advanceMinutes(1);
                                cout << "Time is now ";
                                tocker.println();
                        }
                        return EXIT_SUCCESS;
                }


