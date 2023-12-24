#include "AVLTree.h"

AVLTree::AVLTree() {
    root = nullptr;  // Initially the root of the AVL tree is set to nullptr and it means the tree is empty.
}

// Calls the private version of itself and returns the int value found by it (which is the trees height)
int AVLTree::getHeightAVLTree() {
    return getHeightAVLTree(root);
}

// Returns the height of the AVL Tree
int AVLTree::getHeightAVLTree(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}

// Calls the private version of itself and returns the int value found by it (which is the node's balance)
int AVLTree::getBalance() {
    return getBalance(root);
}

// Returns the balance of the node passed in
int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeightAVLTree(node->getLeft()) - getHeightAVLTree(node->getRight());
}

// Prints the number of levels that exist in the tree
void AVLTree::printLevelCount() {
    std::cout << getHeightAVLTree(root);
}


// Calls the private version of itself
void AVLTree::printInorder() {
    bool isFirstName = true;
    printInorder(root, isFirstName);
}

// Traverses the tree the Inorder and prints each node this way
void AVLTree::printInorder(Node* node, bool& isFirstName) {
    if (node != nullptr) {
        printInorder(node->getLeft(), isFirstName);
        if (isFirstName == true) {
            std::cout << node->getStudent().getName();
            isFirstName = false;
        }
        else {
            std::cout << ", " << node->getStudent().getName();
        }
        printInorder(node->getRight(), isFirstName);
    }
}

// Calls the private version of itself
std::string AVLTree::preorderToString() {
    bool isFirstName = true;
    std::string str = "";
    preorderToString(root, isFirstName, str);
    return str;
}

// Traverses the tree the Preorder and creates a string with this
void AVLTree::preorderToString(Node* node, bool& isFirstName, std::string& str) {
    if (node != nullptr) {
        if (isFirstName == true) {
            str += node->getStudent().getName();
            isFirstName = false;
        }
        else {
            str += ", ";
            str += node->getStudent().getName();
        }
        preorderToString(node->getLeft(), isFirstName, str);
        preorderToString(node->getRight(), isFirstName, str);
    }
}

// Calls the private version of itself
void AVLTree::printPreorder() {
    bool isFirstName = true;
    printPreorder(root, isFirstName);
}

// Traverses the tree the Preorder and prints each node this way
void AVLTree::printPreorder(Node* node, bool& isFirstName) {
    if (node != nullptr) {
        if (isFirstName == true) {
            std::cout << node->getStudent().getName();
            isFirstName = false;
        }
        else {
            std::cout << ", " << node->getStudent().getName();
        }
        printPreorder(node->getLeft(), isFirstName);
        printPreorder(node->getRight(), isFirstName);
    }
}

// Calls the private version of itself
void AVLTree::printPostorder() {
    bool isFirstName = true;
    printPostorder(root, isFirstName);
}

// Traverses the tree the Postorder and prints each node this way
void AVLTree::printPostorder(Node* node, bool& isFirstName) {
    if (node != nullptr) {
        printPostorder(node->getLeft(), isFirstName);
        printPostorder(node->getRight(), isFirstName);
        if (isFirstName == true) {
            std::cout << node->getStudent().getName();
            isFirstName = false;
        }
        else {
            std::cout << ", " << node->getStudent().getName();
        }
    }
}

// Calls the private version of itself and returns that bool value 
bool AVLTree::removeByID(int id) {
    if (root == nullptr) {
        return false;
    }
    return removeByID(root, nullptr, id);
}

// Returns true if the ID was removed successfully from the tree (searches for the ID directly)
bool AVLTree::removeByID(Node* node, Node* nodeParent, int studentID) {
    if (node == nullptr) {
        return false;
    }
    if (studentID == node->getStudent().getId()) {
        deleteNode(node, nodeParent);
        return true;
    }
    if (studentID < node->getStudent().getId()) {
        return removeByID(node->getLeft(), node, studentID);
    }
    else { 
        return removeByID(node->getRight(), node, studentID);
    }
}

// Calls the private version of itself and returns that bool value
bool AVLTree::removeIDInorder(int nthId) {
    if (root == nullptr) {
        return false;
    }
    int counter = 0;
    return removeIDInorder(root, nullptr, nthId, counter);
}

// Returns true if the ID was removed successfully from the tree (searches for the location (nth ID) of the ID using Inorder traversal)
bool AVLTree::removeIDInorder(Node* node, Node* nodeParent, int nthId, int& counter) { 
    if (node == nullptr) {
        return false;
    }
    bool success = false;
    if (removeIDInorder(node->getLeft(), node, nthId, counter) == true) {
        success = true;
    }
    else {
        if (nthId == counter) {
            success = true;
            deleteNode(node, nodeParent);
        }
        else {
            counter++; // incrementing the counter
            if (removeIDInorder(node->getRight(), node, nthId, counter) == true) {
                success = true;
            }
        }
    }
    return success;
}

// Deletes the Node from the tree (Help from Professor Kapoor's Tree lecture slides and https://www.geeksforgeeks.org/deletion-in-binary-search-tree/)
void AVLTree::deleteNode(Node* nodeToDelete, Node* nodeParent) {

    // The case where both left and right children are null
    if (nodeToDelete->getLeft() == nullptr && nodeToDelete->getRight() == nullptr) { 
        if (nodeParent != nullptr) {
            if (nodeParent->getLeft() == nodeToDelete) {
                nodeParent->setLeft(nullptr);
            }
            else if (nodeParent->getRight() == nodeToDelete) {
                nodeParent->setRight(nullptr);
            }
        }
        else {
            root = nullptr;
        }
        delete nodeToDelete;
    }

    // The case where only the left child is nullptr
    else if (nodeToDelete->getRight() != nullptr && nodeToDelete->getLeft() == nullptr) { 
        if (nodeParent != nullptr) {
            if (nodeParent->getLeft() == nodeToDelete) {
                nodeParent->setLeft(nodeToDelete->getRight());
            }
            else if (nodeParent->getRight() == nodeToDelete) {
                nodeParent->setRight(nodeToDelete->getRight());
            }
        }
        else {
            root = nullptr;
        }
        delete nodeToDelete;
    }

    // The case where only the right child is nullptr
    else if (nodeToDelete->getLeft() != nullptr && nodeToDelete->getRight() == nullptr) { 
        if (nodeParent != nullptr) {
            if (nodeParent->getLeft() == nodeToDelete) {
                nodeParent->setLeft(nodeToDelete->getLeft());
            }
            else if (nodeParent->getRight() == nodeToDelete) {
                nodeParent->setRight(nodeToDelete->getLeft());
            }
        }
        else {
            root = nullptr;
        }
        delete nodeToDelete;
    }

    // Neither children are nullptr. Node with two children get the inorder successor (smallest in the right subtree). For this I used help from https://www.geeksforgeeks.org/deletion-in-binary-search-tree/#
    else if (nodeToDelete->getRight() != nullptr && nodeToDelete->getLeft() != nullptr) { 
        Node* temp = nodeToDelete->getRight();
        Node* tempParent = nodeToDelete;
        while (temp->getLeft() != nullptr) {
            tempParent = temp;
            temp = temp->getLeft();
        }
        nodeToDelete->setStudent(temp->getStudent()); // Copy the inorder successor's key to this node
        deleteNode(temp, tempParent); // Recursively delete the inorder successor
    }
}

// Searches for the node with the given ID and returns the node
Node* AVLTree::studentSearchID(int studentID) {
    return searchByID(root, studentID);
}

// Searches for the node with the given ID and returns true if it exists, false otherwise
bool AVLTree::doesIdExist(int id) {
    return searchByID(root, id) != nullptr;
}

// Searches for the node in the tree based off its ID and returns it. Since the tree is ordered, we can see if the left or right child is > or < and act correspondingly 
Node* AVLTree::searchByID(Node* node, int studentID) {
    if (node == nullptr) {
        return nullptr;
    }
    if (studentID == node->getStudent().getId()) {
        return node;
    }
    if (studentID < node->getStudent().getId()) {
        return searchByID(node->getLeft(), studentID);
    }
    else {
        return searchByID(node->getRight(), studentID);
    }
}

// Calls the private version of itself
bool AVLTree::studentSearchName(const std::string& studentName) {
    return studentSearchName(root, studentName);
}

// Searches for students who have the passed in name, returns true as long as one is found, false otherwise
bool AVLTree::studentSearchName(Node* node, const std::string& studentName) {
    bool success = false;

    if (node == nullptr) {
        return false;
    }
    else {
        if (node->getStudent().getName() == studentName) {
            std::cout << node->getStudent().getStringId() << "\n";
            success = true;
        }
        bool successLeft = studentSearchName(node->getLeft(), studentName);
        bool successRight = studentSearchName(node->getRight(), studentName);
        return success || successLeft || successRight;
    }
}

// Inserts the node into the tree and calls the balancing method to balance it (Based off slide 34 of Trees powerpoint)
Node* AVLTree::insert(Node* node, const Student& student) { 
    if (node == nullptr) {
        return new Node(student);
    }
    if (student.getId() < node->getStudent().getId()) {
        node->setLeft(insert(node->getLeft(), student));
    }
    else if (student.getId() > node->getStudent().getId()) {
        node->setRight(insert(node->getRight(), student));
    }
    node->setHeight(std::max(getHeightAVLTree(node->getLeft()), getHeightAVLTree(node->getRight())) + 1);
    node = balanceNode(node);
    return node;
}

// Balances the node using different kinds of rotations depending on the balance orientation
Node* AVLTree::balanceNode(Node* node) {
    if (getBalance(node) >= 2) {
        if (getBalance(node->getLeft()) == 1) {
            node = rightRotation(node);
        }
        else if (getBalance(node->getLeft()) == -1) {
            node = leftRightRotiation(node);
        }
    }
    else if (getBalance(node) <= -2) {
        if (getBalance(node->getRight()) == 1) {
            node = rightLeftRotiation(node);
        }
        else if (getBalance(node->getRight()) == -1) {
            node = leftRotation(node);
        }
    }
    return node;
}

// Creates a new student object and inserts it into the tree
void AVLTree::fullInsert(const std::string& studentName, const std::string& studentId) {
    Student newStudent = Student(studentName, studentId);
    root = insert(root, newStudent); //root basically stays the same
}

// Exectutes a left rotation (For right right case)
Node* AVLTree::leftRotation(Node* node) { 

    Node* newParent = node->getRight();  
    Node* grandchild = newParent->getLeft();

    newParent->setLeft(node);
    node->setRight(grandchild);

    node->setHeight(std::max(getHeightAVLTree(node->getLeft()), getHeightAVLTree(node->getRight())) + 1);
    newParent->setHeight(std::max(getHeightAVLTree(newParent->getLeft()), getHeightAVLTree(newParent->getRight())) + 1);

    return newParent; 
}

// Exectutes a right rotation (For left left case)
Node* AVLTree::rightRotation(Node* node) { 

    Node* newParent = node->getLeft();
    Node* grandchild = newParent->getRight();

    newParent->setRight(node);
    node->setLeft(grandchild);

    node->setHeight(std::max(getHeightAVLTree(node->getRight()), getHeightAVLTree(node->getLeft())) + 1);
    newParent->setHeight(std::max(getHeightAVLTree(newParent->getRight()), getHeightAVLTree(newParent->getLeft())) + 1);

    return newParent;
}

// Performs a right left rotation (for right left case)
Node* AVLTree::rightLeftRotiation(Node* node) { 
    Node* firstRotationParent = rightRotation(node->getRight());
    node->setRight(firstRotationParent); 
    return leftRotation(node);
}

// Performs a left right rotation (for left riught case)
Node* AVLTree::leftRightRotiation(Node* node) { 
    Node* firstRotationParent = leftRotation(node->getLeft());
    node->setLeft(firstRotationParent); 
    return rightRotation(node);
}