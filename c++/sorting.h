#ifndef SORTING_H
#define SORTING_H

namespace sorting {
	void generate_numbers_file();
	int read_file(int** a);
	void print_array(int* a, int size);
	void insertion_sort(int *a, int size);
};

#endif
