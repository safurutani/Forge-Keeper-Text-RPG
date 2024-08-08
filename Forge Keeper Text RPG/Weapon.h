#pragma once

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

class Weapon : public Item
{
private:
	int damage;
	int durability;
	vector<string> aspects;
public:
	Weapon();
	Weapon(const string& name, int damage, int durability);
	Weapon(const string& name, int damage, int durability, vector<string> aspects); 

	int getDamage() const;
	int getDurability() const;
	void decreaseDurability(int num);
	void increaseDurability(int num);
};
