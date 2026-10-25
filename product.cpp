//code for product struct here
#include <iostream>
#include "product.h"
#include <format>

std::string product::product_info() {
    return std::format("Product Name: {}\n{}\nPrice: ${:.2f}", name, description, price);
}
