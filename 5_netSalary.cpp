/* Write a C++ program to read the data of N employee and compute Net salary of each
employee (DA=52% of Basic and Income Tax (IT) =30% of the gross salary).  */

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeNumber;
    string employeeName;
    float basic;
    float da;
    float it;
    float grossSalary;
    float netSalary;

public:
    void inputDetails() {
        cout << "Enter Employee Number: ";
        cin >> employeeNumber;
        cout << "Enter Employee Name: ";
        getline(cin, employeeName);
        cout << "Enter Basic Salary: ";
        cin >> basic;
        
        // Calculate DA (52% of Basic)
        da = 0.52 * basic;
        // Calculate Gross Salary (Basic + DA)
        grossSalary = basic + da;
        // Calculate IT (30% of Gross Salary)
        it = 0.30 * grossSalary;
        // Calculate Net Salary (Gross Salary - IT)
        netSalary = grossSalary - it;
    }
    void displayDetails() {
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "DA: " << da << endl;
        cout << "Gross Salary: " << grossSalary << endl;
        cout << "IT: " << it << endl;
        cout << "Net Salary: " << netSalary << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << (i + 1) << ":" << endl;
        employees[i].inputDetails();
    }

    cout << "\nDisplaying Employee Details:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].displayDetails();
    }

    return 0;
}
