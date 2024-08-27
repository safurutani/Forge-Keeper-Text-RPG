#pragma once

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include <map>

class Weapon : public Item
{
private:
	int damage;
	map<string, int> recipe;
public:
	Weapon();
	Weapon(const string& name, int damage);
	Weapon(const string& name, int damage, map<string, int> recipe);

	int getDamage() const;
	void getRecipe() const;
};
