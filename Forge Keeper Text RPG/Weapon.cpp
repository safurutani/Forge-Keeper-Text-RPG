#include "Weapon.h"

using namespace std;

Weapon::Weapon() : Item(""), damage(0), durability(0), aspects({}) {}
Weapon::Weapon(const string& name, int damage, int durability) 
	: Item(name), damage(damage), durability(durability), aspects({}) {}
Weapon::Weapon(const string& name, int damage, int durability, vector<string> aspects) 
	: Item(name), damage(damage), durability(durability), aspects(aspects) {}

int Weapon::getDamage() const {
	return damage;
}

int Weapon::getDurability() const {
	return durability;
}

void Weapon::decreaseDurability(int x) {
	durability -= x;
}

void Weapon::increaseDurability(int y) {
	durability += y;
}
