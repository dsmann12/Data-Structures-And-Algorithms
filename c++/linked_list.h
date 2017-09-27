#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "lnode.h"

template <typename E>
class LinkedList {
	public:
		LinkedList();
		LinkedList(const LinkedList<E>& list);
		LinkedList(LinkedList<E>&& list);
		~LinkedList();
		LinkedList<E>& operator=(const LinkedList<E>& list);
		LinkedList<E>& operator=(LinkedList<E>&& list);
		const E& front() const;
		const E& last() const;
		void add_front(const E& e);
		void add_last(const E& e);
		void remove_front();
		void erase();
		void print();
		bool empty() const;		
		const int& size() const;
	protected:
		LNode<E>* head;
		LNode<E>* tail;
		int size_;
};

template <typename E>
LinkedList<E>::LinkedList() :
	head{nullptr}, tail{nullptr}, size_{0} {}

template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E>& list) :
	head{nullptr}, tail{nullptr}, size_{0} {
	
	LNode<E>* node = list.head;
	while(node != nullptr) {
		add_last(node->element());
		node = node->next();
	}
}

template <typename E>
LinkedList<E>::LinkedList(LinkedList<E>&& list) :
	head{list.head}, tail{list.tail}, size_{list.size_} {

	list.size_ = 0;
	list.head = list.tail = nullptr;
}

template <typename E>
LinkedList<E>::~LinkedList() {
	erase();
}


template <typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E>& list) {
	
	// delete all nodes from this list
	erase();

	// get head of new list	
	LNode<E>* node = list.head;

	// have head point to new node with element equal to list's node
	while(node != nullptr) {
		add_last(node->element());	
		node = node->next();
	}

	return *this;
}

template <typename E>
LinkedList<E>& LinkedList<E>::operator=(LinkedList<E>&& list) {
	erase();

	head = list.head;
	tail = list.tail;
	size_ = list.size_;

	list.head = list.tail = nullptr;
	list.size_ = 0;

	return *this;
}

template <typename E>
const E& LinkedList<E>::front() const {
	return head->element();
}

template <typename E>
const E& LinkedList<E>::last() const {
	return tail->element();
}

template <typename E>
void LinkedList<E>::add_front(const E& e) {
	LNode<E>* node = new LNode<E>{e, head};
	head = node;
	if (empty()) {
		tail = node;
	}
	size_++;
}

template <typename E>
void LinkedList<E>::add_last(const E& e) {
	// add last
	LNode<E>* node = new LNode<E>{e};
	
	// if list is empty, head = node
	// else set tail.next to node
	if (empty()) {
		head = node;
	} else {
		tail->set_next(node);	
	}
	
	// tail is assigned to new node
	tail = node;
	// list size is incremented
	size_++;
}

template <typename E>
void LinkedList<E>::remove_front() {
	// remove front
	// if empty, return
	if (empty()) return;

	// head points to node to be removed
	// must delete old head
	// head must point to head.next
	LNode<E>* old = head;
	head = old->next();
	delete old;
	
	// decrement size
	size_--;
	
	// if size is now 0, tail = nullptr
	if (size_ == 0) {
		tail = nullptr;
	}
}

template <typename E>
void LinkedList<E>::erase() {
	while(!empty()) {
		remove_front();
	}
}

template <typename E>
void LinkedList<E>::print() {
	// while node pointer is not nullptr
	LNode<E>* node = head;
	while (node != nullptr) {
		std::cout << *node << std::endl;
		node = node->next(); 
	}
}

template <typename E>
bool LinkedList<E>::empty() const {
	return (size_ == 0);
}

template <typename E>
const int& LinkedList<E>::size() const {
	return size_;
}

#endif
