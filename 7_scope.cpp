/*  Write a C++ program to use scope resolution operator. Display the various values of the
same variables declared at different scope levels.  */

#include <iostream>

using namespace std;

int globalVar = 1; 

class MyClass {
public:
    static int classVar; 
    void displayVariables() {
        int localVar = 3; 
        cout << "Local variable: " << localVar << endl;
        cout << "Class variable: " << MyClass::classVar << endl;
    }
};

int MyClass::classVar = 2; 

int main() {
    MyClass obj;
    obj.displayVariables();

    return 0;
}


