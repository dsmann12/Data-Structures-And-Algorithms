#include <iostream>
#include "array_stack.h"

// print top
void print_top(ArrayStack<int> &a) {
	try {
		std::cout << a.top() << std::endl;
	} catch (StackError e) {
		std::cout << e.what() << std::endl;
	}
}

// pop
void pop(ArrayStack<int> &a) {
	try {
		a.pop();
	} catch (StackError e) {
		std::cout << e.what() << std::endl;
	}
}

// push
void push(ArrayStack<int> &a, int n) {
	try {
		a.push(n);
	} catch (StackError e) {
		std::cout << e.what() << std::endl;
	}
}

// test move constructor and move assignment
ArrayStack<int> move(int n) {
	ArrayStack<int> stack{n};
	for(int i = 0; i < n; i++) {
		push(stack, i);
	}

	return stack;
}

int main() {
	ArrayStack<int> stack;
	push(stack, 7);
	push(stack, 13);
	print_top(stack);
	pop(stack);
	push(stack, 9);
	print_top(stack);
	pop(stack);
	print_top(stack);
	pop(stack);
	print_top(stack);
	print_top(stack);

	ArrayStack<int> stack2{5};
	push(stack2, 7);
	push(stack2, 8);
	push(stack2, 9);
	push(stack2, 10);
	push(stack2, 11);
	push(stack2, 12);
	ArrayStack<int> stack3{stack2};
	print_top(stack2);
	pop(stack2);
	print_top(stack2);
	pop(stack2);
	print_top(stack2);
	pop(stack2);
	print_top(stack2);
	pop(stack2);
	print_top(stack2);
	pop(stack2);
	print_top(stack2);
	pop(stack2);
	
	print_top(stack3);

	ArrayStack<int> stack4{move(5)};
	print_top(stack4);
	stack = move(10);
	print_top(stack);
	return 0;
}
