#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"

std::vector<std::string> splitStudentData(const std::string& data) {
    std::vector<std::string> tokens;
    std::istringstream stream(data);
    std::string token;
    while (std::getline(stream, token, ',')) {
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl
              << "Programming Language: C++" << std::endl
              << "Student ID: #011957047" << std::endl
              << "Student Name: Suji Falcon" << std::endl << std::endl;
    
    // Sample student data.
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,SUJI,FALCON,suji.falcon@gmail.com,25,15,21,23,SOFTWARE"
    };
    
    Roster classRoster;

    for (const auto& entry : studentData) {
        auto info = splitStudentData(entry);
        if (info.size() == 9) {
            classRoster.add(info[0], info[1], info[2], info[3], std::stoi(info[4]),
                            std::stoi(info[5]), std::stoi(info[6]), std::stoi(info[7]),
                            info[8]);
        }
    }

    // Test print functions
    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + std::to_string(i + 1));
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.remove("A3"); // EXPECTED ERROR MESSAGE "THE STUDENT WITH ID: A3 WAS NOT FOUND."

    classRoster.printAll();


    return 0;
}
