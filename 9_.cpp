/* Write a C++ program to create multilevel inheritance. (Hint: Classes A1, A2, A3)  */
#include <iostream>

using namespace std;

// Base class
class A1 {
public:
    void showA1() {
        cout << "This is class A1" << endl;
    }
};

// Derived class from A1
class A2 : public A1 {
public:
    void showA2() {
        cout << "This is class A2" << endl;
    }
};

// Derived class from A2
class A3 : public A2 {
public:
    void showA3() {
        cout << "This is class A3" << endl;
    }
};

int main() {
    A3 obj;

    obj.showA1(); // Method from A1
    obj.showA2(); // Method from A2
    obj.showA3(); // Method from A3

    return 0;
}


