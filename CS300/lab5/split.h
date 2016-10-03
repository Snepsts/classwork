#ifndef __SPLIT_H
#define __SPLIT_H
#include <vector>
#include <string>

const std::string delimiters = " \n\t~!@#%^&*()_+={}|\\{};:,.<>,?\""
                               "0123456789";

const std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz"; //I noticed the missing j. It's fixed now, though.
// split returns a vector of the the "words" in s
// words are separated by delimiters
std::vector<std::string> split(const std::string & s, const std::string& delim = delimiters);

// cplit returns a vector of the the "words" in s
// words are maximal sequences of acceptable characters
std::vector<std::string> csplit(const std::string & s, const std::string& accept = letters);


#endif
