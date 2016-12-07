#ifndef __F_H__
#define __F_H__

/* Lab13:
function object class - take string, return sum of absolute value of character codes
unordered <string, int> map with the class as a third parameter
the constructor needs 2 parameters, the first a suggested # of buckets (use 20)
the second a function object object of the function object class
do it all on an unordered_multimap as well


struct KeyHash{
 std::size_t operator()(const Key& k) const
 {
     return std::hash<std::string>()(k.first) ^
            (std::hash<std::string>()(k.second) << 1);
 }
};

struct KeyEqual{
 bool operator()(const Key& lhs, const Key& rhs) const
 {
    return lhs.first == rhs.first && lhs.second == rhs.second;
 }
};

	size_t r = 0;
	for(size_t i = 0; i < item.length(); i++)
		r += (size_t)item[i]; //cast to size_t */

#include <string> //string
#include <functional> //hash<string>
using std::string;

template <class Key>
class functobj{
public:
	functobj(){}
	std::size_t operator()(const Key& item) const{
		return std::hash<string>(item);
	} //end operator definition
};

#endif
