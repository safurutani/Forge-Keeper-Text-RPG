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
	inventory.emplace_back(new Weapon("Wood Hammer", 1));
	inventory.emplace_back(new Weapon("Bronze Sword", 3));
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
	// Print item added
	cout << "[Gained " << quantity << " " << item->getName() << "]" << endl << endl;
}

void Player::removeItem(Item* item, int quantity) {
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
		// Print item removed
		cout << "[Removed " << quantity << " " << item->getName() << "]" << endl << endl;
	}
	else {
		// Item not found
		cout << "You don't have a " << item->getName() << ". No item removed." << endl<< endl;
	}
}

vector<Item*> Player::getInventory() {
	return inventory;
}

void Player::displayInventory() const {
	cout << "Item                Qty " << endl << "------------------------" << endl;
	for (const auto& it : inventory) {
		cout << left <<  setw(20) << it -> getName() 
			<< setw(4) << it -> getQuantity() << endl;
	}
	cout << endl;
}

string Player::getName() const {
	return name;
}
void Player::setName(string newName) {
	name = newName;
}
int Player::getHealth() const{
	return health;
}
void Player::displayHealth() const {
	cout << "Health: " << health << "/100";
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
void Player::displayGold() const {
	cout << "Gold: " << gold << endl;
}

void Player::increaseGold(int i) {
	gold += i;
	cout << "You gained " << i << " gold!" << endl;
	displayGold();
}

void Player::decreaseGold(int j) {
	gold -= j;
	cout << "You paid " << j << " gold." << endl;
	displayGold();
}