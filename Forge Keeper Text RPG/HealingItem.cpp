#include "HealingItem.h"

HealingItem::HealingItem() : Item(""), heal(0) {}
HealingItem::HealingItem(const string& name, int heal) : Item(name), heal(heal) {}

int HealingItem::getHeal() const {
	return heal;
}
