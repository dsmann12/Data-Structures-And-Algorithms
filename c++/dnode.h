#ifndef DNODE_H
#define DNODE_H

#include "node.h"

template <typename E>
class DNode : public Node<E> {
	public:
		DLNode();
		DLNode(const E& e);
		DLNode(const E& e, DLNode<E>& p, DLNode<E>& n);
		DLNode<E>* const prev();
		DLNode<E>* const next();
		void set_prev(DLNode<E>* const n);
		void set_next(DLNode<E>* const n);
	protected:
		DLNode<E> *prev_;
		DLNode<E> *next_;
};

template <typename E>
template <typename E>
template <typename E>
template <typename E>
template <typename E>
template <typename E>
template <typename E>

#endif
