#include "movie.h"
#include "util.h"
#include <sstream>

using namespace std;

std::set<string> Movie::keywords() const {
  std::set<string> keys = parseStringToWords(name_);
  keys.insert(convToLower(genre_));
  return keys;
}

std::string Movie::displayString() const {
  std::ostringstream oss;
  oss << name_ << "\n"
      << "Genre: " << genre_ << " Rating: " << rating_ << "\n"
      << price_ << " " << qty_ << " left.";
  return oss.str();
}

void Movie::dump(std::ostream& os) const {
  os << "movie\n" << name_ << "\n"
     << price_ << "\n" << qty_ << "\n"
     << genre_ << "\n" << rating_ << "\n";
}