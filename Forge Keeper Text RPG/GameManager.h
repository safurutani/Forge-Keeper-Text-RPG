#pragma once
#include "RequestBoard.h"
#include <map>
using namespace std;

class GameManager
{
private:
	GameManager();
	~GameManager() = default;
	static GameManager* instance;
public:
	static GameManager& getInstance();
	void displayGameState() const;
	void updateCheckpoint(const string, bool);

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	Player& player;
	map<string, bool> checkpoints;
	RequestBoard& requestBoard;
};
