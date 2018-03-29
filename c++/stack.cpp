#include <iostream>
#include "stack.h"

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.top() << std::endl;
	stack.pop();
	stack.pop();
	
	return 0;	
}
