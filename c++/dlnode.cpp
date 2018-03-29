#include <string>
#include <iostream>
#include "dlnode.h"

int main() {
	DLNode<std::string> n("David");
	std::cout << n << std::endl;
	
	DLNode<std::string> n1("Emily");
	DLNode<std::string> n2("Martina");
	
	DLNode<std::string> e;
	std::cout << e << std::endl;

	n.set_prev(&n2);
	n.set_next(&n1);
	
	std::cout << *n.prev() << std::endl;
	std::cout << *n.next() << std::endl;
}


