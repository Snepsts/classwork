#include <iostream>
#include "split.h"

std::vector<std::string> csplit(const std::string& s, const std::string& accept)
{
	std::vector<std::string> v;
	std::string::size_type pos1, pos2 = 0;
	std::string word;
	std::string::size_type n;
	pos1 = s.find_first_of(accept, pos2);

	while (pos1 != std::string::npos){
		if((pos2 = s.find_first_not_of(accept, pos1)) == std::string::npos){
			word = s.substr(pos1);
			pos1 = pos2;
		}
		else{
			word = s.substr(pos1, pos2 - pos1);
			pos1 = s.find_first_of(accept, pos2);
		}
		v.push_back(word);
	}
	return v;
}
