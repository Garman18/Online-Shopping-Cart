#include<iostream>
#include<string>
#include<cmath>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart& menu);
   
int main(){
    string customerName;
    string date;
    
    cout << "Enter customer's name: ";
    getline(cin, customerName);
    cout << endl;
    cout << "Enter today's date: " << endl;
    cout << endl;
    getline(cin, date);
    ShoppingCart menu(customerName, date);
    
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;
    cout << endl;
    
    printMenu(menu);
    
    return 0;
}

void printMenu(ShoppingCart& menu){
    char userInput = ' ';
    int itemPrice;
    int itemQuantity;
    string itemName;
    string itemDescription;
    
    while(userInput != 'q'){
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option: ";
        cin >> userInput;
        cout << endl;
        
        if(userInput == 'a'){
            cin.ignore();
            cout << endl;
            cout << "ADD ITEM TO CART" <<  endl;
            cout << "Enter the item name: ";
            getline(cin, itemName);
            cout << endl;
            cout << "Enter the item description: ";
            getline(cin,itemDescription);
            cout << endl;
            cout << "Enter the item price: ";
            cin >> itemPrice;
            cout << endl;
            cout << "Enter the item quantity: ";
            cin >> itemQuantity;
            cout << endl;
            ItemToPurchase item(itemName,itemDescription,itemPrice,itemQuantity);
            menu.addItem(item);
            cout << endl;
        }
        else if (userInput == 'd'){
            cin.ignore();
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: ";
            getline(cin, itemName);
            cout << endl;
            menu.removeItem(itemName);
            cout << endl;
        }

        else if (userInput == 'c'){
            cin.ignore();
            cout << endl;
            ItemToPurchase item;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: ";
            getline(cin,itemName);
            cout << endl;
            cout << "Enter the new quantity: ";
            cin >> itemQuantity;
            cout << endl;
            item.setName(itemName);
            item.setQuantity(itemQuantity);
            menu.modifyItem(item);
            cout << endl;
        }
        else if (userInput == 'i'){
            cin.ignore();
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            menu.printDescriptions();
            cout << endl;
        }
        else if (userInput == 'o'){
            cin.ignore();
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            menu.printTotal();
            cout << endl;
    
        }
       
    }
}
