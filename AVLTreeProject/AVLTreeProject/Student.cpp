#include "Student.h"

// Default Constructor
Student::Student() {
    name = "";
    id = "";
}

// Constructor for String ID
Student::Student(const std::string& studentName, const std::string& studentId) {
    name = studentName;
    id = studentId;
}

// Getter that gets the students name
std::string Student::getName() const {
    return name;
}

// Getter that retrieves the student's ID as an int
int Student::getId() const {
    return std::stoi(id);
}

//Getter that retrieves the students ID as a string
std::string Student::getStringId() const {
    return id;
}