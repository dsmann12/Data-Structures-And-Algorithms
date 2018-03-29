#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

// push(E)
// pop(E)
// empty()
// full()
// top()
// size()

class StackError : public std::runtime_error {
	public:
		StackError(const std::string& err) : runtime_error(err) {}
};

template <typename E>
class ArrayStack {
	public:
		ArrayStack(int cap = DEF_CAPACITY);
		~ArrayStack();
		// copy constructor
		ArrayStack(const ArrayStack<E>& stack);
		// move constructor
		ArrayStack(ArrayStack<E>&& stack);
		// copy assignment
		ArrayStack<E>& operator=(const ArrayStack<E>& stack);
		// move assignment
		ArrayStack<E>& operator=(ArrayStack<E>&& stack);
		int size() const;
		bool empty() const;
		bool full() const;
		void push(const E& e);
		void pop();
		const E& top() const;
	private:
		E* array;
		int capacity;
		int top_;
		static const int DEF_CAPACITY = 100;
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) :
	array{new E[cap]}, capacity{cap}, top_{-1} {}

template <typename E>
ArrayStack<E>::ArrayStack(const ArrayStack<E>& stack) :
	array{new E[stack.capacity]}, capacity{stack.capacity}, top_{stack.top_} {

	std::copy(stack.array, stack.array+stack.size(), array);
}

template <typename E>
ArrayStack<E>::ArrayStack(ArrayStack<E>&& stack) :
	array{stack.array}, capacity{stack.capacity}, top_{stack.top_} {
	stack.array = nullptr;
	stack.top_ = -1;
	stack.capacity = 0;
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
	delete[] array;
}

template <typename E>
ArrayStack<E>& ArrayStack<E>::operator=(const ArrayStack<E>& stack) {
	// create new array pointer
	E* p = new E[stack.capacity];
	
	// delete old array elements
	delete[] array;
	
	// copy stack parameter elements into p
	std::copy(stack.array, stack.array+stack.size(), p);
	
	// set array = to p
	array = p;
	top_ = stack.top_;
	capacity = stack.capacity;
	
	return *this;
}

template <typename E>
ArrayStack<E>& ArrayStack<E>::operator=(ArrayStack<E>&& stack) {
	// delete old array
	delete[] array;
	
	// array = stack.array
	array = stack.array;
	capacity = stack.capacity;
	top_ = stack.top_;

	// make stack parameter empty
	stack.array = nullptr;
	stack.capacity = 0;
	stack.top_ = -1;

	return *this;
}

template <typename E>
int ArrayStack<E>::size() const { return top_ + 1; }

template <typename E>
bool ArrayStack<E>::empty() const { return top_ < 0; }

template <typename E>
bool ArrayStack<E>::full() const { return top_ + 1 == capacity; }

template <typename E>
void ArrayStack<E>::push(const E& e) {
	if (full()) {
		throw StackError("Stack is full!");
	}

	// increment top and set index to element e
	array[++top_] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
	if (empty()) throw StackError("Stack is empty!");
	
	// decrement top
	top_--;
}

template <typename E>
const E& ArrayStack<E>::top() const {
	if (empty()) throw StackError("Stack is empty!");
	
	return array[top_];
}

#endif
