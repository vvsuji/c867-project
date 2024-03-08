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

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
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
void Student::SetFirstName(std::string firstName) { this->firstName = firstName; }
void Student::SetLastName(std::string lastName) { this->lastName = lastName; }
void Student::SetEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::SetAge(int age) { this->age = age; }
void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}
void Student::SetDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

// print() to print specific student data
void Student::Print() const {
    std::cout << this->studentID << '\t'
              << "First Name: " << this->firstName << '\t'
              << "Last Name: " << this->lastName << '\t'
              << "Age: " << this->age << '\t'
              << "daysInCourse: {" << this->daysInCourse[0] << ", "
                                  << this->daysInCourse[1] << ", "
                                  << this->daysInCourse[2] << "} \t"
              << "Degree Program: " << this->degreeProgram << std::endl;
}

// Note: We will need to define a function to convert DegreeProgram enum to a printable string.
