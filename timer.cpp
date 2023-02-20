#include "timer.h"

// Default constructor
timer::timer() {
    running = false;
}

// Copy constructor
timer::timer(timer& t) {
    running = t.running;
    start_time = t.start_time;
    stop_time = t.stop_time;
}

// Start the timer
void timer::start() {
    if (!running) {
        running = true;
        start_time = steady_clock::now();
    }
}

// Stop the timer
void timer::stop() {
    if (running) {
        running = false;
        stop_time = steady_clock::now();
    }
}

// Get the time elapsed since the timer was started, in seconds
double timer::getTime() {
    // Cast the intrinsic duration to seconds, but use a double so that we can
    // have fractional seconds to represent value more precisely (i.e. microseconds)
    return duration_cast<duration<double> >(stop_time - start_time).count();
}

// Overloaded << operator to print the time elapsed in seconds
ostream& operator<<(ostream& out, timer& t) {
    return out << to_string(t.getTime());
}
