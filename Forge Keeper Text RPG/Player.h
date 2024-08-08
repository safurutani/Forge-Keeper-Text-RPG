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
	static Player& getInstance(const string& name);
	void displayInventory() const;
	void addItem(Item* item, int quantity);
	void subtractItem(Item* item, int quantity);
	
	int getHealth() const;
	void increaseHealth(int hp);
	void decreaseHealth(int hp);

	int getGold() const;
	void increaseGold(int gold);
	void decreaseGold(int gold);
};
