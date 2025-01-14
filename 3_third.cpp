/*  Write a C++ program to declare a class. Declare pointer to class. Initialize and display the  contents of the class member. */

#include <iostream>
#include <string>
using namespace std;

class Addition
{
private:
    int num1;
    int num2;
    int sum;

public:
    Addition(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }

    int calculate()
    {
        sum = num1 + num2;
        return sum;
    }
};

int main()
{
    Addition obj(5, 10);
    Addition obj2(10, 20);

    int result2 = obj2.calculate();
    int result = obj.calculate();
    Addition *ptr;
    ptr = &obj;
    cout << "Addition of First : " << ptr->calculate() << endl;
    ptr = &obj2;
    cout << "Addition of second : " << ptr->calculate() << endl;
}