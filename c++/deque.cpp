#include <iostream>
#include "deque.h"

int main() {
	Deque<std::string> d;

	d.add_front("Ashleigh");
	d.add_back("Martina");
	d.add_back("Bradley");
	d.add_front("David");

	std::cout << "Size of deque is " << d.size() << std::endl;	
	while(!d.empty()) {
		std::cout << d.front() << std::endl;
		d.remove_front();
	}

	return 0;
}
