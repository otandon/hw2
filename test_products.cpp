#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;
template <typename T>
void printSet(const std::set<T>& s) {
  cout << "{";
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << "}" << endl;
}

int main() {
  cout << "BOOK" << endl;
  Book b("Jungle Book", 19.99, 20, "123-456789-0", "Om Tandon");
  cout << "[displayString()]\n" << b.displayString() << endl << endl;
  cout << "[keywords()]\n";
  printSet(b.keywords());
  cout << "[dump()]\n";
  b.dump(cout);
  cout << endl;

  cout << "CLOTHING" << endl;
  Clothing c("Tee Shirt", 39.99, 50, "Large", "Nike");
  cout << "[displayString()]\n" << c.displayString() << endl << endl;
  cout << "[keywords()]\n";
  printSet(c.keywords());
  cout << "[dump()]\n";
  c.dump(cout);
  cout << endl;

  cout << "MOVIE" << endl;
  Movie m("Creed", 10.99, 100, "Drama", "PG-13");
  cout << "[displayString()]\n" << m.displayString() << endl << endl;
  cout << "[keywords()]\n";
  printSet(m.keywords());
  cout << "[dump()]\n";
  m.dump(cout);
  cout << endl;

  return 0;
}