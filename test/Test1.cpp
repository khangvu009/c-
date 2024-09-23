#include <iostream>
#include <vector>

void sieveOfEratosthenes(long long upperLimit) {
    // Create a boolean vector to mark numbers as prime or not
    std::vector<bool> isPrime(upperLimit + 1, true);

    // Start with the first prime number (2) and iterate up to the square root of the upper limit
    for (long long currentNumber = 2; currentNumber * currentNumber <= upperLimit; ++currentNumber) {
         if (isPrime[currentNumber]) {
            // Mark all multiples of the current number as not prime
            for (long long multiple = currentNumber * currentNumber; multiple <= upperLimit; multiple += currentNumber) {
                isPrime[multiple] = false;
            }
        }
    }

    // Print the prime numbers up to the specified limit
    std::cout << "Prime numbers up to " << upperLimit << ": ";
    for (long long i = 2; i <= upperLimit; ++i) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    long long upperLimit;

    // Get user input for the upper limit, ensuring it is a positive integer
    do {
        std::cout << "Enter the upper limit for prime numbers (must be a positive integer): ";
        std::cin >> upperLimit;

        if (upperLimit <= 0) {
            std::cout << "Please enter a valid positive integer." << std::endl;
        }
    } while (upperLimit <= 0);

    // Find and display prime numbers using the Sieve of Eratosthenes
    sieveOfEratosthenes(upperLimit);

    return 0;
}

