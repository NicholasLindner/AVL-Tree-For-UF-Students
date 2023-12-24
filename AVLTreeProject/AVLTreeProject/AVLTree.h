#pragma once
#include "Node.h"
#include "Student.h"
#include <algorithm>
#include <iostream>
#include <vector>

class AVLTree {

// Declares privates
private:

    Node* root; // Declares the root node

    // BOOL RETURN METHODS:

    bool removeIDInorder(Node* node, Node* nodeparent, int nthId, int& counter); // Returns true or false if the given student can be removed from thhe tree (based off the nth position with an Inorder traversal)
    bool removeByID(Node* node, Node* nodeParent, int id); // Returns true or false if the given student can be removed from the tree (based off their ID)
    bool studentSearchName(Node* node, const std::string& studentName); // Searches the tree for a given student's name (can be 

    // INT RETURN METHODS:

    int getHeightAVLTree(Node* node); // Gets the height of the tree
    int getBalance(Node* node); // Gets the balance factor of the tree
  
    // NODE* RETURN METHODS: 

    Node* insert(Node* node, const Student& student); // inserts the nodes but does not balance them. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's TREES POWERPOINT
    Node* balanceNode(Node* node); // Balances the tree properly. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's BALANCING TREES POWERPOINT
    Node* searchByID(Node* node, int id); // Searches the tree for a given ID
    Node* leftRotation(Node* node); // For right right case. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's BALACING TREES POWERPOINT
    Node* rightRotation(Node* node); // For left left case. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's BALACING TREES POWERPOINT
    Node* leftRightRotiation(Node* node); // For  Left Right case. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's BALACING TREES POWERPOINT
    Node* rightLeftRotiation(Node* node); // For  Right Left case. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's BALACING TREES POWERPOINT

    // VOID RETURN METHODS:

    void printInorder(Node* node, bool& isFirstName); // Prints out the students in the tree using InOrder traversal. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's TREES POWERPOINT
    void printPreorder(Node* node, bool& isFirstName); // Prints out the students in the tree using PreOrder traversal. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's TREES POWERPOINT
    void printPostorder(Node* node, bool& isFirstName); // Prints out the students in the tree using PostOrder traversal. IMPLEMENTATION BASED OFF OF PROFESSOR KAPOOR's TREES POWERPOINT
    void deleteNode(Node* node, Node* nodeParent);

    // STRING RETURN METHODS:
    void preorderToString(Node* node, bool& isFirstName, std::string& str); // Creates a string that has the IDs inorder


// Declares publics
public:

    AVLTree(); // Constructor

    // BOOL RETURN METHODS:

    bool removeIDInorder(int nthId); // Calls the private version of this function (this exists so that this function can be called from main)
    bool removeByID(int id);
    bool doesIdExist(int id);
    bool studentSearchName(const std::string& studentName);  // Calls the private version of this function (this exists so that this function can be called from main)

    // INT RETURN METHODS:

    int getHeightAVLTree(); // Calls the private version of this function (this exists so that this function can be called from main)
    int getBalance(); // Calls the private version of this function (this exists so that this function can be called from main)

    // VOID RETURN METHODS:
    
    void fullInsert(const std::string& studentName, const std::string&  studentId); // uses unbalancedInsert and then balances them
    void printLevelCount(); // Prints out the number of levels that exist in the tree
    void printInorder(); // Calls the private version of this function (this exists so that this function can be called from main)
    void printPreorder(); // Calls the private version of this function (this exists so that this function can be called from main)
    void printPostorder(); // Calls the private version of this function (this exists so that this function can be called from main)

    // STRING RETURN METHODS
    std::string preorderToString(); // Calls the private version of this function (this exists so that this function can be called from main)

    // NODE RETURN METHODS:
    Node* studentSearchID(int studentID);  // Calls the private version of this function (this exists so that this function can be called from main)
  

};
