#include "RequestBoard.h"
RequestBoard* RequestBoard::instance = nullptr;

RequestBoard::RequestBoard() {
	requests.push_back(Request(1, "Sir Henry of the Terra Guard",
		"I have shattered my previous blade in a duel and need to restore my honor.\nI need a blade much stronger than the copper one I once wielded.\n", 100));
}
RequestBoard& RequestBoard::getInstance() {
	static RequestBoard instance;
	return instance;
}

void RequestBoard::getRequests() const {
	for (const Request& req : requests) {
		req.displayRequest();
	}
}

void RequestBoard::addRequest(Request newRequest) {
	requests.push_back(newRequest);
}

void RequestBoard::removeRequest(int id) {
	for (int i = 0; i < requests.size(); i++) {
		if (requests[i].getId() == id) {
			requests.erase(requests.begin() + i);
			break;
		}
	}
}