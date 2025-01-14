/* Implement a class Complex which represents the Complex Number data type. Implement the following
operations:
1. Constructor (including a default constructor which creates the complex number0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.   */

#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(){
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(double r, double i){
        real = r;
        imag = i;
    }

    // Overloaded operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real - imag * other.imag), (real * other.imag + imag * other.real));
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2, sum, product;

    cout << "Enter the first complex number:" << endl;
    cin >> c1;

    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    sum = c1 + c2;
    product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
  