#include  "address.h"
#include  <iostream>
#include  <string>

using namespace std;

string address::address_info()
{
    string info = address_line1 + "\n";

    if (!address_line2.empty()){
        info += address_line2 + "\n";
    }

    info += city + ", " + state + " " + zip;

    return info;
}