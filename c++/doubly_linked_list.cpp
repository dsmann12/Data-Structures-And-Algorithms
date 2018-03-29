#include <string>
#include <iostream>
#include "doubly_linked_list.h"

template <typename E>
void print_front(const DoublyLinkedList<E>& list) {
	// return front (should throw exception)
	try {
		std::cout << list.front() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Oh no an exception occurred!\n";
	}
}

template <typename E>
void print_back(const DoublyLinkedList<E>& list) {
	try {
		std::cout << list.back() << std::endl;
	} 
	catch (std::exception e) {
		std::cout << "No back\n";
	}
}

int main() {
	DoublyLinkedList<std::string> dl{};
	dl.print();
	
	print_front(dl);
	print_back(dl);

	dl.add_front("David");
	dl.print();
	
	print_front(dl);
	print_back(dl);
	
	dl.add_back("Bradley");
	print_front(dl);
	print_back(dl);
	
	dl.print();
	
	dl.add_front("Martina");
	print_front(dl);
	print_back(dl);

	dl.print();
	
	dl.remove_front();
	std::cout << std::endl;
	dl.print();

	dl.remove_back();
	std::cout << std::endl;
	dl.print();

}
