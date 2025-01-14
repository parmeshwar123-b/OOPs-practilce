/*
Write C++ Program with base class convert declares two variables, val1 and val2, which hold the initial
and converted values, respectively. It also defines the functions getinit( ) and getconv( ), which return the
initial value and the converted value. These elements of convert are fixed and applicable to all derived
classes that will inherit convert. However, the function that will actually perform the conversion,
compute( ), is a pure virtual
function that must be defined by the classes derived from convert. The specific nature of compute( )
will be determined by what type of conversion is taking place.
*/

#include <iostream>
#include <string>
using namespace std;

class Convert {
protected:
    double val1; // Initial value
    double val2; // Converted value

public:
    Convert(double initialValue = 0.0)  {
         this->val1 = initialValue;
         this->val2 = 0.0; 
    }

    double getInit() const {
        return val1;
    }

    double getConv() const {
        return val2;
    }

    virtual void compute() = 0; 

    virtual ~Convert() {}
};

class FahrenheitToCelsius : public Convert {
public:
    FahrenheitToCelsius(double fahrenheit = 0.0) : Convert(fahrenheit) {}

    void compute() override {
        val2 = (val1 - 32) * 5.0 / 9.0;
    }
};

class CelsiusToFahrenheit : public Convert {
public:
    CelsiusToFahrenheit(double celsius = 0.0) {
        this->val1 = celsius;
    }

    void compute() override {
        val2 = (val1 * 9.0 / 5.0) + 32;
    }
};

class KilometersToMiles : public Convert {
public:
    KilometersToMiles(double kilometers = 0.0) {
        this->val1 = kilometers;
    }

    void compute() override {
        val2 = val1 * 0.621371;
    }
};

int main() {
    double value;

    cout << "Enter value in Fahrenheit to convert to Celsius: ";
    cin >> value;
    FahrenheitToCelsius fToC(value);
    fToC.compute();
    cout << value << " Fahrenheit is " << fToC.getConv() << " Celsius." << endl;

    cout << "\nEnter value in Celsius to convert to Fahrenheit: ";
    cin >> value;
    CelsiusToFahrenheit cToF(value);
    cToF.compute();
    cout << value << " Celsius is " << cToF.getConv() << " Fahrenheit." << endl;

    cout << "\nEnter value in Kilometers to convert to Miles: ";
    cin >> value;
    KilometersToMiles kmToMiles(value);
    kmToMiles.compute();
    cout << value << " Kilometers is " << kmToMiles.getConv() << " Miles." << endl;

    return 0;
}
