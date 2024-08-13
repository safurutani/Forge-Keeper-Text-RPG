#pragma once

#include "Item.h"
class HealingItem : public Item
{
private:
	int heal;
public:
	HealingItem();
	HealingItem(const string& name, int heal);
	int getHeal() const;
};

