#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

    static int studentCount; // Static member to count the number of students

public:
    // Default constructor
    Student() : name(""), rollNumber(0), studentClass(""), division(' '), dateOfBirth(""), bloodGroup(""), contactAddress(""), telephoneNumber(""), drivingLicenseNumber("") {
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int rollNumber, string studentClass, char division, string dateOfBirth, string bloodGroup, string contactAddress, string telephoneNumber, string drivingLicenseNumber)
        : name(name), rollNumber(rollNumber), studentClass(studentClass), division(division), dateOfBirth(dateOfBirth), bloodGroup(bloodGroup), contactAddress(contactAddress), telephoneNumber(telephoneNumber), drivingLicenseNumber(drivingLicenseNumber) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student &other)
        : name(other.name), rollNumber(other.rollNumber), studentClass(other.studentClass), division(other.division), dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup), contactAddress(other.contactAddress), telephoneNumber(other.telephoneNumber), drivingLicenseNumber(other.drivingLicenseNumber) {
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }
    inline void display() const {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License Number: " << drivingLicenseNumber << endl;
    }
    static int getStudentCount() {
        return studentCount;
    }
    friend void displayPrivateData(const Student &student);

    // Dynamic memory allocation using new
    void *operator new(size_t size) {
        cout << "Allocating memory for Student object." << endl;
        void *ptr = ::operator new(size);
        return ptr;
    }

    void operator delete(void *ptr) {
        cout << "Deallocating memory for Student object." << endl;
        ::operator delete(ptr);
    }
};

// Initialize static member
int Student::studentCount = 0;

// Friend function definition
void displayPrivateData(const Student &student) {
    cout << "\nAccessing private data through friend function:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
}

int main() {
    // Dynamic allocation of Student object
    Student *student1 = new Student("Parmeshwar Bodake", 1, "MCA", 'C', "2005-01-15", "O+", "Yewalewadi", "8459209346", "DL12345");
    student1->display();
    Student *student2 = new Student("Parmeshwar Bodake", 1, "MCA", 'C', "2005-01-15", "O+", "Yewalewadi", "8459209346", "DL12345");
    student2->display();

    cout << "\nTotal Students: " << Student::getStudentCount() << endl;
    displayPrivateData(*student1);
    cout << "\nTotal Students: " << Student::getStudentCount() << endl;
    displayPrivateData(*student2);

    cout << "\nTotal Students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}
