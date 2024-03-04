// roster.h

#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
    // Constructor
    Roster();
    
    // Destructor
    ~Roster();
    
    // Other methods
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    int lastIndex;
    int capacity;
    Student** classRosterArray; // Array of pointers to Students
};

#endif
