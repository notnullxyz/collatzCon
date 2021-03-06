#include <unordered_map>
#include "main.h"

/**
 * Marlon van der Linde <marlonv@protonmail.com>
 * Collatz Conjecture for U*****c.
 */

using namespace std;
map<long, long> memo;


/**
 * Ubiquotous main boilerplate.
 */
int main(int argc, char* argv[]) {

    auto usage = []() {
        cout << "collatzA - Collatz Conjecture Term Calculator" << endl;
        cerr << "\tusage: collatzA <integer upperlimit larger than 0>" << endl;
    };

    if ((argc != 2) || (atoi(argv[1]) < 1)) {
        usage();
        return -1;
    }

    calCol(atoi(argv[1]));
    return 0;
}

/**
 * The main calculation loop to determine the longest Collatz (number of terms) up to the specified upper limit.
 * @param int limit The upper limit of number to break down into their respective collatz sequences.
 * @return int Largest term count
 */
long calCol(long limit) {
    unordered_map<long , long> numberToTermMap;

    for (long i = 1; i <= limit; i++) {
        long result = unravel(i);

        if (result > 0) {
            numberToTermMap[i] = result;
        }
    }

    unsigned long* maxes;
    maxes = findLargestTermCount(numberToTermMap);

    cout << "Concluded largest term chain is for number " << maxes[1] << " with " << maxes[0]
        << " terms" << endl;

    return maxes[0];
}

/**
 * Isolating function for breaking up a positive number into a number of terms up to ...
 * @param int unravel A positive number to break into a collatz sequence
 */
long unravel(long num) {
    long termCount = 1L;  // I start counting terms at 1, as the starting number is one of the terms.

    do {
        if (num == 1L) {
            break;
        }

        if (memo[num]) {
            num = memo[num];
        } else {
            long x = (num % 2 == 0) ? num / 2 : 3 * num + 1;
            memo.insert(pair<long, long>(num, x));
            num = x;
        };

        termCount++;
    } while (num > 1L);

    return termCount;
}

/**
 * Finds the largest term count for a given starting number
 */
unsigned long * findLargestTermCount(unordered_map<long, long> searchMap) {
    static unsigned long maxes[2];
    for ( auto it = searchMap.begin(); it != searchMap.end(); ++it ) {
        if (it->second > maxes[0]) {
            maxes[0] = it->second;
            maxes[1] = it->first;
        }
    }
    return maxes;
}





