#include <iostream>
#include "List.h"
#include <chrono>

using namespace std;

void measureInsertionTime(LinkedList& linkedList, int numElements) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Call the function
    for (int i = 0; i < numElements; i++) {
        linkedList.insert(i);
    }

    // End the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Compute the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - begin;

    // Print the execution time
    std::cout << "Execution time for inserting " << numElements << " elements: "
              << duration.count() << " milliseconds" << std::endl;
}

void measureSearchTime(LinkedList& linkedList, int searchValue) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Call the function
    linkedList.search(searchValue);

    // End the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Compute the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - begin;

    // Print the execution time
    std::cout << "Execution time for searching " << searchValue << " in the list: "
              << duration.count() << " milliseconds" << std::endl;
}

void measureClearTime(LinkedList& linkedList) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Call the function
    linkedList.clear();

    // End the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Compute the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - begin;

    // Print the execution time
    std::cout << "Execution time for clearing the list: "
              << duration.count() << " milliseconds" << std::endl;
}

int main() {
    LinkedList linkedList;

    measureInsertionTime(linkedList, 1000);
    measureClearTime(linkedList);

    measureInsertionTime(linkedList, 10000);
    measureClearTime(linkedList);

    measureInsertionTime(linkedList, 100000);
    measureSearchTime(linkedList, 99999);
    measureClearTime(linkedList);

    return 0;
}
