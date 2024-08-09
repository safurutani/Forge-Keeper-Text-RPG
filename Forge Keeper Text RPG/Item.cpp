#include "Item.h"
using namespace std;

Item::Item() : name(""), quantity(0), description("") {}
Item::Item(const string& name) : name(name), quantity(0), description("") {}
Item::Item(const string& name, const string& description) 
	: name(name), quantity(0), description(description) {}

bool Item::isEqualToItem(Item& other) const{
	return name == other.getName();
}

string Item::getName() const {
	return name;
}

string Item::getDescription() const {
	return description;
}

int Item::getQuantity() const {
	return quantity;
}

void Item::addQuantity(int a) {
	quantity += a;
}

void Item::subtractQuantity(int b) {
	quantity -= b;
}

