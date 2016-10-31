/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/12/16 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using std::string;
using std::cout;
using std::cin;
using std::copy;

struct atLeastThree{
	bool operator()(const string& s) const{
		return (s.length() > 3);
	}
};

int main(){
	std::vector<string> strv1 = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}, strv2;
	std::deque<string> strd;
	std::set<string> strs;
	std::ostream_iterator<string> osti(cout, " ");

	copy(strv1.begin(), strv1.end(), std::back_inserter(strv2));
	copy(strv1.begin(), strv1.end(), std::front_inserter(strd));
	copy(strv1.begin(), strv1.end(), std::inserter(strs, strs.begin()));

	cout << "Output for the first vector (original text): ";
	copy(strv1.begin(), strv1.end(), osti); //vector output
	cout << "\nOutput for the second vector: ";
	copy(strv2.begin(), strv2.end(), osti); //second vector output
	cout << "\nOutput for the deque: ";
	copy(strd.begin(), strd.end(), osti); //deque output
	cout << "\nOutput for the set: ";
	copy(strs.begin(), strs.end(), osti); //set output
	cout << '\n';

	std::vector<string> strv3 = {"An", "albino", "bear", "jumps", "over", "a", "small", "lazy", "dog"}, strv4;
	std::deque<string> strd2;
	std::set<string> strs2;

	copy_if(strv3.begin(), strv3.end(), std::back_inserter(strv4), atLeastThree());
	copy_if(strv3.begin(), strv3.end(), std::front_inserter(strd2), atLeastThree());
	copy_if(strv3.begin(), strv3.end(), std::inserter(strs2, strs2.begin()), atLeastThree());

	cout << "Output for the third vector (original text): ";
	copy(strv3.begin(), strv3.end(), osti); //vector output
	cout << "\nOutput for the fourth vector: ";
	copy(strv4.begin(), strv4.end(), osti); //second vector output
	cout << "\nOutput for the second deque: ";
	copy(strd2.begin(), strd2.end(), osti); //deque output
	cout << "\nOutput for the second set: ";
	copy(strs2.begin(), strs2.end(), osti); //set output
	cout << '\n';

	return 0;
}

/* Output:
Output for the first vector (original text): The quick brown fox jumps over the lazy dog
Output for the second vector: The quick brown fox jumps over the lazy dog
Output for the deque: dog lazy the over jumps fox brown quick The
Output for the set: The brown dog fox jumps lazy over quick the
Output for the third vector (original text): An albino bear jumps over a small lazy dog
Output for the fourth vector: albino bear jumps over small lazy
Output for the second deque: lazy small over jumps bear albino
Output for the second set: albino bear jumps lazy over small
*/
