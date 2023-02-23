#include "ItemToPurchase.h"
#include <vector>
#include <iostream>
#include <string>
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

using namespace std;

class ShoppingCart{
    
 public:
    ShoppingCart();
    ShoppingCart(string,string);
    
    string customerName();
    string date();
    void addItem(ItemToPurchase);
    void removeItem(string);
    void modifyItem(ItemToPurchase);
    int numItemsInCart();
    double costOfCart();
    void printTotal();
    void printDescriptions();
    
 private:
    string _customerName;
    string _currentDate;
    vector <ItemToPurchase> _cartItems;
};
#endif
