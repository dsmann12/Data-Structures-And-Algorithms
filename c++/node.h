#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
	public:
		Node();
		Node(const E& e);
		const E& element() const;
		void set(const E& e);
	protected:
		E element_;
};

template <typename E>
Node<E>::Node() :
	element_{} {}

template <typename E>
Node<E>::Node(const E& e) : 
	element_{e} {}

template <typename E>
const E& Node<E>::element() const {
	return element_;
}

template <typename E>
void Node<E>::set(const E& e) {
	element_ = e;
}

template <typename E>
std::ostream& operator <<(std::ostream& os, const Node<E>& n) {
	return os << n.element();
}

#endif
