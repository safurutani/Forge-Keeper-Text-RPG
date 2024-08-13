#include "Weapon.h"

using namespace std;

Weapon::Weapon() : Item(""), damage(0), durability(0), aspects({}) {}
Weapon::Weapon(const string& name, int damage) 
	: Item(name), damage(damage), aspects({}) {}
Weapon::Weapon(const string& name, int damage, vector<string> aspects) 
	: Item(name), damage(damage), aspects(aspects) {}

int Weapon::getDamage() const {
	return damage;
}

