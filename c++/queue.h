#ifndef QUEUE_H
#define QUEUE_H

class QueueEmpty : std::runtime_error {
	public:
		QueueEmpty(const std::string& err) :
			std::runtime_error(err) {}
}

// queue
template <typename E>
class Queue {
	public:
		Queue();
		void enqueue(const E& e);
		void dequeue();
		const E& front() const;
		int size() const;
		bool empty() const;
	private:
		LinkedList<E> queue;
		int size_;
};

template <typename E>
Queue<E>::Queue() :
	queue{}, size_{0} {}

template <typename E>
void Queue<E>::enqueue(const E& e) {
	queue.add_last(e);
	size_++;
}

template <typename E>
void Queue<E>::dequeue() {
	queue.remove_front();
	size_--;
}

template <typename E>
const E& Queue<E>::front() const {
	return queue.front();
}

template <typename E>
int size() const {
	return size_;
}

template <typename E>
bool empty() const {
	return size_ == 0;
}

#endif
