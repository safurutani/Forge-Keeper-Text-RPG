#include "Player.h"

using namespace std;

Player* Player::instance = nullptr;

Player& Player::getInstance(const string& name) {
	if (instance == nullptr) {
		instance = new Player(name);
	}
	return *instance;
}
Player::Player(const string& name) : name(name), health(100), gold(0), reputation({ {"Knights", 0}, {"Pirates", 0}, {"Aristocrats", 0}, {"Nomads", 0}, {"Samurai", 0}, {"Wizards", 0}}) {
	inventory.emplace_back(new Weapon("Wood Hammer", 1));
	inventory.emplace_back(new Item("Wood", 999));
	inventory.emplace_back(new Item("Leather", 999));
	inventory.emplace_back(new Item("Iron", 999));
	inventory.emplace_back(new Item("Steel", 999));
	inventory.emplace_back(new Item("Soulurite", 999));
	inventory.emplace_back(new Item("Iron Ore", 999));
	
	inventory.push_back(&Weapon::woodStaffW);
	inventory.push_back(&Weapon::ironStaffW);
	inventory.push_back(&Weapon::ironSpearW);
	inventory.push_back(&Weapon::souluriteShurikenW);
	inventory.push_back(&Weapon::steelMaceW);
	inventory.push_back(&Weapon::steelStaffW);
	inventory.push_back(&Weapon::ironSwordW);
	inventory.push_back(&Weapon::souluriteSpearW);
	inventory.push_back(&Weapon::woodBoomerangW);

}

bool Player::hasMaterials(const vector<pair<string, int>>& recipe) {
	int count = 0;
	// Go through items in recipe
	for (const auto& mat : recipe) {
		const string& matName = mat.first;
		int requiredAmount = mat.second;
		bool itemFound = false;
		// Skip the first item in recipe (name/quantity of product)
		if (count != 0) {
			// Go through items in inventory to see if it matches given mat
			for (const auto& item : inventory) {
				if (item->getName() == matName) {
					
					// Check if appropriate quantity
					if (item->getQuantity() < requiredAmount) {
						cout << requiredAmount << " " << matName << " not found" << endl;
						return false;
					}
					else {
						itemFound = true;
					}
				}
			}
			if (!itemFound) {
				cout << requiredAmount << " " << matName << " not found" << endl;
				return false;
			}
			
		}
		count++;
	}
	return true;
}

void Player::addItem(Item* item, int quantity) {
	// Check if item is already in inventory
	for (auto& invItem : inventory) {
		if (invItem->getName() == item->getName()) {
			invItem->addQuantity(quantity);
			cout << "[Gained " << quantity << " " << item->getName() << "]" << endl << endl;
			return;
		}
	}
	// New item not yet in inventory
	Item* tempItem = nullptr;
	// Check if item being added is a weapon
	if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
		tempItem = new Weapon(*weapon);
	}
	else {
		tempItem = new Item(*item);
	}

	tempItem->setQuantity(quantity);
	inventory.push_back(tempItem);

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
			inventory.erase(itemLocation);
		}
		// Print item removed
		cout << "[Removed " << quantity << " " << item->getName() << "]" << endl << endl;
	}
	else {
		inventory.push_back(item);
		// Item not found
		cout.flush();
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

map<string, int> Player::getReputation() {
	return reputation;
}

void Player::updateReputation(string faction, int points) {
	reputation[faction] += points;
	string plus = "";
	if (points >= 0) {
		plus = "+";
	}
	cout << "[ " << plus << points << " reputation with " << faction << " ]" << endl;
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

Weapon* Player::chooseWeapon() {
	vector<Weapon*> weapList;
	Weapon* weapChoice;
	int num = 1;
	int choice;
	// List weapons to choose from
	for (Item* item : inventory) {
		// Attempt dynamic cast of item into a weapon
		Weapon* weap = dynamic_cast<Weapon*>(item);
		// Weap will be non null
		if (weap) {
			cout << num << ") " << left << setw(20) << weap->getName()
				<< "    " << "Dmg: " << weap->getDamage() << endl;
			weapList.push_back(weap);
			num++;
		}
	}
	cout << "Enter -1 to cancel or " << endl;
	cout << "Choose a weapon: ";
	cin >> choice;
	if (choice == -1) {
		weapChoice = nullptr;
	}
	else {
		weapChoice = weapList.at(choice - 1);
	}
	
	return weapChoice;
}

void Player::craftWeapon(const string& name, Weapon* weapon, const vector<pair<string, int>>& recipe) {
	int craftQuantity = recipe[0].second;
	int count = 0;
	// Check if materials are in inventory
	if (hasMaterials(recipe)) {
		// Remove materials from inventory - loop through recipe
		for (const auto& mat : recipe) {
			// Skip the first item in recipe (name/quantity of product)
			if (count != 0) {
				const string& matName = mat.first;
				int requiredAmount = mat.second;
				// Go through each inventory item to see if it needs to be removed
				for (auto& item : inventory) {
					if (item->getName() == matName) {
						item->subtractQuantity(requiredAmount);
					}
				}
			}
			count++;
		}
		addItem(weapon, craftQuantity);
	}
}
void Player::smeltItem(const string& name, Item* item, const vector<pair<string, int>>& recipe) {
	int count = 0;
	// Check if materials are in inventory
	if (hasMaterials(recipe)) {
		// Remove materials from inventory - loop through recipe
		for (const auto& mat : recipe) {
			// Skip the first item in recipe (name/quantity of product)
			if (count != 0) {
				const string& matName = mat.first;
				int requiredAmount = mat.second;
				// Go through each inventory item to see if it needs to be removed
				for (auto& invItem : inventory) {
					if (invItem->getName() == matName) {
						invItem->subtractQuantity(requiredAmount);
					}
				}
			}
			count++;
			
		}
		addItem(item, 1);
	}
}