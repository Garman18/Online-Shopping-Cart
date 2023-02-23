#include <iostream>
#include <string>
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

using namespace std;

class ItemToPurchase{
    
 public:
    ItemToPurchase();
    ItemToPurchase(string, string, int, int); //Parameterized constructor 
    void setName(string itemName); //mutators
    void setPrice(int itemPrice);
    void setQuantity(int itemQuantity);
    
    string name(); //accessors
    int price();
    int quantity();
    string description();
    
    void setDescription(string Description); // mutators
    void printItemCost(string itemCost);
    void printItemDescription(string itemDes);
    
 private:
    string _name;
    int _price;
    int _quantity;
    string _description; 
    
};
#endif
