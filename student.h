
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
public:
    // Constructors
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    // Destructors
    ~Student();

    // Accessors (getters)
    std::string GetStudentID() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetEmailAddress() const;
    int GetAge() const;
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram() const;

    // Mutators (setters)
    void SetStudentID(std::string ID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetEmailAddress(std::string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void SetDegreeProgram(DegreeProgram dp);

    // Other methods
    void Print() const;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};

#endif
