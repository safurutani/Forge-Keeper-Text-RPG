#include "GameManager.h"

GameManager::GameManager() : player(Player::getInstance()) {
	checkpoints = {
		{"Note #1", false},
		{"Unknown object blueprint", false},
		{"Stone hammer", false}

	};
}

GameManager& GameManager::getInstance() {
	static GameManager instance;
	return instance;
}

void GameManager::displayGameState() const{

}

void GameManager::updateCheckpoint(const string& checkpoint, bool reached) {
	checkpoints[checkpoint] = reached;
}