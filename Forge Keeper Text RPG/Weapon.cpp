#include "Weapon.h"

Weapon::Weapon() : Item(""), damage(0) {}
Weapon::Weapon(const string& name, int damage) 
	: Item(name), damage(damage) {}
Weapon::Weapon(const string& name, int damage, map<string, int> recipe)
	: Item(name), damage(damage), recipe(recipe) {}
int Weapon::getDamage() const {
	return damage;
}

void Weapon::getRecipe() const {
	for (auto& pair : recipe) {
		string item = pair.first;
		int quantity = pair.second;
		cout << item << ": " << quantity << endl;
	}
}