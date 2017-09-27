#include<string>
#include "linked_list.h"

int main() {
	LinkedList<std::string> list;
	list.add_front("Bradley");
	list.print();
	
	// testing add_front
	std:: cout << "\nTesting add_front(): \n";

	list.add_front("David");
	list.add_front("Martina");
	list.add_front("Ashleigh");
	
	std::cout << "Printing list: \n";
	list.print();

	// Testing copy constructor
	std::cout << "\nTesting copy constructor: \n";
	LinkedList<std::string> list1{list};
	std::cout << "\nPrinting new list: \n";
	list1.print();
	
	// testing add_last
	std::cout << "\nTesting add_last(): \n";
	
	list.add_last("Emily");
	list.add_last("Pepper");
	list.add_last("Daniella");
	
	std::cout << "Printing list: \n";
	list.print();

	// testing front()
	std::cout << "\nTesting front(): \n";
	std::cout << list.front() << std::endl;

	// testing last()
	std::cout << "\nTesting last(): \n";
	std::cout << list.last() << std::endl;

	// testing copy assignment
	std::cout << "\nTesting copy assignment\n";
	LinkedList<std::string> list2;
	list2 = list;
	std::cout << "Printing list2: \n";
	list2.print();

	// testing remove_front()
	std::cout << "\nTesting remove_front(): \n";
	std::cout << "Removing front: \n";
	list.remove_front();
	list.print();

	// testing front()
	std::cout << "\nTesting front(): \n";
	std::cout << list.front() << std::endl;

	// test last()
	std::cout << "\nTesting last(): \n";
	std::cout << list.last() << std::endl;
	
	// test remove_front()
	std::cout << "\nRemoving front: \n";
	list.remove_front();
	list.print();

	// testing front()
	std::cout << "\nTesting front(): \n";
	std::cout << list.front() << std::endl;

	// testing front as variable
	std::string test_string = list.front();
	std::cout << "\nTest string: " << test_string << std::endl;

	// Delete list
	std::cout << "\nDeleting entire list from front\n";
	while(!list.empty()) {
		list.remove_front();
	}
	
	// test copied variable
	std::cout << "\nPrinting list1: \n";
	list1.print();

	// test assignment copied variable
	std::cout << "\nPrinting list2: \n";
	list2.print();
	
	return 0;
}
