//#include "AVLTree.h"
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//
//bool insertHelper(std::string functionCall, int& location, AVLTree& tree);
//bool removeInorderHelper(std::string functionCall, int& location, AVLTree& tree);
//bool removeHelper(std::string functionCall, int& location, AVLTree& tree);
//
//std::string createIdFromNumber(int i) {
//	std::string strId = std::to_string(i);
//	if (strId.length() == 1) {
//		strId = "0000000" + strId;
//	}
//	else if (strId.length() == 2) {
//		strId = "000000" + strId;
//	}
//	return strId;
//}
//
///*
//	To check output (At the Project1 directory):
//		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
//*/
//
//TEST_CASE("Five Incorrect Commands", "[flag]") {
//
//	AVLTree tree; // Create a Tree object
//
//	int location = 6;
//	REQUIRE_FALSE(insertHelper("insert \"a1\" 00000000", location, tree)); // number in name
//
//	location = 6;
//	REQUIRE_FALSE(insertHelper("insert \"b\" 123456789", location, tree));  // nine numbers in the ID
//
//	location = 6;
//	REQUIRE_FALSE(insertHelper("insert \"c\" abc00000", location, tree));  // letters in the ID
//
//	location = 6;
//	REQUIRE_FALSE(insertHelper("insert \"d!@#\" 12345678", location, tree));  // special characters used
//
//	location = 6;
//	REQUIRE_FALSE(insertHelper("insert \"e\" 0", location, tree));  // only one digit in the ID
//}
//
//TEST_CASE("Three Edge Cases", "[flag]") {
//
//	AVLTree tree1; 
//	int location = 13;
//	REQUIRE_FALSE(removeInorderHelper("removeInorder 0", location, tree1)); // removing (given a nth index) from a tree that is empty
//
//	AVLTree tree2; 
//	location = 6;
//	tree2.fullInsert("a", "00000000");
//
//	REQUIRE_FALSE(removeHelper("remove 11111111", location, tree2)); // removing a specified ID from a tree (this ID does not exist)
//
//	AVLTree tree3;
//	location = 6;
//	tree3.fullInsert("a", "00000000");
//	REQUIRE_FALSE(insertHelper("insert \"a\" 00000000", location, tree3));  // re-inserting an existing ID
//}
//
//TEST_CASE("All Four Rotation Types", "[flag]") {
//
//	// ROTATION 1: RIGHT RIGHT CASE (left rotation) - 
//	// insert 1, then 2, then 3. After rotations, Node should be 2, left of node should be 1, and right node should be 3
//
//	AVLTree tree1;
//	tree1.fullInsert("one", "00000001");
//	tree1.fullInsert("two", "00000002");
//	tree1.fullInsert("three", "00000003");
//
//	std::string leftRotationCase = tree1.preorderToString();
//	REQUIRE(leftRotationCase == "two, one, three");
//
//
//	// ROTATION 2: LEFT LEFT CASE (right rotation) - 
//	// insert 3, then 2, then 1. After rotations, Node should be 2, left of node should be 1, and right node should be 3
//
//	AVLTree tree2;
//	tree2.fullInsert("three", "00000003");
//	tree2.fullInsert("two", "00000002");
//	tree2.fullInsert("one", "00000001");
//
//	std::string rightRotationCase = tree2.preorderToString();
//	REQUIRE(rightRotationCase == "two, one, three");
//
//	// ROTATION 3: RIGHT LEFT CASE (right left rotation) - 
//	// insert 1, then 3, then 2. After rotations, Node should be 2, left of node should be 1, and right node should be 3
//	
//	AVLTree tree3;
//	tree3.fullInsert("one", "00000001");
//	tree3.fullInsert("three", "00000003");
//	tree3.fullInsert("two", "00000002");
//
//	std::string rightLeftRotationCase = tree3.preorderToString();
//	REQUIRE(rightLeftRotationCase == "two, one, three");
//
//	// ROTATION 4: LEFT RIGHT CASE (left right rotation) - 
//	// insert 3, then 1, then 2. After rotations, Node should be 2, left of node should be 1, and right node should be 3
//
//	AVLTree tree4;
//	tree4.fullInsert("three", "00000003");
//	tree4.fullInsert("one", "00000001");
//	tree4.fullInsert("two", "00000002");
//
//	std::string leftRightRotationCase = tree4.preorderToString();
//	REQUIRE(leftRightRotationCase == "two, one, three");
//}
//
//TEST_CASE("Three Deletions Case", "[flag]") {
//
//	// DELETION OF NODE WITH NO CHILDREN
//	AVLTree tree1;
//	tree1.fullInsert("one", "00000001");
//	tree1.fullInsert("two", "00000002");
//	tree1.removeByID(00000002);
//
//	std::string deleteWithNoChildCase = tree1.preorderToString();
//	REQUIRE(deleteWithNoChildCase == "one");
//
//	// DELETION OF NODE WITH ONE CHILD
//	AVLTree tree2;
//	tree2.fullInsert("two", "00000002");
//	tree2.fullInsert("one", "00000001");
//	tree2.fullInsert("three", "00000003");
//	tree2.fullInsert("four", "00000004");
//
//	tree2.removeByID(00000003);
//
//	std::string deleteWithOneChildCase = tree2.preorderToString();
//	REQUIRE(deleteWithOneChildCase == "two, one, four");
//
//	// DELETION OF NODE WITH TWO CHILDREN
//	AVLTree tree3;
//	tree3.fullInsert("two", "00000002");
//	tree3.fullInsert("one", "00000001");
//	tree3.fullInsert("four", "00000004");
//	tree3.fullInsert("five", "00000005");
//	tree3.fullInsert("three", "00000003");
//
//	tree3.removeByID(00000004);
//
//	std::string deleteWithTWOChildrenCase = tree3.preorderToString();
//	REQUIRE(deleteWithTWOChildrenCase == "two, one, five, three");
//
//}
//// Tests the case where 100 nodes are added and then 10 are removed
//TEST_CASE("One Hundred Nodes Test", "[flag]") {
//	AVLTree tree1;
//	std::vector<int> deletedNodes;
//	
//	for (int i = 0; i < 100; i++) {
//		tree1.fullInsert("name", createIdFromNumber(i));
//	}
//	
//	while(deletedNodes.size() < 10){
//		int randomInput = rand() % 100;
//		if (std::find(deletedNodes.begin(), deletedNodes.end(), randomInput) == deletedNodes.end()) {
//			deletedNodes.push_back(randomInput);
//			tree1.removeByID(randomInput);
//		}
//	}
//	for (int i = 0; i < 100; i++) {
//		bool nodeDeleted = std::find(deletedNodes.begin(), deletedNodes.end(), i) != deletedNodes.end();
//		if (nodeDeleted == true) {
//			REQUIRE(tree1.studentSearchID(i) == nullptr);
//		}
//		else {
//			REQUIRE(tree1.studentSearchID(i) != nullptr);
//		}
//	}
//	
//}
