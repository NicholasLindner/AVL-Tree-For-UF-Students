#pragma once
#include <string>

class Student {

//Private variables are declared
private:
    std::string name;
    std::string id;

//Public methods are declared
public:
    // Constructors
    Student();
    Student(const std::string& studentName, const std::string& studentId);

    // Getters
    std::string getName() const;
    std::string getStringId() const;
    int getId() const;


};
