#include "Node.h"

Node::Node(const Student& theStudent) {
    student = theStudent;  // Assigns the inputStudent to the student member variable of the node.
    left = nullptr;  // At first the left child of the node is set to nullptr (doesnt have left child yet)
    right = nullptr;  // At first the right kid of the node is set to nullptr (doesnt have right child yet)
    height = 1;  // At first the height of the node is set to 1, as it doesn't have any child yet.
}

// Getter method for getting the left node.
Node* Node::getLeft() const {
    return left;
}

// Getter method for getting the right node.
Node* Node::getRight() const {
    return right;
}

// Getter method for getting the height of node.
int Node::getHeight() const {
    return height;
}

// Getter method for getting the left node.
const Student& Node::getStudent() const {
    return student;
}

// Getter method for getting the student related to the node.
void Node::setStudent(const Student& student) {
    this->student = student;
}

// Setter method that sets the left student of the node
void Node::setLeft(Node* left) {
    this->left = left;
}

// Setter method that sets the right student of the node
void Node::setRight(Node* right) {
    this->right = right;
}

// Setter method that sets the node's height
void Node::setHeight(int height) {
    this->height = height;
}
