#include "mydatastore.h"
#include "util.h"
#include <iostream>

using namespace std;
MyDataStore::MyDataStore() {}
MyDataStore::~MyDataStore() {
  for (size_t i = 0; i < products_.size(); i++) {
    delete products_[i];
  }
  for (std::map<string, User*>::iterator it = usersByName_.begin(); it != usersByName_.end(); it++) {
    delete it -> second;
  }
}

void MyDataStore::addUser(User* u) {
  if (!u) return;
  string uname = convToLower(u -> getName());
  usersByName_[uname] = u;
}

void MyDataStore::addProduct(Product* p) {
  if (!p) return;
  products_.push_back(p);
  std::set<string> keys = p -> keywords();
  for (std::set<string>::iterator it = keys.begin(); it != keys.end(); it++) {
    index_[convToLower(*it)].insert(p);
  }
}

std::vector<Product*> MyDataStore::search(std::vector<string>& terms, int type) {
  if (terms.empty()) return std::vector<Product*>();
  std::vector<string> temp;
  for (size_t i = 0; i < terms.size(); i++) temp.push_back(convToLower(terms[i]));
  std::set<Product*> result;
  if (type == 0) {
    std::map<string, std::set<Product*> >::const_iterator it = index_.find(temp[0]);
    if (it == index_.end()) {
      return std::vector<Product*>();
    }
    result = it -> second;
    for (size_t i = 1; i < temp.size(); i++) {
      std::map<string, std::set<Product*> >::const_iterator ait = index_.find(temp[i]);
      if (ait == index_.end()) return std::vector<Product*>();
      result = setIntersection(result, ait -> second);
    }
  } else {
    for (size_t i = 0; i < temp.size(); i++) {
      std::map<string, std::set<Product*> >::const_iterator it = index_.find(temp[i]);
      if (it != index_.end()) result = setUnion(result, it -> second);
    }
  }
  std::vector<Product*> v_res;
  for (size_t i = 0; i < products_.size(); i++) {
    if (result.find(products_[i]) != result.end()) v_res.push_back(products_[i]);
  }
  return v_res;
}

void MyDataStore::addToCart(const std::string& username, Product* p) {
  if (!p) return;
  string uname = convToLower(username);
  if (usersByName_.find(uname) == usersByName_.end()) {
    cout << "Invalid username";
    return;
  }
  carts_[uname].push_back(p);
}

void MyDataStore::viewCart(const std::string& username, std::ostream& os) const {
  string uname = convToLower(username);
  std::map<string, std::vector<Product*>>::const_iterator it = carts_.find(uname);
  if (it == carts_.end()) return;
  const std::vector<Product*>& products = it -> second;
  for (size_t i =0; i < products.size(); i++) {
    os << "Item " << (i + 1) << "\n";
    os << products[i] -> displayString() << "\n\n";
  }
}

void MyDataStore::buyCart(const std::string& username) {
  string uname = convToLower(username);
  std::map<string, User*>::iterator uit = usersByName_.find(uname);
  if (uit == usersByName_.end()) {
    cout << "Invalid username" << endl;
    return;
  }
  User* user = uit -> second;
  std::vector<Product*>& items = carts_[uname];
  std::vector<Product*> left;
  left.reserve(items.size());
  for (size_t i = 0; i < items.size(); i++) {
    Product* p = items[i];
    double price = p -> getPrice();

    if (p -> getQty() > 0 && user -> getBalance() >= price) {
      p -> subtractQty(1);
      user -> deductAmount(price);
    } else {
      left.push_back(p);
    }
  }
  items.swap(left);
}

void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>\n";
  for (size_t i = 0; i < products_.size(); i++) {
    products_[i] -> dump(ofile);
  }
  ofile << "</products>\n";
  ofile << "<users>\n";
  for (std::map<string, User*>::const_iterator it = usersByName_.begin(); it != usersByName_.end(); it++) {
    it -> second -> dump(ofile);
  }
  ofile << "</users>\n";
}

bool MyDataStore::userExists(const std::string& username) {
  string uname = convToLower(username);
  return usersByName_.find(uname) != usersByName_.end();
}


