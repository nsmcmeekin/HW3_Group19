#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

int main()
{

	Store store1;
	string cardNames[100];
	credit_card cards[100];

	ifstream customerFile("people.txt");
	ifstream productFile("products.txt");
	ifstream creditFile("credit_card.txt");

	if (!customerFile.is_open() || !productFile.is_open() || !creditFile.is_open()) {
		cout << "Could not open files" << endl;
		return 1;
	}
	//import from text files
	int numCards;
	creditFile >> numCards;
	creditFile.ignore();

	for (int i = 0; i < numCards; i++) {
		getline(creditFile, cardNames[i]);

		creditFile >> cards[i].cc_number;
		creditFile >> cards[i].limit;
		creditFile >> cards[i].current_balance;
		creditFile.ignore();
	}

	creditFile.close();

	int numProducts;

	productFile >> numProducts;
	productFile.ignore();

	for (int i = 0; i < numProducts; i++) {
		product item;
		getline(productFile, item.name);
		getline(productFile, item.description);
		productFile >> item.price;
		productFile.ignore();

		store1.add_product(item);
	}

	productFile.close();
//read customers in
	int numCustomers;
	customerFile >> numCustomers;
	customerFile.ignore();

	for (int i = 0; i < numCustomers; i++) {
		string name, phone, street, street2, city, state, zip;

		getline(customerFile, name);
		getline(customerFile, phone);
		getline(customerFile, street);
		getline(customerFile, street2);
		getline(customerFile, city);
		getline(customerFile, state);
		getline(customerFile, zip);

		address customerAddress(street, street2, city, state, zip);

		for (int j = 0; j < numCards; j++) {
			if (cardNames[j] == name) {
				Person customer(name, phone, customerAddress, cards[j]);
				store1.add_customer(customer);
				break;
			}
		}
	}
	customerFile.close();
	//add to store and other variables

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	int targetTrans = 11 + (rand() % 15);

	for (int i = 1; i < targetTrans; i++) {
		int customerIndex = rand() % store1.num_customers();
		int productIndex = rand() % store1.num_products();
		int quantity = 1 + (rand() % 10);

		Person customer = store1.get_customer(customerIndex);
		product item = store1.get_product(productIndex);

		bool success = store1.make_purchase(customer, item, quantity);

		if (success) {
			cout << "Transaction Successful!" << endl;
			cout << "Details: " << endl;
			transaction transRecord = store1.get_transaction(store1.num_transactions() - 1);
			cout << transRecord.transaction_info() << endl;

		}
		else {
			cout << "Transaction Failed!" << endl;
			cout << "Details: \nPerson: " << endl;
			cout << customer.person_info() << endl;
			cout << "Product: \n" << item.product_info() << endl;
			cout << "Quantity: " << quantity << endl;

		}
	}


	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	return 0;
}
