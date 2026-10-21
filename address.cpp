#include <iostream>
#include "address.h"
using namespace std;

Address::Address(){
	street = "";
	city = "";
	state = "";
	zip = "";
} // end Address

void Address::init(string st, string ci, string sta, string z){
	street = st;
	city = ci;
	state = sta;
	zip = z;
} // end init

void Address::printAddress(){
	cout << street << endl;
	cout << city << " " << state << ", " << zip << endl;
} // end printAddress
