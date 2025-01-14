/* Write a C++ program to declare Struct. 
Initialize and display contents of member variables.  */

#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNo;
    char grade;
};

int main() {
    Student student1 = {"Pamrshwar Bodake", 101, 'A'};
    Student student2 = {"Rutuja Chakor", 102, 'B'};
    Student student3 = {"Himesh Koli", 103, 'A'};

    cout << "Student 1: Name = " << student1.name << ", Roll No = " << student1.rollNo << ", Grade = " << student1.grade << endl;
    cout << "Student 2: Name = " << student2.name << ", Roll No = " << student2.rollNo << ", Grade = " << student2.grade << endl;
    cout << "Student 3: Name = " << student3.name << ", Roll No = " << student3.rollNo << ", Grade = " << student3.grade << endl;

    return 0;
}

