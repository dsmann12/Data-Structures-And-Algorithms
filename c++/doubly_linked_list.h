#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "dlnode.h"

template <typename E>
class DoublyLinkedList {
	public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList<E>& list);
		DoublyLinkedList(DoublyLinkedList<E>&& list);
		~DoublyLinkedList();
		DoublyLinkedList<E>& operator=(const DoublyLinkedList<E>& list);
		DoublyLinkedList<E>& operator=(DoublyLinkedList<E>&& list);
		const E& front() const;
		const E& back() const;
		void add_front(const E& e);
		void add_back(const E& e);
		void remove_front();
		void remove_back();
		bool empty() const;
		void print() const;
		void erase();
		const int size() const; // test
	private:
		DLNode<E>* header;
		DLNode<E>* trailer;
		int size_;
	protected:
		// add method
		void add_between(const E& e, DLNode<E>* prev, DLNode<E>* next);
		// remove method
		void remove(DLNode<E>* n);
};

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList() :
	header{new DLNode<E>{}}, trailer{new DLNode<E>{}}, size_{0} {

	header->set_next(trailer);
	trailer->set_prev(header);
}

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList(const DoublyLinkedList<E>& list) :
	header{new DLNode<E>{}}, trailer{new DLNode<E>{}}, size_{0} {
	
	header->set_next(trailer);
	trailer->set_prev(header);
	
	DLNode<E>* node = list.header->next();
	while (node != list.trailer) {
		add_back(node->element());
		node = node->next();
	}
} 

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList(DoublyLinkedList<E>&& list) : 
	header{list.header}, trailer{list.trailer}, size_{list.size_} {
	
	list.size_ = 0;
	list.header = list.trailer = nullptr;
}

template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList() {
	erase();
	delete header;
	delete trailer;
}

template <typename E>
DoublyLinkedList<E>& DoublyLinkedList<E>::operator=(const DoublyLinkedList<E>& list) {
	
	erase();
	
	DLNode<E>* node = list.header->next();
	
	while (node != list.trailer) {
		add_back(node->element());
		node = node->next();
	}

	return *this;
}

template <typename E>
DoublyLinkedList<E>& DoublyLinkedList<E>::operator=(DoublyLinkedList<E>&& list) {
	header = list.header;
	trailer = list.trailer;
	size_ = list.size_;

	list.size_ = 0;
	list.header = list.trailer = nullptr;

	return *this;
}

template <typename E>
const E& DoublyLinkedList<E>::front() const {
	if (empty()) {
		throw std::exception();
	}

	return header->next()->element();
}

template <typename E>
const E& DoublyLinkedList<E>::back() const {
	if (empty()) {
		throw std::exception();
	}

	return trailer->prev()->element();
}

template <typename E>
void DoublyLinkedList<E>::add_between(const E& e, DLNode<E>* prev, DLNode<E>* next) {
	// create a new node
	DLNode<E>* node = new DLNode<E>{e};
	
	// prev's new next is node
	prev->set_next(node);
	// next's new prev is node
	next->set_prev(node);

	// node's prev is prev and next is next
	node->set_prev(prev);
	node->set_next(next);
	
	// increment size
	++size_;
}

template <typename E>
void DoublyLinkedList<E>::add_front(const E& e) {
	// add between header and header.next
	add_between(e, header, header->next());
}

template <typename E>
void DoublyLinkedList<E>::add_back(const E& e) {
	// add between trailer.prev and trailer
	add_between(e, trailer->prev(), trailer);
}

template <typename E>
void DoublyLinkedList<E>::remove(DLNode<E>* const n) {
	DLNode<E>* prev = n->prev();
	DLNode<E>* next = n->next();

	prev->set_next(next);
	next->set_prev(prev);
	
	delete n;
	
	--size_;
}

template <typename E>
void DoublyLinkedList<E>::remove_front() {
	// remove front
	// if empty, do nothing
	if (empty()) {
		return;
	}

	// otherwise remove header->next()
	remove(header->next());
}

template <typename E>
void DoublyLinkedList<E>::remove_back() {
	if (empty()) {
		return;
	}
	
	remove(trailer->prev());
}

template <typename E>
bool DoublyLinkedList<E>::empty() const {
	return (size_ == 0);
}

template <typename E>
void DoublyLinkedList<E>::print() const {
	DLNode<E>* node = header->next();

	while(node != trailer) {
		std::cout << *node << std::endl;
		node = node->next();
	}
}

template <typename E>
void DoublyLinkedList<E>::erase() {
	while (!empty()) {
		remove_front();
	}
}

#endif
