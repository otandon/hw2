#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  std::set<string> out;

  //lowercase
  for (size_t i = 0; i < rawWords.size(); i++) {
    rawWords[i] = tolower(static_cast<unsigned char>(rawWords[i]));
  }

  // split on non-alnum, add to set iff >= 2
  string curr;
  for (size_t i = 0; i < rawWords.size(); i++) {
    char c = rawWords[i];
    if (isalnum(static_cast<unsigned char>(c))) {
      curr.push_back(c);
    } else {
      if (curr.size() >= 2) out.insert(curr);
      curr.clear();
    }
  }

  if (curr.size() >= 2) out.insert(curr);

  return out;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
