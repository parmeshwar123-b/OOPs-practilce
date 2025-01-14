/* Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the index set is a set
of consecutive integers starting at 0) except for the following :
1. It performs range checking.
2. It allows one to be assigned to another array through the use of the assignment operator (e.g. cp1=cp2)
3. It supports a function that returns the size of thearray.
4. It allows the reading or printing of array through the use of coutandcin. */

#include <iostream>

using namespace std;

class CppArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    CppArray(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0; 
        }
    }

    // Copy constructor
    CppArray(const CppArray& other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor
    ~CppArray() {
        delete[] arr;
    }

    // Assignment operator
    CppArray& operator=(const CppArray& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;

        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // Range-checked element access
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    int getSize() const {
        return size;
    }

    friend ostream& operator<<(ostream& out, const CppArray& cppArray) {
        for (int i = 0; i < cppArray.size; ++i) {
            out << cppArray.arr[i] << " ";
        }
        return out;
    }

    // Overloaded >> to read the array
    friend istream& operator>>(istream& in, CppArray& cppArray) {
        for (int i = 0; i < cppArray.size; ++i) {
            in >> cppArray.arr[i];
        }
        return in;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    CppArray arr1(size);
    cout << "Enter elements of the array: ";
    cin >> arr1;

    cout << "Elements in arr1: " << arr1 << endl;

    CppArray arr2 = arr1; // Copy constructor
    cout << "Elements in arr2 (after copy): " << arr2 << endl;

    CppArray arr3(size);
    arr3 = arr1; // Assignment operator
    cout << "Elements in arr3 (after assignment): " << arr3 << endl;

    try {
        cout << "Accessing element at index 2: " << arr1[2] << endl;
        cout << "Trying to access element at out-of-range index: ";
        cout << arr1[size] << endl; // This will throw an exception
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}


