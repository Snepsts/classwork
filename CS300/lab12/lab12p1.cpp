/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/31/16 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using std::cin;
using std::cout;
using std::copy;
using std::string;

int main(int argc, char** argv){
	std::istream_iterator<string> ist(cin);
	std::istream_iterator<string> eof;
	std::ostream_iterator<string> ost(cout, " ");

	//part 1
	cout <<"Part 1:\n\n";

	copy(ist, eof, ost);

	//part 2
	cout << "\n\nPart 2:\n\n";

	std::ifstream fin;
	fin.open("shortstory.txt");

	if(fin.fail()){
		cout << "Where is shortstory.txt???\n";
		return 1;
	}

	std::istream_iterator<string> fist(fin);

	copy(fist, eof, ost);

	cout << '\n';

	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab12$ ./lab12p1.out < shortstory.txt
Part 1:

Once upon a time, aeons ago, on a world orbiting a distant sun very much unlike our own an intelligence we could not begin to comprehend had a thought we could not even conceive of, let alone understand, which would, in the fullnes of time have absolutely no discernible effect on us. "We are so large against the sky, so small against the stars ..." according to Leonard Cohen. Verily, a big frog in a very small pond. Meanwhile, back at the ranch, the lone ranger mistaking his trust indian companion Tonto .... Lone ranger jokes are a step down from elephant jokes. Well it's time to go now. If you are good, next time I'll tell you the shaggy dog story that has the punch line "You can't sent a Knight out on a dog like this."

Part 2:

Once upon a time, aeons ago, on a world orbiting a distant sun very much unlike our own an intelligence we could not begin to comprehend had a thought we could not even conceive of, let alone understand, which would, in the fullnes of time have absolutely no discernible effect on us. "We are so large against the sky, so small against the stars ..." according to Leonard Cohen. Verily, a big frog in a very small pond. Meanwhile, back at the ranch, the lone ranger mistaking his trust indian companion Tonto .... Lone ranger jokes are a step down from elephant jokes. Well it's time to go now. If you are good, next time I'll tell you the shaggy dog story that has the punch line "You can't sent a Knight out on a dog like this."
*/
