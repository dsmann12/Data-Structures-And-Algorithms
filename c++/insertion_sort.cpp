#include <iostream>
#include "sorting.h"

int main() {
	int* a;
	int size = sorting::read_file(&a);
	sorting::print_array(a, 15);
	sorting::insertion_sort(a, 15);
	sorting::print_array(a, 15);
	delete[] a;
	return 0;
}
