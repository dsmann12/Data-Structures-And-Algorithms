#include <iostream>
#include "queue.h"

int main() {
	Queue<std::string> q;
	q.enqueue("Ashleigh");
	q.enqueue("Martina");
	q.enqueue("David");
	q.enqueue("Bradley");
	
	while(!q.empty()) {
		std::cout << q.front() << std::endl;
		q.dequeue();
	}

	return 0;
}
