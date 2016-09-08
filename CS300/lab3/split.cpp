#include <iostream>
#include "split.h"

std::vector<std::string> split(const std::string & s, const std::string& delim)
{
	std::vector<std::string> v;
	std::string::size_type pos1, pos2 = 0;
	std::string word;
	std::string::size_type n;
	pos1 = s.find_first_not_of(delim, pos2);

	while (pos1 != std::string::npos){
		if((pos2 = s.find_first_of(delim, pos1)) == std::string::npos){
			word = s.substr(pos1);
			pos1 = pos2;
		}
		else{
			word = s.substr(pos1, pos2 - pos1);
			pos1 = s.find_first_not_of(delim, pos2);
		}
		v.push_back(word);
	}
	return v;
}
