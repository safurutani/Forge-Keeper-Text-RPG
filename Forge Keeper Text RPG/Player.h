#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Weapon.h"
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

	// Singleton
	Player(const string& name);
	static Player* instance;

public:

	string getName() const;
	static Player& getInstance(const string& name="Traveler");
	vector<Item*> getInventory();
	void displayInventory() const;
	void addItem(Item* item, int quantity);
	void removeItem(Item* item, int quantity);
	
	void displayHealth() const;
	void increaseHealth(int hp);
	void decreaseHealth(int hp);

	void displayGold() const;
	void increaseGold(int gold);
	void decreaseGold(int gold);
};
