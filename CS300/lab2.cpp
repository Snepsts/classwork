#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <deque>

using std::cout;
using std::string;
using std::vector;
using std::deque;

int main()
{
	vector<string> vst = {"The", "quick", "brown", "fox", "jumps", "over",
						  "the", "lazy", "dog"};

	cout << "Using a vector:\n";

	//1st way
	cout << "1. ";
	for (int i = 0; i < vst.size(); i++)
		cout << vst[i] << ' ';
	cout << '\n';

	//2nd way
	cout << "2. ";
	for (vector<string>::size_type i = 0; i < vst.size(); i++)
		cout << vst[i] << ' ';
	cout << '\n';

	//3rd way
	cout << "3. ";
	for (vector<string>::iterator vsit = vst.begin(); vsit != vst.end(); vsit++)
		cout << *vsit << ' ';
	cout << '\n';

	//4th way
	cout << "4. ";
	for (vector<string>::const_iterator cvsit = vst.cbegin(); cvsit != vst.cend(); cvsit++)
		cout << *cvsit << ' ';
	cout << '\n';

	//5th way
	cout << "5. ";
	for (vector<string>::reverse_iterator rvsit = vst.rend() - 1; rvsit != vst.rbegin() - 1; rvsit--)
		cout << *rvsit << ' ';
	cout << '\n';

	//6th way
	cout << "6. ";
	for (vector<string>::const_reverse_iterator crvsit = vst.crend() - 1; crvsit != vst.crbegin() - 1; crvsit--)
		cout << *crvsit << ' ';
	cout << '\n';

	//7th way
	cout << "7. ";
	for (vector<string>::iterator vsit = begin(vst); vsit != end(vst); vsit++)
		cout << *vsit << ' ';
	cout << '\n';

	//8th way (part 1)
	cout << "8.1. ";
	for (auto i = 0; i < vst.size(); i++)
		cout << vst[i] << ' ';
	cout << '\n';

	//8th way (part 2)
	cout << "8.2. ";
	for (auto vsit = vst.begin(); vsit != vst.end(); vsit++)
		cout << *vsit << ' ';
	cout << '\n';

	//8th way (part 3)
	cout << "8.3. ";
	for (auto cvsit = vst.cbegin(); cvsit != vst.cend(); cvsit++)
		cout << *cvsit << ' ';
	cout << '\n';

	//8th way (part 4)
	cout << "8.4. ";
	for (auto rvsit = vst.rend() - 1; rvsit != vst.rbegin() - 1; rvsit--)
		cout << *rvsit << ' ';
	cout << '\n';

	//8th way (part 5 )
	cout << "8.5. ";
	for (auto crvsit = vst.crend() - 1; crvsit != vst.crbegin() - 1; crvsit--)
		cout << *crvsit << ' ';
	cout << '\n';

	//8th way (part 6)
	cout << "8.6. ";
	for (auto vsit = begin(vst); vsit != end(vst); vsit++)
		cout << *vsit << ' ';
	cout << '\n';

	//9th way
	cout << "9. ";
	for (string i : vst)
		cout << i << ' ';
	cout << '\n';

	cout << "Using a deque:\n";

	deque<string> dst = {"The", "quick", "brown", "fox", "jumps", "over",
						  "the", "lazy", "dog"};

	//1st way
	cout << "1. ";
	for (int i = 0; i < dst.size(); i++)
		cout << dst[i] << ' ';
	cout << '\n';

	//2nd way
	cout << "2. ";
	for (deque<string>::size_type i = 0; i < dst.size(); i++)
		cout << dst[i] << ' ';
	cout << '\n';

	//3rd way
	cout << "3. ";
	for (deque<string>::iterator dsit = dst.begin(); dsit != dst.end(); dsit++)
		cout << *dsit << ' ';
	cout << '\n';

	//4th way
	cout << "4. ";
	for (deque<string>::const_iterator cdsit = dst.cbegin(); cdsit != dst.cend(); cdsit++)
		cout << *cdsit << ' ';
	cout << '\n';

	//5th way
	cout << "5. ";
	for (deque<string>::reverse_iterator rdsit = dst.rend() - 1; rdsit != dst.rbegin() - 1; rdsit--)
		cout << *rdsit << ' ';
	cout << '\n';

	//6th way
	cout << "6. ";
	for (deque<string>::const_reverse_iterator crdsit = dst.crend() - 1; crdsit != dst.crbegin() - 1; crdsit--)
		cout << *crdsit << ' ';
	cout << '\n';

	//7th way
	cout << "7. ";
	for (deque<string>::iterator dsit = begin(dst); dsit != end(dst); dsit++)
		cout << *dsit << ' ';
	cout << '\n';

	//8th way (part 1)
	cout << "8.1. ";
	for (auto i = 0; i < dst.size(); i++)
		cout << dst[i] << ' ';
	cout << '\n';

	//8th way (part 2)
	cout << "8.2. ";
	for (auto dsit = dst.begin(); dsit != dst.end(); dsit++)
		cout << *dsit << ' ';
	cout << '\n';

	//8th way (part 3)
	cout << "8.3. ";
	for (auto cdsit = dst.cbegin(); cdsit != dst.cend(); cdsit++)
		cout << *cdsit << ' ';
	cout << '\n';

	//8th way (part 4)
	cout << "8.4. ";
	for (auto rdsit = dst.rend() - 1; rdsit != dst.rbegin() - 1; rdsit--)
		cout << *rdsit << ' ';
	cout << '\n';

	//8th way (part 5 )
	cout << "8.5. ";
	for (auto crdsit = dst.crend() - 1; crdsit != dst.crbegin() - 1; crdsit--)
		cout << *crdsit << ' ';
	cout << '\n';

	//8th way (part 6)
	cout << "8.6. ";
	for (auto dsit = begin(dst); dsit != end(dst); dsit++)
		cout << *dsit << ' ';
	cout << '\n';

	//9th way
	cout << "9. ";
	for (string i : dst)
		cout << i << ' ';
	cout << '\n';

	return 0;
}
