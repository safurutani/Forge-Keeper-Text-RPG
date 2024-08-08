#include "Item.h"
using namespace std;

Item::Item() : name(""), quantity(1) {}
Item::Item(const string& name) : name(name), quantity(1) {}

bool Item::isEqualToItem(Item& other) const{
	return name == other.getName();
}

string Item::getName() const {
	return name;
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

