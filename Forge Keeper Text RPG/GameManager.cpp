#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

// Initializes reference from header with singleton instances of player and requestBoard
GameManager::GameManager() : player(Player::getInstance()), requestBoard(RequestBoard::getInstance()) {
	checkpoints = {
		{"Note #1", false},
		{"Unknown object blueprint", false},
		{"Stone hammer", false},
		{"Mines visited", false},
		{"Forest visited", false},
		{"General store visited", false},
		{"Code #1", false},
		{"Bat defeated", false},
		{"Mine chest failed", false}

	};
	requestBoard.addRequest(Request(1, "Sir Henry of the Terra Guard",
		"We also have a resident merchant who can sell you finished goods at the General Store, but the raw materials you'll have to source yourself.\n", 100));
}

GameManager& GameManager::getInstance() {
	if (instance == nullptr) {
		instance = new GameManager();
	}
	return *instance;
}

void GameManager::displayGameState() const{

}

void GameManager::updateCheckpoint(const string checkpoint, bool reached) {
	checkpoints[checkpoint] = reached;
}