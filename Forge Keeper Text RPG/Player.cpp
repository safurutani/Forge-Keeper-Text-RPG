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
}

void Player::addItem(Item* item, int quantity) {
	for (auto& invItem : inventory) {
		
		if (invItem->getName() == item->getName()) {
			invItem->addQuantity(quantity);
			return;
		}
	}
	Item* tempItem = new Item(*item);
	tempItem->setQuantity(quantity);
	inventory.push_back(tempItem);
	// Print item added
	cout << "[Gained " << quantity << " " << item->getName() << "]" << endl << endl;
	return;
}

void Player::removeItem(Item* item, int quantity) {
	// Find the item in the inventory
	auto itemLocation = find_if(inventory.begin(), inventory.end(),
		[&](Item* invItem) { return invItem->isEqualToItem(*item); });

	if (itemLocation != inventory.end()) {
		// Item found, update quantity
		(*itemLocation)->subtractQuantity(quantity);
		if ((*itemLocation)->getQuantity() <= 0) {	
			inventory.erase(itemLocation);
		}
		// Print item removed
		cout << "[Removed " << quantity << " " << item->getName() << "]" << endl << endl;
	}
	else {
		inventory.push_back(item);
		// Item not found
		cout << item->getName() << " is not in your inventory. No item removed." << endl<< endl;
	}
}

vector<Item*> Player::getInventory() {
	return inventory;
}

void Player::displayInventory() const {
	int count = 1;
	cout << "Item                   Qty " << endl << "---------------------------" << endl;
	for (const auto& it : inventory) {
		cout << count << ") " << left << setw(20) << it->getName()
			<< setw(4) << it -> getQuantity() << endl;
		count++;
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
	if (health > 100) {
		health = 100;
	}
	cout << "You healed for " << heal << " hp. (" << health << "/100)" << endl;
}
void Player::decreaseHealth(int dmg) {
	health -= dmg;
	if (health < 0) {
		health = 0;
	}
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
	cout << endl;
}

void Player::decreaseGold(int j) {
	gold -= j;
	cout << "You paid " << j << " gold." << endl;
	displayGold();
}