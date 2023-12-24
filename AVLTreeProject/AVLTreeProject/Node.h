#pragma once
#include "Student.h"
#include <algorithm> 

class Node {

// Private variables are declared
private:
    Student student;
    Node* left;
    Node* right;
    int height;

//Public methods are declared
public:
    // Constructor
    Node(const Student& student); 

    // Getters
    Node* getLeft() const;
    Node* getRight() const;
    int getHeight() const;
    const Student& getStudent() const;
    
    //Setters
    void setStudent(const Student& student);
    void setLeft(Node* left);
    void setRight(Node* right);
    void setHeight(int height);
};
