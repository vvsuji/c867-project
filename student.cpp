#include "student.h"
#include <iostream>

// Constructor implementation
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(std::string setStudentID, std::string setFirstName, std::string setLastName, std::string setEmailAddress, int setAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram setDegreeProgram) {
    this->studentID = setStudentID;
    this->firstName = setFirstName;
    this->lastName = setLastName;
    this->emailAddress = setEmailAddress;
    this->age = setAge;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = setDegreeProgram;
}

// Destructor
Student::~Student() {
    // Empty for now since we're not dynamically allocating memory
}

// Accessors (getters) implementation
std::string Student::GetStudentID() const { return studentID; }
std::string Student::GetFirstName() const { return firstName; }
std::string Student::GetLastName() const { return lastName; }
std::string Student::GetEmailAddress() const { return emailAddress; }
int Student::GetAge() const { return age; }
int* Student::GetDaysInCourse() { return daysInCourse; }
DegreeProgram Student::GetDegreeProgram() const { return degreeProgram; }

// Mutators (setters) implementation
void Student::SetStudentID(std::string ID) { this->studentID = ID; }
void Student::SetFirstName(std::string newFirstName) { this->firstName = newFirstName; }
void Student::SetLastName(std::string newLastName) { this->lastName = newLastName; }
void Student::SetEmailAddress(std::string newEmailAddress) { this->emailAddress = newEmailAddress; }
void Student::SetAge(int newAge) { this->age = newAge; }
void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}
void Student::SetDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

// print() to print specific student data
void Student::Print() const {
    std::string degreePrograms[] = {
        "SECURITY",
        "NETWORK",
        "SOFTWARE"
    };

    std::cout << this->studentID << '\t'
              << "First Name: " << this->firstName << '\t'
              << "Last Name: " << this->lastName << '\t'
              << "Email: " << this->emailAddress << '\t'
              << "Age: " << this->age << '\t'
              << "daysInCourse: {" << this->daysInCourse[0] << ", "
                                  << this->daysInCourse[1] << ", "
                                  << this->daysInCourse[2] << "} \t"
              << "Degree Program: " << degreePrograms[this->degreeProgram] << std::endl;
}

