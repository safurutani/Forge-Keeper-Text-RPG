#include "Weapon.h"

Weapon::Weapon() : Item(""), damage(0) {}
Weapon::Weapon(const string& name, int damage) 
	: Item(name), damage(damage) {}

int Weapon::getDamage() const {
	return damage;
}

