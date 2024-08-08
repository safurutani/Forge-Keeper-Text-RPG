#include "Player.h"

using namespace std;

Player* Player::instance = nullptr;

Player& Player::getInstance(const string& name) {
	if (instance == nullptr) {
		instance = new Player(name);
	}
	return *instance;
}
Player::Player(const string& name) : name(name), health(100), gold(0) {
	inventory.emplace_back(new Weapon("Wood Sword", 3, 10));
	inventory.emplace_back(new Item("Wood Axe"));
	inventory.emplace_back(new Item("Wood Pick"));
	inventory.emplace_back(new Item("Wood Hammer"));
}

void Player::addItem(Item* item, int quantity) {
	// Find the item in the inventory
	auto itemLocation = find_if(inventory.begin(), inventory.end(),
		[&](Item* invItem) { return invItem->isEqualToItem(*item); });

	if (itemLocation != inventory.end()) {
		// Item found, update quantity
		(*itemLocation)->addQuantity(quantity);
	}
	else {
		// Item not found, add new item to inventory
		inventory.push_back(new Item(*item));
		inventory.back()->addQuantity(quantity);
	}
}

void Player::subtractItem(Item* item, int quantity) {
	// Find the item in the inventory
	auto itemLocation = find_if(inventory.begin(), inventory.end(),
		[&](Item* invItem) { return invItem->isEqualToItem(*item); });

	if (itemLocation != inventory.end()) {
		// Item found, update quantity
		(*itemLocation)->subtractQuantity(quantity);
		if ((*itemLocation)->getQuantity() <= 0) {
			delete* itemLocation;  // Remove item from inventory if quantity is 0 or less
			inventory.erase(itemLocation);
		}
	}
	else {
		// Item not found
		cout << "You don't have a " << item->getName() << ". No item lost." << endl;
	}
}

void Player::displayInventory() const {
	for (const auto& it : inventory) {
		cout << setw(12) << it -> getName() 
			<< setw(4) << it -> getQuantity() << endl;
	}
}

string Player::getName() const {
	return name;
}

int Player::getHealth() const {
	return health;
}

void Player::increaseHealth(int heal) {
	health += heal;
	cout << "You healed for " << heal << " hp. (" << health << "/100)" << endl;
}
void Player::decreaseHealth(int dmg) {
	health -= dmg;
	cout << "You lost " << dmg << " hp. (" << health << "/100)" << endl;
}

int Player::getGold() const {
	return gold;
}

void Player::increaseGold(int i) {
	gold += i;
	cout << "You gained " << i << " gold! (" << gold << "g)" << endl;
}

void Player::decreaseGold(int j) {
	gold -= j;
	cout << "You paid " << j << " gold. (" << gold << "g)" << endl;
}