#include "roster.h"
#include <iostream>

// Constructor implementation
Roster::Roster() {
    this->lastIndex = -1;
    this->capacity = 5;
    this->classRosterArray = new Student*[capacity];
}

// Destructor implementation
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete this->classRosterArray[i];
    }
    delete [] this->classRosterArray;
}

// Other methods implementation
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string degreeProgram) {
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    DegreeProgram degreeProgramEnum = DegreeProgram::SOFTWARE;
    if (degreeProgram == "NETWORK") {
        degreeProgramEnum = DegreeProgram::NETWORK;
    };
    if (degreeProgram == "SECURITY") {
        degreeProgramEnum = DegreeProgram::SECURITY;
    }
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgramEnum);
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->GetStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
            break;
        }
    }
    if (!found) {
        std::cout << "The student with ID: " << studentID << " was not found." << std::endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        this->classRosterArray[i]->Print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->GetStudentID() == studentID) {
            int* days = classRosterArray[i]->GetDaysInCourse();
            std::cout << "Average days in course for student ID " << studentID << " is "
                      << (days[0] + days[1] + days[2]) / 3 << std::endl;
            break;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        std::string email = classRosterArray[i]->GetEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}
