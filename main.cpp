#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"

// Helper function to split a string by a delimiter and return a vector of strings
std::vector<std::string> splitStudentData(const std::string& str) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ',')) {
        result.push_back(token);
    }
    return result;
}

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "Student ID: #011957047" << std::endl;
    std::cout << "Student Name: #SujiFalcon" << std::endl << std::endl;
    
    // Data provided in the “studentData Table”
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,SUJI,FALCON,suji.falcon@gmail.com,10,15,21,23,SOFTWARE"
    };
    
    // Instantiate the Roster class
    Roster classRoster;

    // Parse the studentData and add each student to classRoster
    for (int i = 0; i < 5; ++i) {
        std::vector<std::string> studentInfo = splitStudentData(studentData[i]);
        // Assuming the last element is correctly representing the enum value as an integer
        // Also, ensuring that the email validation function and DegreeProgram enum conversion are correctly implemented elsewhere in your code
        classRoster.add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], std::stoi(studentInfo[4]),
                        std::stoi(studentInfo[5]), std::stoi(studentInfo[6]), std::stoi(studentInfo[7]),
                        studentInfo[8]);

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
}
