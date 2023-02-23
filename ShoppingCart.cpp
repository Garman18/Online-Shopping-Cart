#include <iostream>
#include <string>
#include <cmath>
#include<vector>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"


ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date){
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart::customerName(){
    return _customerName;
}

string ShoppingCart::date(){
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase aItem){
    _cartItems.push_back(aItem);
    
}

void ShoppingCart::removeItem(string rItem){
    bool ifFound = false;
    for(int i=0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == rItem){
            _cartItems.erase(_cartItems.begin() + i);
            ifFound = true;
        }
    }
    if(ifFound == false){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase modItem){
     bool ifFound = false;
    for(int i=0; i < _cartItems.size(); ++i){
        if(modItem.name() == _cartItems.at(i).name()){
            ifFound = true;
            if(_cartItems.at(i).description() != "none"){
                _cartItems.at(i).setDescription(modItem.description());
            }
            if(_cartItems.at(i).price() != 0){
                _cartItems.at(i).setPrice(modItem.price());
            }
            if(_cartItems.at(i).quantity() != 0){
                _cartItems.at(i).setQuantity(modItem.quantity());
            }
        }
    }
    if(!ifFound){
        cout << "Item not found in cart. Nothing modified." << endl;
    }       
}

int ShoppingCart::numItemsInCart(){
    int total = 0;
    for(int i = 0; i < _cartItems.size(); ++i){
        total = total + _cartItems.at(i).quantity();
    }
    return total;
}

double ShoppingCart::costOfCart(){
    int total = 0;
    int itemPrice;
    int itemQuantity;
    
    for(int i=0; i < _cartItems.size(); ++i){
        itemPrice = _cartItems.at(i).price();
        itemQuantity = _cartItems.at(i).quantity();
        total += itemPrice * itemQuantity;
    }
    return total;
}

void ShoppingCart::printTotal(){
    int total = 0;
    int itemPrice;
    int itemQuantity;
    int totalPrice;
    string itemName;
    
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    
    if(_cartItems.size() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
    }
    else{
        for(int i=0; i < _cartItems.size(); ++i){
            itemPrice = _cartItems.at(i).price();
            itemQuantity = _cartItems.at(i).quantity();
            itemName = _cartItems.at(i).name();
            totalPrice = itemPrice * itemQuantity;
            total += totalPrice;
            
            cout << itemName <<" " << itemQuantity << " @ " << "$" << itemPrice << " = " << "$" << totalPrice << endl;
        }
        cout << endl;
    }
    cout << "Total: $" << total << endl;
    for(int i=0; i < _cartItems.size(); ++i){
    itemPrice = _cartItems.at(i).price();
    itemQuantity = _cartItems.at(i).quantity();
    total += itemPrice * itemQuantity;
}
}

void ShoppingCart::printDescriptions(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    
    for(int i=0; i < _cartItems.size(); ++i){
        cout << _cartItems.at(i).name() << ": " << _cartItems.at(i).description() << endl;
    }
    
    
}
