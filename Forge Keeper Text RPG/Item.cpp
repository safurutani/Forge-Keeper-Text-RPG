#include "Item.h"

Item::Item() : name(""), quantity(1), description("") {}
Item::Item(const string& name) : name(name), quantity(1), description("") {}
Item::Item(const string& name, int qty) : name(name), quantity(qty) {}
Item::Item(const string& name, int qty, vector<pair<string, int>> recipe) : name(name), quantity(qty), recipe(recipe) {}
Item::Item(const string& name, const string& description) 
	: name(name), quantity(1), description(description) {}
Item::Item(const string& name, const string& description, int qty)
	: name(name), quantity(qty), description(description){}


bool Item::isEqualToItem(Item& other) const{
	return name == other.getName();
}

string Item::getName() const {
	return name;
}

string Item::getDescription() const {
	return description;
}

void Item::setDescription(string newDescription) {
	description = newDescription;
}

int Item::getQuantity() const {
	return quantity;
}

void Item::addQuantity(int a) {
	quantity += a;
}
void Item::setQuantity(int newQuantity) {
	quantity = newQuantity;
}
void Item::subtractQuantity(int b) {
	if (quantity - b < 0) {
		quantity = 0;
	}
	else {
		quantity -= b;
	}
}

