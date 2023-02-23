#include <iostream>
#include <string>
#include <cmath>
#include "ItemToPurchase.h"


ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
    _name = name;
    _description = description;
    _price = price;
    _quantity = quantity;
}

void ItemToPurchase::setName(string name){
    _name = name;
}

void ItemToPurchase::setPrice(int price){
    _price = price;
}

void ItemToPurchase::setQuantity(int quantity){
    _quantity = quantity;
}

string ItemToPurchase::name(){
    return _name;
}

int ItemToPurchase::price(){
    return _price;
}

int ItemToPurchase::quantity(){
    return _quantity;
}

void ItemToPurchase::setDescription(string str){
    _description = str;
}

void ItemToPurchase::printItemCost(string itemCost){
    cout << _name << " " << _quantity << " " << "@ " << "$" << _price << " " << "= " << "$" << _quantity * _price << endl;
}

void ItemToPurchase::printItemDescription(string itemDes){
    cout << _name <<": " << _description << "." << endl;
}

string ItemToPurchase::description(){
    return _description;
}
