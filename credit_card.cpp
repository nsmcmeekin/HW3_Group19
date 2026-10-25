#include "credit_card.h"
#include <iostream>
#include <string>

using namespace std;

bool credit_card::make_purchase(double purchase_amount) {
    if (current_balance + purchase_amount <= limit){
        current_balance += purchase_amount;
        return true;
    } else {
        cout << "Purchase declined: exceeds credit limit." << endl;
        return false;
    }
    bool credit_card::make_payment(double payment_amount) {
        if (payment_amount <= 0) {
            cout << "Payment amount must be positive." << endl;
            return false;
        }
        current_balance -= payment_amount;

        if (current_balance < 0) {
            current_balance = 0;
        }

        return true;
}

string credit_card::credit_card_info(){
    return "Card Number: " + to_string(cc_number) +
           "\nLimit: $" + to_string(limit) +
           "\nCurrent Balance: $" + to_string(current_balance);
}