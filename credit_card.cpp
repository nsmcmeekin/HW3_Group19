#include "credit_card.h"
#include <iostream>
#include <string>
#include <format>

using namespace std;

bool credit_card::make_purchase(double purchase_amount) {
    if (current_balance + purchase_amount <= limit){
        current_balance += purchase_amount;
        return true;
    } else {
        cout << "Purchase declined: exceeds credit limit." << endl;
        return false;
    }
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
    return std::format(
        "Credit card number: {}\n"
        "Credit Card Limit: ${:.2f}\n"
        "Current Balance: ${:.2f}",
        cc_number,
        limit,
        current_balance
    );
}