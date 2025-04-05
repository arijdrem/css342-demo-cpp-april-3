#include <iostream>
using namespace std;

/*
 * Function: isPowerOfTwo_loop
 * Checks if a number is a power of two using a loop.
 * This is the more "manual" version—helped me understand the logic better.
 */
bool isPowerOfTwo_loop(int n) {
    if (n <= 0) return false; // power of 2 must be positive

    // Keep dividing by 2 as long as it's even
    while (n % 2 == 0) {
        n = n / 2;
    }

    // If we end up with 1, it means n was a power of 2
    return n == 1;
}

/*
 * Function: isPowerOfTwo_bitwise
 * Bitwise version of the power of 2 check.
 * I looked this one up and also asked ChatGPT to help me understand the bit trick.
 * It checks if only one bit is set in the number.
 */
bool isPowerOfTwo_bitwise(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

/*
 * Function: test_isPowerOfTwo
 * Just runs test cases for both versions of the function.
 * Based on the in-lecture example and my own additions.
 */
void test_isPowerOfTwo() {
    bool pass = true;

    // Loop version tests
    pass &= isPowerOfTwo_loop(1) == true;
    pass &= isPowerOfTwo_loop(2) == true;
    pass &= isPowerOfTwo_loop(4) == true;
    pass &= isPowerOfTwo_loop(6) == false;
    pass &= isPowerOfTwo_loop(16) == true;
    pass &= isPowerOfTwo_loop(31) == false;
    pass &= isPowerOfTwo_loop(0) == false;
    pass &= isPowerOfTwo_loop(-8) == false;

    // Bitwise version tests (same inputs)
    pass &= isPowerOfTwo_bitwise(1) == true;
    pass &= isPowerOfTwo_bitwise(2) == true;
    pass &= isPowerOfTwo_bitwise(4) == true;
    pass &= isPowerOfTwo_bitwise(6) == false;
    pass &= isPowerOfTwo_bitwise(16) == true;
    pass &= isPowerOfTwo_bitwise(31) == false;
    pass &= isPowerOfTwo_bitwise(0) == false;
    pass &= isPowerOfTwo_bitwise(-8) == false;

    // Only show PASS or FAIL (no extra text, per assignment)
    cout << (pass ? "PASS" : "FAIL") << endl;
}

/*
 * Function: isPrime
 * Returns true if n is a prime number.
 * I wrote this using the logic I remember from Java.
 * Basically checking if anything divides n from 2 up to n-1.
 */
bool isPrime(int n) {
    if (n <= 1) return false; // 0, 1, and negatives are not prime

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false; // divisible by something other than 1 and itself
        }
    }

    return true;
}

/*
 * Function: test_isPrime
 * Runs test cases on the isPrime function and prints PASS or FAIL.
 */
void test_isPrime() {
    bool pass = true;

    pass &= isPrime(2) == true;
    pass &= isPrime(3) == true;
    pass &= isPrime(4) == false;
    pass &= isPrime(5) == true;
    pass &= isPrime(9) == false;
    pass &= isPrime(1) == false;
    pass &= isPrime(0) == false;
    pass &= isPrime(-3) == false;

    cout << (pass ? "PASS" : "FAIL") << endl;
}

int main() {
    test_isPowerOfTwo();
    test_isPrime();
    // reduceFraction test will go here next
    return 0;
}

