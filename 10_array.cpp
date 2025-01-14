/*  Write a C++ program to create an array of pointers. Invoke functions using array objects.  */

#include <iostream>

using namespace std;

class MyClass {
public:
    void display() {
        cout << "Hello from MyClass!" << endl;
    }
};

int main() {
    int size = 3;
    MyClass* objArray[size];

    for (int i = 0; i < size; ++i) {
        objArray[i] = new MyClass();
        objArray[i]->display();
    }

    return 0;
}
