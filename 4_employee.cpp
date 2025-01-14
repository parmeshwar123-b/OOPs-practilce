/*  Given that an EMPLOYEE class contains following members: data members: Employee
number, Employee name, Basic, DA, IT, Net Salary and print data members.  */

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
    float netSalary;

public:
    void inputDetails() {
        cout << "Enter Employee Number: ";
        cin >> employeeNumber;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, employeeName);
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter DA: ";
        cin >> da;
        cout << "Enter IT: ";
        cin >> it;
        
        // Calculate Net Salary
        netSalary = basic + da - it;
    }

    void displayDetails() {
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "DA: " << da << endl;
        cout << "IT: " << it << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
};

int main() {
    Employee emp;
    emp.inputDetails();
    cout << "\nDisplaying Employee Details:" << endl;
    emp.displayDetails();

    return 0;
}

