#include <unordered_map>
#include "main.h"

/**
 * Marlon van der Linde <marlonv@protonmail.com>
 * Collatz Conjecture for U*****c.
 */

using namespace std;

/**
 * Ubiquotous main boilerplate.
 */
int main(int argc, char* argv[]) {
    auto usage = []() {
        cerr << "collatzA - Collatz Conjecture Term Calculator" << endl
            << "\tusage: collatzA <integer upperlimit larger than 0>" << endl;
    };

    if ((argc != 2) || (atoi(argv[1]) < 1)) {
        usage();
        return EXIT_FAILURE;
    }

    cout << "Concluded max terms: " << countTerms(atoi(argv[1]));
    return EXIT_SUCCESS;
}

int64_t countTerms(int64_t max) {
    int64_t count = 0;
    int64_t memo;

    for (int64_t i = 1; i <= max; i++) {
        memo = colCalc(i, 1);
        if (memo > count) {
            count = memo;
        }
    }
    return count;
}

int64_t colCalc(int64_t number, int64_t count)
{
    if (number == 1) {
        return count;
    } else if ( number % 2 == 0) {
        number = number / 2;
        colCalc(number, count+1);
    } else {
        number = number * 3 + 1;
        colCalc(number,count+1);
    }
    return colCalc(number, count+1);
}

