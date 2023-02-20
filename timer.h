// This timer typically has 1/1000000 second (1 micro-second) accuracy
// under most Linux distributions

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <string>
#include <chrono> // C++ standard library for time-related functionality

using namespace std;
using namespace std::chrono;

class timer {
public:
    // Default constructor
    timer();

    // Copy constructor
    timer(timer& myTimer);

    // Starts the timer
    void start();

    // Stops the timer
    void stop();

    // Returns the time elapsed, in seconds
    double getTime();

private:
    // Variables to hold the start and stop time points, and whether the timer is running
    steady_clock::time_point start_time, stop_time;
    bool running;
};

// Overloaded output stream operator to print the elapsed time as a string
ostream& operator<<(ostream& theStream, timer& theTimer);

#endif

