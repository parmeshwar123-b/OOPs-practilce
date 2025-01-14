/*   Write a C++ program to allocate memory using new operator.  */

#include <iostream>

using namespace std;

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;
    int* arrayPtr = new int[size];
    for (int i = 0; i < size; ++i) {
        arrayPtr[i] = i + 1; 
    }

    cout << "Values in dynamically allocated array: ";
    for (int i = 0; i < size; ++i) {
        cout << arrayPtr[i] << " ";
    }
    delete[] arrayPtr;  // free memory allocated 

    return 0;
}

