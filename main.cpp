// main.cpp

#include <iostream>
#include "roster.h"

int main() {
    // Print course title, programming language used, student ID, and name
    std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "Student ID: #011957047" << std::endl;
    std::cout << "Student Name: #SujiFalcon" << std::endl << std::endl;
    
    // Data provided in the “studentData Table”
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Alice,Wonderland,alice@example.com,21,45,50,55,SOFTWARE"
    };
    
    // Instantiate the Roster class
    Roster classRoster;

    // Parse the studentData and add each student to classRoster
    for (int i = 0; i < 5; ++i) {
        // Split the studentData by comma and add the student to the roster
        // This code will be simplified here, parsing will be done by a function in a real-world scenario
        // Assume a function splitStudentData is already implemented
        std::vector<std::string> studentInfo = splitStudentData(studentData[i]);
        classRoster.add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], std::stoi(studentInfo[4]),
                        std::stoi(studentInfo[5]), std::stoi(studentInfo[6]), std::stoi(studentInfo[7]),
                        static_cast<DegreeProgram>(std::stoi(studentInfo[8])));
    }

    // Printing all students
    classRoster.printAll();

    // Printing invalid emails
    classRoster.printInvalidEmails();

    // Printing average days in course
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + std::to_string(i + 1));
    }

    // Printing by degree program SOFTWARE
    classRoster.printByDegreeProgram(SOFTWARE);

    // Removing student A3
    classRoster.remove("A3");

    // Attempting to remove student A3 again to print error message
    classRoster.remove("A3");

    // Implement the destructor to release memory (handled in Roster's destructor)

    return 0;
}
