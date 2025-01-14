#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

    // Function to reduce the fraction without gcd
    void reduce() {
        int a = numerator, b = denominator;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcdValue = a > 0 ? a : -a; // Ensure gcd is positive
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) { // Ensure denominator is always positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    RationalNumber(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // Overload + operator
    RationalNumber operator+(const RationalNumber &rhs) const {
        int newNumerator = numerator * rhs.denominator + rhs.numerator * denominator;
        int newDenominator = denominator * rhs.denominator;
        return RationalNumber(newNumerator, newDenominator);
    }

    // Overload - operator
    RationalNumber operator-(const RationalNumber &rhs) const {
        int newNumerator = numerator * rhs.denominator - rhs.numerator * denominator;
        int newDenominator = denominator * rhs.denominator;
        return RationalNumber(newNumerator, newDenominator);
    }

    // Overload * operator
    RationalNumber operator*(const RationalNumber &rhs) const {
        return RationalNumber(numerator * rhs.numerator, denominator * rhs.denominator);
    }

    // Overload / operator
    RationalNumber operator/(const RationalNumber &rhs) const {
        if (rhs.numerator == 0) {
            throw invalid_argument("Division by zero.");
        }
        return RationalNumber(numerator * rhs.denominator, denominator * rhs.numerator);
    }

    // Overload relational operators
    bool operator<(const RationalNumber &rhs) const {
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }

    bool operator<=(const RationalNumber &rhs) const {
        return numerator * rhs.denominator <= rhs.numerator * denominator;
    }

    bool operator>(const RationalNumber &rhs) const {
        return numerator * rhs.denominator > rhs.numerator * denominator;
    }

    bool operator>=(const RationalNumber &rhs) const {
        return numerator * rhs.denominator >= rhs.numerator * denominator;
    }

    bool operator==(const RationalNumber &rhs) const {
        return numerator * rhs.denominator == rhs.numerator * denominator;
    }

    bool operator!=(const RationalNumber &rhs) const {
        return !(*this == rhs);
    }

    // Display the rational number
    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    try {
        RationalNumber r1(1, 2);
        RationalNumber r2(3, 4);

        cout << "r1: ";
        r1.display();
        cout << "\nr2: ";
        r2.display();

        RationalNumber r3 = r1 + r2;
        cout << "\nr1 + r2: ";
        r3.display();

        RationalNumber r4 = r1 - r2;
        cout << "\nr1 - r2: ";
        r4.display();

        RationalNumber r5 = r1 * r2;
        cout << "\nr1 * r2: ";
        r5.display();

        RationalNumber r6 = r1 / r2;
        cout << "\nr1 / r2: ";
        r6.display();

        cout << "\nComparison r1 < r2: " << (r1 < r2);
        cout << "\nComparison r1 == r2: " << (r1 == r2);

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
