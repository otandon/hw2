#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include "util.h"
#include <set>
#include <string>

class Clothing : public Product {
  public:
    Clothing(std::string name, double price, int qty, 
    const std::string size, const std::string brand) :
    Product("clothing", name, price, qty), size_(size), brand_(brand) {}

    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const;
  
  private:
    std::string size_;
    std::string brand_;
};

#endif