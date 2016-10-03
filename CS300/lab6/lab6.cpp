#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::sort;
using std::vector;
using std::string;

int main()
{
	vector<string> v = {"Six", "sick", "slick", "sycamore", "saplings"};
	vector<string> v2 = v, v3 = v;

	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater());
	sort(v.begin(), v.end(), less());

	return 0;
}
