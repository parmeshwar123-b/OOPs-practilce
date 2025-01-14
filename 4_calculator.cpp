/* Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program should take
two operands from user and performs the operation on those two operands depending upon the operator
entered by user. Use a switch statement to select the operation. Finally, display the result.
Some sample interaction with the program might look like this:
Enter first number, operator, second number: 10 / 3 Answer =3.333333
Do another (y/n)?y
Enter first number, operator, second number: 12
+ 100 Answer = 112 Do another (y/n)? n */

#include <iostream>
#include <iomanip> // For setting precision
using namespace std;

int main() {
    char doAnother = 'y';

    while (doAnother == 'y' || doAnother == 'Y') {
        double num1, num2, result;
        char op;

        // Prompt user for input
        cout << "Enter first number, operator, second number: ";
        cin >> num1 >> op >> num2;

        // Perform the operation based on the operator
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    continue;
                }
                break;
            default:
                cout << "Error: Invalid operator." << endl;
                continue;
        }

        cout << "Answer = " << fixed << setprecision(6) << result << endl;

        cout << "Do another (y/n)? ";
        cin >> doAnother;
    }

    cout << "Goodbye!" << endl;
    return 0;
}
