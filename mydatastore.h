#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
#include <string>
#include <map>
#include <set>
#include <vector>

class MyDataStore : public DataStore {
  public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product *> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;
    void addToCart(const std::string& username, Product* p);
    void viewCart(const std::string& username, std::ostream& os) const;
    void buyCart(const std::string& username);
    bool userExists(const std::string& username);
  private:
    std::vector<Product *> products_;
    std::map<std::string, User*> usersByName_;
    std::map<std::string, std::set<Product*> > index_;
    std::map<std::string, std::vector<Product *> > carts_;
};

#endif
