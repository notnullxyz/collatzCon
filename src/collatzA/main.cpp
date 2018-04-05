#include <iostream>
#include <stdlib.h>

/**
 * Marlon van der Linde <marlonv@protonmail.com>
 * Collatz Conjecture for U*****c.
 */

using namespace std;

int calCol(int limit);

/**
 * Ubiquotous main boilerplate.
 */
int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "usage: collatzA <integer upperlimit>\n";
        return -1;
    }

    calCol(atoi(argv[1]));

    return 0;
}

/**
 * The main calculation loop to determine the longest Collatz (number of terms) up to the specified upper limit.
 */
int calCol(int limit) {
    cout << limit;
    return limit;
}

