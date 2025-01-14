/* Write a C++ program to use pointer for both base and derived classes and call the member
function. Use Virtual keyword.  */

#include <iostream>

using namespace std;

// Base class
class Base {
public:
    virtual void display() {
        cout << "Displaying Base class" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    void display() override {
        cout << "Displaying Derived class" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;

    basePtr->display(); 

    return 0;
}

