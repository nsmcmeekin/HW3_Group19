//code for store class here
#include "store.h"
#include <format>
#include <string>
#include <iostream>

Store::Store() {
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int customer_number) {
    num_customers_ = customer_number;
}

int Store::num_customers() {
    return num_customers_;
}

void Store::num_products(int product_count) {
    num_products_ = product_count;
}

int Store::num_products() {
    return num_products_;
}

void Store::num_transactions(int transaction_number) {
    num_transactions_ = transaction_number;
}

int Store::num_transactions() {
    return num_transactions_;
}

bool Store::add_customer(Person customer) {
    if (num_customers_ >= 100) return false;

    customers_[num_customers_] = customer;
    num_customers_++;
    return true;
}

bool Store::update_customer(int index, Person customer) {
    if (index >= num_customers_) return false;
    customers_[index] = customer;
    return true;
}

Person Store::get_customer(int index) {
    return customers_[index];
}

bool Store::add_product(product item) {
    if (num_products_ >= 100) return false;
    products_[num_products_] = item;
    num_products_++;
    return true;
}

product Store::get_product(int index) {
    return products_[index];
}

bool Store::add_transaction(transaction transaction) {
    if (num_transactions_ >= 100) return false;
    transactions_[num_transactions_] = transaction;
    num_transactions_++;
    return true;
}

transaction Store::get_transaction(int index) {
    return transactions_[index];
}

bool Store::make_purchase(Person customer, product product, int quantity) {
    if (quantity <= 0 || num_transactions_ >= 100) return false;

    int customberIndex = find_customer(customer);

    if (customberIndex == -1) return false;

    double purchaseAmount = product.price * quantity;

    credit_card card = customers_[customberIndex].person_credit_card();
    //checks if theres credit
    if (!card.make_purchase(purchaseAmount)) return false;

    customers_[customberIndex].person_credit_card(card);
    transaction newTransaction;
    newTransaction.transaction_number = num_transactions_ + 1;
    newTransaction.customer = customers_[customberIndex];
    newTransaction.purchased_item = product;
    newTransaction.quantity = quantity;

    return add_transaction(newTransaction);

}

int Store::find_customer(Person customer) {
    for (int i = 0; i < num_customers_; i++) {
        if (customers_[i].name() == customer.name() && customers_[i].phone() == customer.phone()) return i;
    }

    return -1;
}

string Store::product_info() {
    string info = "";
    for (int i = 0; i < num_products_; i++) {
        info += products_[i].product_info();
        info += "\n";
    }
    return info;
}

string Store::transaction_info() {
    string info = "";
    for (int i = 0; i < num_transactions_; i++) {
        info += transactions_[i].transaction_info();
        info += "\n";
    }

    return info;
}

string Store::customer_info() {
    string info = "";
    for (int i = 0; i < num_customers_; i++) {
        info += customers_[i].person_info();
        info += "\n";
    }

    return info;
}

string Store::store_info() {
    string info = "Customers: \n";
    for (int i = 0; i < num_customers_; i++) {
        info += customers_[i].person_info();
        info += "\n";
    }

    info += "Products: \n";
    for (int i = 0; i < num_products_; i++) {
        info += products_[i].product_info();
        info += "\n";
    }

    info += "\nTransactions: \n";
    for (int i = 0; i < num_transactions_; i++) {
        info += transactions_[i].transaction_info();
        info += "\n";
    }
    return info;
}

string Store::purchase_history(Person person) {
    int personIndex = find_customer(person);
    if (personIndex == -1) return "Person not found";
    string info = "";
    for (int i = 0; i < num_transactions_; i++) {
        if (transactions_[i].customer.name() == person.name() && transactions_[i].customer.phone() == person.phone()) {
            info += transactions_[i].transaction_info();
        }
    }

    return info;

}
