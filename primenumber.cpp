#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is prime or not
bool checkprime(unsigned int n) {
    if (n <= 1) {
        // 0 and 1 are not prime numbers
        return false;
    }
    
    // Create a boolean vector to mark the numbers from 0 to n
    vector<bool> is_prime(n + 1, true);
    
    // Mark 0 and 1 as not prime
    is_prime[0] = false;
    is_prime[1] = false;
    
    // Iterate over all the numbers from 2 to the square root of n
    for (unsigned int i = 2; i * i <= n; i++) {
        // If i is prime, mark all its multiples as not prime
        if (is_prime[i]) {
            for (unsigned int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // Return whether n is prime or not
    return is_prime[n];
}

// Function to get the next prime number greater than n
int getNextPrime(unsigned int n) {
    while (!checkprime(++n));
    // Return the next prime number
    return n;
}
