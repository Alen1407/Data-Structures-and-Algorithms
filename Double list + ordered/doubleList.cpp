#include <iostream>
#include "doubleList.h"

using namespace std;

int main(){
    DoubleList d1;
    d1.insert(99);
    d1.insert(1);
    d1.insert(16);
    d1.insert(5);
    d1.insert(6);
    d1.insert(3);
    d1.insert(14);
    d1.insert(12);
    d1.insert(11);
    d1.insert(11);
    d1.print();
    cout << endl;
    d1.printByValue();
    cout << endl;
    cout << d1.contains(14) << endl;
    cout << d1.contains(4) << endl;
    d1.remove(99);
    d1.remove(11);
    d1.print();
    cout << endl;
    d1.printByValue();
    cout << endl;
    cout << d1.search(11) << endl;

    return 0;
}