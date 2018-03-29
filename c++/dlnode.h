#ifndef DLNODE_H
#define DLNODE_H

#include "node.h"

template <typename E>
class DLNode : public Node<E> {
	public:
		DLNode();
		DLNode(const E& e);
		DLNode(const E& e, DLNode<E>* const p, DLNode<E>* const n);
		DLNode<E>* const prev() const;
		DLNode<E>* const next() const;
		void set_prev(DLNode<E>* const n);
		void set_next(DLNode<E>* const n);
	protected:
		DLNode<E> *prev_;
		DLNode<E> *next_;
};

template <typename E>
DLNode<E>::DLNode() :
	Node<E>::Node{}, prev_{nullptr}, next_{nullptr} {}

template <typename E>
DLNode<E>::DLNode(const E& e) :
	Node<E>::Node{e}, prev_{nullptr}, next_{nullptr} {}

template <typename E>
DLNode<E>::DLNode(const E& e, DLNode<E>* const p, DLNode<E>* const n) :
	Node<E>::Node{e}, prev_{p}, next_{n} {}

template <typename E>
DLNode<E>* const DLNode<E>::prev() const {
	return prev_;
}

template <typename E>
DLNode<E>* const DLNode<E>::next() const {
	return next_;
}

template <typename E>
void DLNode<E>::set_prev(DLNode<E>* const n) {
	prev_ = n;
}

template <typename E>
void DLNode<E>::set_next(DLNode<E>* const n) {
	next_ = n;
}

#endif
