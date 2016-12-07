/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/31/16 */

#include <iostream>
#include <iterator>

int main(int argc, char **argv){
	std::istream_iterator<int> ist(std::cin);
	std::istream_iterator<int> eof;
	std::ostream_iterator<int> ost(std::cout, " ");

	std::copy(ist, eof, ost);

	cout << '\n';

	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab12$ ./lab12p2.out
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
*/
