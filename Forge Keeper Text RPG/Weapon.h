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
	vector<pair<string, int>> recipe;
public:
	Weapon();
	Weapon(const string& name, int damage);
	Weapon(const string& name, int damage, vector<pair<string, int>> recipe);

	int getDamage() const;
	void getRecipe() const;
	static void forge();

	static Weapon woodSwordW;
    static Weapon ironSwordW;
    static Weapon steelSwordW;
    static Weapon souluriteSwordW;
    static Weapon ironCutlassW;
    static Weapon steelCutlassW;
    static Weapon ironKatanaW;
    static Weapon steelKatanaW;
    static Weapon woodSpearW;
    static Weapon ironSpearW;
    static Weapon steelSpearW;
    static Weapon souluriteSpearW;
    static Weapon woodBowW;
    static Weapon steelBowW;
    static Weapon woodArrowW;
    static Weapon ironArrowW;
    static Weapon steelArrowW;
    static Weapon souluriteArrowW;
    static Weapon ironMaceW;
    static Weapon steelMaceW;
    static Weapon souluriteMaceW;
    static Weapon woodBoomerangW;
    static Weapon ironBoomerangW;
    static Weapon steelBoomerangW;
    static Weapon souluriteBoomerangW;
    static Weapon woodStaffW;
    static Weapon ironStaffW;
    static Weapon steelStaffW;
    static Weapon souluriteStaffW;
    static Weapon ironShurikenW;
    static Weapon steelShurikenW;
    static Weapon souluriteShurikenW;
    static Weapon woodAxeW;
    static Weapon ironAxeW;
    static Weapon steelAxeW;
    static Weapon souluriteAxeW;
};
