#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include "sorting.h"

namespace sorting {
	void generate_numbers_file() {
		int n = 0;

		while (n <= 0) {
			std::cout << "Enter a number greater than 0: ";
			std::cin >> n;
			std::cout << std::endl;
		}

		// Create file to hold n numbers
		std::ofstream fs("numbers.txt");
		if (!fs) {
			std::cout << "File Not Created!\n";
			return;
		}

		// Seed random number generator
		srand(time(NULL));

		fs << n << std::endl << std::endl;
		
		// Generate n Random Numbers
		for (int i = 0; i < n; i++) {
			fs << rand() % 100 << std::endl;
		}
		
		// Close File
		fs.close();
	}

	int read_file(int** a) {
		std::ifstream fs("numbers.txt");
		if (!fs) {
			return 0;
		}

		int size = 0;
		int n;

		if(!(fs >> size)) {
			return 0;
		}

		// Dynamically allocate array of size
		// Assign pointer parameter to array
		*a = new int[size];

		// Read through file and fill array
		for (int i = 0; fs >> n; i++) {
			(*a)[i] = n;
		}

		// Close file
		fs.close();

		// Return size of array
		return size;	
	}

	void print_array(int* a, int size) {
		if (a != NULL) {
			// Print array
			std::cout << "[" << a[0];
			for (int i = 1; i < size; i++) {
				std::cout << ", " << a[i];
			}
			std::cout << "]\n";
		}
	}
	
	void insertion_sort(int *a, int size) {
		if (a != NULL) {
			for(int i = 1; i < size; i++) {
				int cur = a[i];
				int j = i - 1;

				while((j >= 0) && (a[j] > cur)) {
					a[j+1] = a[j];
					j--;
				}

				a[j+1] = cur;
			}
		}
	}
}
