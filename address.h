#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address {
	protected:
		std::string street;
		std::string city;
		std::string state;
		std::string zip;
	public:
		Address();
		void init(std::string street, std::string city, std::string state, std::string zip);
		void printAddress();
}; // end class Address 
#endif
