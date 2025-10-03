#include "clothing.h"
#include "util.h"
#include <sstream>
#include <cctype>

using namespace std;

std::set<string> Clothing::keywords() const {
  std::set<string> keys = parseStringToWords(name_);
  std::set<string> brands = parseStringToWords(brand_);
  return setUnion(keys, brands);
}

std::string Clothing::displayString() const {
  std::ostringstream oss;
  oss << name_ << "\n"
      << "Size: " << size_ << " Brand: " << brand_ << "\n"
      << price_ << " " << qty_ << " left.";
  return oss.str();
}

void Clothing::dump(std::ostream& os) const {
  os << "clothing\n" << name_ << "\n"
     << price_ << "\n" << qty_ << "\n"
     << size_ << "\n" << brand_ << "\n";
}