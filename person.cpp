#include "person.h"

using std::string;

// Constructor
Person::Person(string name,
               string phone,
               address person_address,
               credit_card person_credit_card)
{
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;
}

// Default Constructor
Person::Person()
{
    name_ = "";
    phone_ = "";
}

// Setter for name
void Person::name(string name)
{
    name_ = name;
}

// Getter for name
string Person::name()
{
    return name_;
}

// Setter for phone
void Person::phone(string phone)
{
    phone_ = phone;
}

// Getter for phone
string Person::phone()
{
    return phone_;
}

// Setter for address
void Person::person_address(address person_address)
{
    person_address_ = person_address;
}

// Getter for address
address Person::person_address()
{
    return person_address_;
}

// Setter for credit card
void Person::person_credit_card(credit_card person_credit_card)
{
    person_credit_card_ = person_credit_card;
}

// Getter for credit card
credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

// Person information
string Person::person_info()
{
    return "Name: " + name_ +
           "\nPhone: " + phone_ +
           "\n\nAddress:\n" +
           person_address_.address_info() +
           "\n\nCredit Card:\n" +
           person_credit_card_.credit_card_info();
}