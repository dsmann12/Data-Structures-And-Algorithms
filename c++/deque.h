#ifndef DEQUE_H
#define DEQUE_H

#include "doubly_linked_list.h"

class DequeEmpty : std::runtime_error {
	public:
		DequeEmpty(const std::string& err) :
			std::runtime_error(err) {}
};

// deque
template <typename E>
class Deque{
	public:
		Deque();
		void add_front(const E& e);
		void add_back(const E& e);
		void remove_front();
		void remove_back();
		const E& front() const;
		const E& back() const;
		int size() const;
		bool empty() const;
	private:
		DoublyLinkedList<E> deque;
		int size_ = 0;
		void empty_check() const;
};

template <typename E>
Deque<E>::Deque() :
	size_{0}, deque{} {}

template <typename E>
void Deque<E>::add_front(const E& e) {
	deque.add_front(e);
	size_++;
}

template <typename E>
void Deque<E>::add_back(const E& e) {
	deque.add_back(e);
	size_++;
}

template <typename E>
void Deque<E>::remove_front() {
	empty_check();
	deque.remove_front();
	size_--;
}

template <typename E>
void Deque<E>::remove_back() {
	empty_check();
	deque.remove_back();
	size_--;
}

template <typename E>
const E& Deque<E>::front() const {
	empty_check();
	return deque.front();
}

template <typename E>
const E& Deque<E>::back() const {
	empty_check();
	return deque.back();
}

template <typename E>
int Deque<E>::size() const {
	return size_;
}

template <typename E>
bool Deque<E>::empty() const {
	return (size_ == 0);
}

template <typename E>
void Deque<E>::empty_check() const {
	if (empty()) {
		throw DequeEmpty("Deque is empty");
	}
	
	return;
}

#endif
