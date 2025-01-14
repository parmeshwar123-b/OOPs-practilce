/*  Implement a class Quadratic that represents degree two polynomials i.e., polynomials of type ax2+bx+c.
The class will require three data members corresponding to a, b and c. Implement the following
operations:
1. A constructor (including a default constructor which creates the 0polynomial).
2. Overloaded operator+ to add two polynomials of degree2.
3. Overloaded << and >> to print and read polynomials. To do this, you will need to decide what you
want your input and output format to looklike.
4. A function eval that computes the value of a polynomial for a given value ofx.
5. A function that computes the two solutions of the equationa x2+bx+c=0. */


#include <iostream>
#include <cmath>

using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Default constructor
    Quadratic()
     {
        a = b = c = 0; 
     }
    Quadratic(double a, double b, double c) {

        this->b = b;
        this->c = c;
        this->a = a;
    }

    Quadratic operator+(const Quadratic& other) const {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2";
        if (q.b >= 0) out << "+" << q.b << "x";
        else out << q.b << "x";
        if (q.c >= 0) out << "+" << q.c;
        else out << q.c;
        return out;
    }

    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficient a: ";
        in >> q.a;
        cout << "Enter coefficient b: ";
        in >> q.b;
        cout << "Enter coefficient c: ";
        in >> q.c;
        return in;
    }

    double eval(double x) const {
        return a * x * x + b * x + c;
    }

    void solve() const {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two distinct real roots: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "One real root: " << root << endl;
        } else {
            cout << "No real roots." << endl;
        }
    }
};

int main() {
    Quadratic q1, q2, sum;

    cout << "Enter the first quadratic polynomial:" << endl;
    cin >> q1;

    cout << "Enter the second quadratic polynomial:" << endl;
    cin >> q2;

    sum = q1 + q2;

    cout << "First polynomial: " << q1 << endl;
    cout << "Second polynomial: " << q2 << endl;
    cout << "Sum of polynomials: " << sum << endl;

    double x;
    cout << "Enter a value for x to evaluate the sum: ";
    cin >> x;
    cout << "Value of the sum polynomial at x = " << x << " is: " << sum.eval(x) << endl;

    cout << "Solving the equation for the sum polynomial:" << endl;
    sum.solve();

    return 0;
}
