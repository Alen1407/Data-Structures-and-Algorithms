#include <iostream>
#include "vector.h"
#include <chrono>

using namespace std;

int main() {
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::duration<double, std::milli> duration;

    // Measure pushing elements
    for (size_t n = 1000; n <= 100000; n *= 10) {
        Vector<int> vector;
        begin = std::chrono::steady_clock::now();

        for (int i = 0; i < n; i++) {
            vector.pushBack(i);
        }

        end = std::chrono::steady_clock::now();
        duration = end - begin;
        std::cout << "Execution time for pushing " << n << " elements to Vector: "
                  << duration.count() << " milliseconds" << std::endl;
    }

    // Measure searching for an element
    for (size_t n = 1000; n <= 100000; n *= 10) {
        Vector<int> vector;
        for (int i = 0; i < n; i++) {
            vector.pushBack(i);
        }

        begin = std::chrono::steady_clock::now();
        size_t index = vector.search(n - 1);  // Search for the value (n-1)
        end = std::chrono::steady_clock::now();
        duration = end - begin;
        if (index != vector.getSize()) {
            std::cout << "Element found at index " << index << " in a Vector of size " << n << std::endl;
        } else {
            std::cout << "Element not found in a Vector of size " << n << std::endl;
        }
        std::cout << "Execution time for searching an element in a Vector of size " << n << ": "
                  << duration.count() << " milliseconds" << std::endl;
    }

    // Measure deleting an element
    for (size_t n = 1000; n <= 100000; n *= 10) {
        Vector<int> vector;
        for (int i = 0; i < n; i++) {
            vector.pushBack(i);
        }

        begin = std::chrono::steady_clock::now();
        vector.deleteElement(n - 1);  // Delete the last element
        end = std::chrono::steady_clock::now();
        duration = end - begin;
        std::cout << "Execution time for deleting an element from a Vector of size " << n << ": "
                  << duration.count() << " milliseconds" << std::endl;
    }

    return 0;
}

