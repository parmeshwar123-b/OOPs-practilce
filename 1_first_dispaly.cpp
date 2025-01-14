#include <iostream>
#include <string>
using namespace std;

#define MAX 3 

class Student
{
private:
    string name;
    string roll_no;
    char grade;

public:
    void inputDetails()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Grade: ";
        cin >> grade;
    }
    void displayDetails()
    {
        cout << "Name: " << name << "\nRoll No: " << roll_no << "\nGrade: " << grade << endl;
    }
};

int main(){
    Student std[MAX];
    for (int i = 0; i < MAX; i++) {
        cout << "Enter details for student " << (i + 1) << ":" << endl;
        std[i].inputDetails();
    }

    cout << "\nDisplaying details of students:" << endl;
    for (int i = 0; i < MAX; i++) {
        std[i].displayDetails();
    }

    return 0;
}
