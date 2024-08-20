#pragma once
#include "RequestBoard.h"
#include <map>
using namespace std;

class GameManager
{
private:
	GameManager();
	~GameManager();
	static GameManager* instance;
public:
	static GameManager& getInstance();
	void displayGameState() const;
	void updateCheckpoint(const string, bool);
	void setMasterRequests();
	void stockGeneralStore();
	void addRequestById(int id);
	void displayGeneralStore();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	Player& player;
	map<string, bool> checkpoints;
	RequestBoard& requestBoard;
	vector<Request> masterRequests;
	map<Item*, int> generalStoreItems;
	Weapon* ironSword;
	Item* leather;
	HealingItem* potion;
};
