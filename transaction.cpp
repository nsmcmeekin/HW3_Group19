//code for transaction struct here
#include "transaction.h"
#include <iostream>
#include <format>

std::string transaction::transaction_info() {
    return std::format("Transaction Number: {}\nCustomer:\nName: {}\nPhone: {}\nAddress: \n{}\nCredit Card: \n{}\nProduct: \n{}\nQuantity: {}\n", transaction_number, customer.name(), customer.phone(), customer.person_address().address_info(), customer.person_credit_card().credit_card_info(), purchased_item.product_info(), quantity);
}
