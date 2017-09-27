#include <iostream>
#include <string>
#include "lnode.h"

int main() {
	LNode<std::string> sn{"David"};
	std::cout << sn << std::endl;
	
	LNode<std::string> sn1{}; 
	std::cout << sn1 << std::endl;

	sn1.set("Emily");
	std::cout << sn1 << std::endl;

	sn.set_next(&sn1);
	
	LNode<std::string>* np = sn.next();
	
	std::cout << sn << std::endl;
	std::cout << *np << std::endl;
	std::cout << *(sn.next()) << std::endl;

	if (sn1.next() == nullptr) {
		std::cout << "SN1 POINTS TO NULL\n";
	}

	return 0;
}
