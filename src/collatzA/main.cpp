#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

/**
 * Marlon van der Linde <marlonv@protonmail.com>
 * Collatz Conjecture for U*****c.
 */

using namespace std;

int calCol(int limit);
int unravel(int unravel);
void dumpMap(unordered_map<int, int> map2dump);
int* findLargestTermCount(unordered_map<int, int> searchMap);

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
int calCol(int limit) {
    unordered_map<int, int> numberToTermMap;

    for (int i = 1; i <= limit; i++) {
        int result = unravel(i);
        if (result > 0) {
            numberToTermMap[i] = result;
        }
    }

    int* maxes;
    maxes = findLargestTermCount(numberToTermMap);
    cout << "Concluded largest term chain is for number " << maxes[1] << " with " << maxes[0]
        << " terms" << endl;

    return maxes[0];
}

/**
 * Isolating function for breaking up a positive number into a number of terms up to ...
 * @param int unravel A positive number to break into a collatz sequence
 */
int unravel(int num) {
    std::vector<int> pTerms;
    int termCount = 1;  // I start counting terms at 1, as the starting number is one of the terms.

    do {
        if (num == 1) {
            termCount++;
            break;
        }

        if (num % 2 == 0) {
            num = num / 2;
            termCount++;
        } else {
            num = 3 * num + 1;
            termCount++;
        }

        pTerms.push_back(num);
    } while (num > 1);

    pTerms.resize(termCount);
    return termCount;
}

/**
 * Finds the largest term count for a given starting number
 */
int * findLargestTermCount(unordered_map<int, int> searchMap) {
    static int maxes[2];
    for ( auto it = searchMap.begin(); it != searchMap.end(); ++it ) {
        if (it->second > maxes[0]) {
            maxes[0] = it->second;
            maxes[1] = it->first;
        }
    }
    return maxes;
}

/**
 * A development function for me to see what's in the map.
 */
void dumpMap(unordered_map<int, int> map2dump) {
    cout << "dumping: " << endl;
    for ( auto it = map2dump.begin(); it != map2dump.end(); ++it ) {
        cout << "-- " << it->first << ":" << it->second;
        cout << endl;
    }
}




