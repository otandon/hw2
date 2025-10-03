#include "util.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;
template <typename T>
void printSet(const std::set<T>& s) {
  cout << "{";
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it;
  }
  cout << "}" << endl;
}

int main() {
  cout << "Test parseStringToWords" << endl;
  set<string> words = parseStringToWords("Men's");
  printSet(words);

  words = parseStringToWords("J.Crew");
  printSet(words);

  words = parseStringToWords("I'll");
  printSet(words);

  cout << "Test setUnion / setIntersection" << endl;
  set<int> a; a.insert(1); a.insert(2); a.insert(3); a.insert(4);
  set<int> b; b.insert(3); b.insert(4); b.insert(5); b.insert(6);

  cout << "A = "; printSet(a);
  cout << "B = "; printSet(b);

  set<int> u = setUnion(a, b);
  cout << "Union = "; printSet(u);

  set<int> is = setIntersection(a, b);
  cout << "Intersection = "; printSet(is);

  return 0;
}