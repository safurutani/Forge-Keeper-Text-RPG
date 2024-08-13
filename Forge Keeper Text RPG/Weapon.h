#pragma once

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

class Weapon : public Item
{
private:
	int damage;
	int durability;
	vector<string> aspects;
public:
	Weapon();
	Weapon(const string& name, int damage);
	Weapon(const string& name, int damage, vector<string> aspects); 

	int getDamage() const;
};
