# C++ Project: Student Roster Management System

## Overview
This project is a simple C++ application designed to manage a roster of students. It allows adding students to the roster, removing students, and printing various details about the students, such as their average days in courses, invalid email addresses, and information by degree program.

## Prerequisites
To compile and run this project, you will need:

- A C++ compiler that supports C++14 or later (e.g., Clang, GCC, or MSVC)
- An IDE or text editor (e.g., Visual Studio Code, Xcode, or any text editor for editing the source files)

## Directory Structure

cpp_project/
│
├── main.cpp # Main program entry point
│
├── roster.h # Header file for the Roster class
├── roster.cpp # Implementation file for the Roster class
│
├── student.h # Header file for the Student class
├── student.cpp # Implementation file for the Student class
│
└── degree.h # Header file for the DegreeProgram enum

## Compilation Instructions

### Using Command Line
Navigate to the project directory and run the following command:

#### For macOS or Linux:
```sh
clang++ -std=c++14 -o main main.cpp roster.cpp student.cpp
```

#### For Windows:
```sh
g++ -std=c++14 -o main.exe main.cpp roster.cpp student.cpp
```

