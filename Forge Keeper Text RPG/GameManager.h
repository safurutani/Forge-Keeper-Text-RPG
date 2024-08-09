#pragma once
#include "Story.h"
#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "Location.h"
#include "Npc.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

class GameManager
{
private:
	GameManager();
	~GameManager() = default;
public:
	static GameManager& getInstance();
	void displayGameState() const;
	void updateCheckpoint(const string&, bool);

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	Player& player;
	map<string, bool> checkpoints;
};
