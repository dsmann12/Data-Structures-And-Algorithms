#include <cstdlib>
#include <iostream>
#include <string>
#include "node.h"

int main() {
	Node<std::string> s;
	Node<int> n;

	std::cout << s << std::endl;
	std::cout << n << std::endl;

	Node<std::string> s1{"David"};
	Node<int> n1{100};

	std::cout << s1 << std::endl;
	std::cout << n1 << std::endl;

	n.set(1000);
	s.set("Emily");
	
	std::cout << "After set:\n";
	std::cout << s << std::endl;
	std::cout << n << std::endl;	

	return 0;
}
