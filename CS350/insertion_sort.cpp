#include <iostream> //cout
#include <random> //default_random_engine and uniform_int_distribution
#include <ctime> //time for default_random_engine

void fill(int array[]); //fill array with random numbers
void print(int array[]); //print array in a table
void sort(int array[]); //insertion sort the array

const int SIZE = 100000; //size_of_array

int main()
{
	clock_t begin = clock();

	int array[SIZE];

	fill(array); //randomize array
	std::cout << "*** Array Unsorted *** \n\n\n";
	print(array); //view it unsorted
	sort(array);
	std::cout << "\n\n\n *** Array Sorted *** \n\n\n";
	print(array);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Time it took: " << elapsed_secs << '\n';

	return 0;
}

void fill(int array[])
{
	std::default_random_engine dre;
	dre.seed(time(nullptr));
	std::uniform_int_distribution<int> dr(1, 10000);

	for (int i = 0; i < SIZE; i++)
		array[i] = dr(dre);
}

void print(int array[])
{ //print in a table format
	for (int i = 0; i < SIZE; i += 8) {
		if (i < SIZE) //these if statements are for saftey of array bounds
			std::cout << array[i] << '\t';
		if (i + 1 < SIZE)
			std::cout << array[i+1] << '\t';
		if (i + 2 < SIZE)
			std::cout << array[i+2] << '\t';
		if (i + 3 < SIZE)
			std::cout << array[i+3] << '\t';
		if (i + 4 < SIZE)
			std::cout << array[i+4] << '\t';
		if (i + 5 < SIZE)
			std::cout << array[i+5] << '\t';
		if (i + 6 < SIZE)
			std::cout << array[i+6] << '\t';
		if (i + 7 < SIZE)
			std::cout << array[i+7] << '\t';

		std::cout << '\n';
	}
}

/* sort
    This function takes an array and sorts it based on the SIZE.
*/
void sort(int array[]) //insertion sort
{
	for (int i = 1; i < SIZE; i++) {
		//register cuts average time in half (28.6951 to 14.6948 with no -O option)
		register int index = i-1;
		int var = array[i]; //variable that we're shifting for

		while(index > 0 && var < array[index]) //find the begin index
		{
			array[index+1] = array[index];
			index--;
		}

		array[index+1] = var;
	}
}

// -O2 : 4.34775, 4.41609, 4.30265
// -O3 : 4.45471, 4.36048, 4.26414
