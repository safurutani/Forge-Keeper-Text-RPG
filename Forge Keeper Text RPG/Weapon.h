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
public:
	Weapon();
	Weapon(const string& name, int damage);

	int getDamage() const;
};
