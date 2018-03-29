#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

// top
// push(e)
// pop
// size
// empty()

class StackEmpty : std::runtime_error {
	public:
		StackEmpty(const std::string& err) :
			std::runtime_error(err) {}	
};

template <typename E>
class Stack {
	public:
		Stack();
		void push(const E& e);
		void pop();
		const E& top() const;
		int size() const;
		bool empty() const;

	private:
		int size_;
		LinkedList<E> stack;
};

template <typename E>
Stack<E>::Stack() :
	size_{0}, stack{} {}

template <typename E>
void Stack<E>::push(const E& e) {
	stack.add_front(e);
	size_++;
}

template <typename E>
void Stack<E>::pop() {
	if (empty()) {
		throw StackEmpty("Stack is empty!");
	}
	stack.remove_front();
	size_--;
}

template <typename E>
const E& Stack<E>::top() const {
	if (empty()) {
		throw StackEmpty("Stack is empty!");
	}
	return stack.front();
}

template <typename E>
int Stack<E>::size() const {
	return size_;
}

template<typename E>
bool Stack<E>::empty() const {
	return size_ == 0;
}

#endif
