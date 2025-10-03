#include "book.h"
#include "util.h"
#include <sstream>
#include <cctype>

using namespace std;

std::set<string> Book::keywords() const {
  std::set<string> keys = parseStringToWords(name_);
  std::set<string> authors = parseStringToWords(author_);
  keys = setUnion(keys, authors);
  keys.insert(isbn_);
  return keys;
}

std::string Book::displayString() const {
  std::ostringstream oss;
  oss << name_ << "\n"
      << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
      << price_ << " " << qty_ << " left.";
  return oss.str();
}

void Book::dump(std::ostream& os) const {
  os << "book\n" << name_ << "\n"
     << price_ << "\n" << qty_ << "\n"
     << isbn_ << "\n" << author_ << "\n";
}