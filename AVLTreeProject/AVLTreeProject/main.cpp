#include <iostream>
#include "AVLTree.h"
#include "Student.h"
#include "Node.h"
#include <algorithm>

/* Note:
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope.
*/

// Here the passed in string(which is the functino call) is substringed from location up to the end of the string. This substring gets any quotation marks removed. 
//Then that new version of the string is returned.
std::string readString(std::string functionCall, int& location) { 
	std::string str = functionCall.substr(++location);
	str.erase(std::remove(str.begin(), str.end(), '"'), str.end()); // Help from tutorialspoint.com article "Remove all the occurrences of a character from a string using STL"
	return str;
}

// Reads the name of the student from the function call and returns it by using quotation marks to locate where the name is found in the function call.
std::string readName(std::string functionCall, int& location) {
	int firstQuotationsLocation = functionCall.find('"', location);
	int secondQuotationsLocation = functionCall.find('"', firstQuotationsLocation + 1);
	location = secondQuotationsLocation + 1;
	return functionCall.substr(firstQuotationsLocation + 1, secondQuotationsLocation - firstQuotationsLocation - 1);
}

// Reads the ID from the function call and returns the string version of the ID
std::string readId(std::string functionCall, int& location) {
	return functionCall.substr(location);
}

// This is only used from removeInorder. This returns what n is (the node's location that is to be removed if traversing inorder.
std::string readNthNode(std::string functionCall, int& location) {
	return functionCall.substr(location);
}

// Verifies that the name given has only alphabet characters or spaces (returns true if it is valid, false if not).
bool verifyName(std::string name) {
	for (int i = 0; i < name.length(); i++) {
		if (!std::isalpha(name[i]) && name[i] != ' ') {
			return false;
		}
	}
	return true;
}

// Checks if the ID provided is valid (is of length 8 and contains only numerical values), and checks to make sure that an ID of the same value is not already in the tree.
// This is because only IDs that are not already existing can be inserted (returns true if it can be inserted, false if not).
bool isIdValidForInsert(std::string stringId, AVLTree& tree) {

	if (stringId.length() != 8) {
		return false;
	}
	for (int i = 0; i < 8; i++) { // remember, this loop is always going through 8 items so it is O(1)
		if (std::isdigit(stringId[i]) == false) {
			return false;
		}
	}
	if (tree.doesIdExist(stoi(stringId)) == true) {
		return false;
	}
	return true;
}

// Checks if the ID provided is valid (is of length 8 and contains only numerical values), and checks to make sure that an ID of the same value is indeed already in the tree.
// This is because for searching, only IDs that are already in the tree can be found (it returns true if it can be searched, false if not)
bool verifyIdForSearch(std::string stringId, AVLTree& tree) {
	if (stringId.length() != 8) {
		return false;
	}
	for (int i = 0; i < 8; i++) { // remember, this loop is always going through 8 items so it is O(1)
		if (std::isdigit(stringId[i]) == false) {
			return false;
		}
	}
	if (tree.doesIdExist(stoi(stringId)) == false) {
		return false;
	}
	return true;
}

// Helps insert a node into the tree. It does this by verifying the name is valid, verifying the ID is valid for insertion, and then calling the actual insert function from 
// the AVLTree class.
bool insertHelper(std::string functionCall, int& location, AVLTree& tree) {

	std::string name = readName(functionCall, location);
	if (verifyName(name) == false) {
		return false;
	}
	location++;
	std::string stringId = readId(functionCall, location);
	if (isIdValidForInsert(stringId, tree) == false) {
		return false;
	}
	tree.fullInsert(name, stringId);
	return true;
}

// Helps remove nodes from the tree. Returns true if the ID got removed, false otherwise.
bool removeHelper(std::string functionCall, int& location, AVLTree& tree) {
	std::string stringId = readId(functionCall, ++location);
	if (verifyIdForSearch(stringId, tree) == false) {
		return false;
	}
	return tree.removeByID(std::stoi(stringId));
}

// Helper method to help us search for a given name or ID is in the tree. If the command is search ID, it searches and validates the ID in tree, and if the command is 
// search NAME, it searches and validates the name (mulitple names can be found as long as they have different IDs). Returns true if even one instance is found, false if not).
bool searchHelper(std::string functionCall, int& location, AVLTree& tree) {
	std::string passedString = readString(functionCall, location);  // WE DONT KNOW IF AN ID OR NAME WILL BE PASSED IN SO BE CARFUL
	if (verifyName(passedString) == true) {
		return tree.studentSearchName(passedString);
	}
	else if (verifyIdForSearch(passedString, tree) == true) {
		Node* node = tree.studentSearchID(std::stoi(passedString));
		if (node == nullptr) {
			return false;
		}
		else {
			std::cout << node->getStudent().getName() << std::endl;
			return true;
		}
	}
	else {
		return false;
	}
}

// Helps remove Inorder. Returns true if the item could be successfully removed, false if not.
bool removeInorderHelper(std::string functionCall, int& location, AVLTree& tree) {
	std::string stringNthNode = readNthNode(functionCall, ++location);
	return tree.removeIDInorder(std::stoi(stringNthNode));
}

// runProgram essentially goes through each possible command and acts correspondingly
int runProgram() {
	AVLTree tree; // Creates AVLTree object

	int numCalls = 0;
	std::cin >> numCalls;

	// Loops for each call in the program
	while (numCalls > 0) {

		std::string functionCall = "";
		std::getline(std::cin >> std::ws, functionCall); // help from stackoverflow.com/questions/5838711/stdcin-input-with-spaces

		int location = functionCall.find(' ');
		std::string command = functionCall.substr(0, location);

		// Conducts insert command's operations
		if (command == "insert") {
			if (insertHelper(functionCall, location, tree) == false) {
				std::cout << "unsuccessful" << "\n";
			}
			else {
				std::cout << "successful" << "\n";
			}
		}
		// Conducts remove command's operations
		else if (command == "remove") {
			if (removeHelper(functionCall, location, tree) == false) {
				std::cout << "unsuccessful" << "\n";
			}
			else {
				std::cout << "successful" << "\n";
			}
		}
		// Conducts search command's operations
		else if (command == "search") {
			if (searchHelper(functionCall, location, tree) == false) {
				std::cout << "unsuccessful" << "\n";
			}
		}
		// Conducts printInorder command's operations
		else if (command == "printInorder") {
			tree.printInorder();
			std::cout << "\n";
		}
		// Conducts printPreorder command's operations
		else if (command == "printPreorder") {
			tree.printPreorder();
			std::cout << "\n";
		}
		// Conducts printPostorder command's operations
		else if (command == "printPostorder") {
			tree.printPostorder();
			std::cout << "\n";
		}
		// Conducts printLevelCount command's operations
		else if (command == "printLevelCount") {
			tree.printLevelCount();
			std::cout << "\n";
		}
		// Conducts removeInorder command's operations
		else if (command == "removeInorder") {
			if (removeInorderHelper(functionCall, location, tree) == false) {
				std::cout << "unsuccessful" << "\n";
			}
			else {
				std::cout << "successful" << "\n";
			}
		}
		// If no commands are recognized, the command was unsuccessful
		else {
			std::cout << "unsuccessful" << "\n";
		}
		numCalls--;
	}


	return 0;
}

// Main function of the program. It calls the runProgram function
int main() {
	return runProgram();
}
