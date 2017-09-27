#ifndef LNODE_H
#define LNODE_H

#include "node.h"

template <typename E>
class LNode : public Node<E> {
	public:
		LNode(); 
		LNode(const E& e); 
		LNode(const E& e, LNode<E>* const n);
		LNode<E> * const next();
		void set_next(LNode<E>* const n);
	protected:
		LNode<E> *next_;
};

template <typename E>
LNode<E>::LNode() :
	Node<E>::Node{}, next_{nullptr} {}


template <typename E>
LNode<E>::LNode(const E& e) :
	Node<E>::Node{e}, next_{nullptr} {}

template <typename E>
LNode<E>::LNode(const E& e, LNode<E>* const n) :
	Node<E>::Node{e}, next_{n} {}

template <typename E>
LNode<E>* const LNode<E>::next() {
	return next_;
}

template <typename E>
void LNode<E>::set_next(LNode<E>* const n) {
	next_ = n;
}

#endif
