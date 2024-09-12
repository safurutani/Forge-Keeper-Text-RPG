#pragma once

#include <string>
#include <vector>
#include <map>
#include "Item.h"
#include "HealingItem.h"
#include "Weapon.h"
#include "Recipes.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Player
{
private:
	string name;
	int health;
	int gold;
	vector<Item*> inventory;
	map<string, int> reputation;
	// Singleton
	Player(const string& name);
	static Player* instance;

public:

	string getName() const;
	void setName(string newName);
	static Player& getInstance(const string& name="Traveler");
	vector<Item*> getInventory();
	void displayInventory() const;
	void addItem(Item* item, int quantity);
	void removeItem(Item* item, int quantity);
	bool hasMaterials(const vector<pair<string, int>>& recipe);
	
	int getHealth() const;
	void displayHealth() const;
	void increaseHealth(int hp);
	void decreaseHealth(int hp);

	map<string, int> getReputation();
	void updateReputation(string, int);

	int getGold() const;
	void displayGold() const;
	void increaseGold(int gold);
	void decreaseGold(int gold);

	Weapon* chooseWeapon();

	void craftWeapon(const string& name, Weapon* weapon, const vector<pair<string, int>>& recipe);
	void smeltItem(const string& name, Item* item, const vector<pair<string, int>>& recipe);
};
