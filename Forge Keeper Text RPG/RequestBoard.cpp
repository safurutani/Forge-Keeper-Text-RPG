#include "RequestBoard.h"
RequestBoard* RequestBoard::instance = nullptr;

RequestBoard::RequestBoard() {
	requests.push_back(Request(1, "Sir Henry of the Terra Guard",
		"We also have a resident merchant who can sell you finished goods at the General Store, but the raw materials you'll have to source yourself.\n", 100));
}
RequestBoard& RequestBoard::getInstance() {
	static RequestBoard instance;
	return instance;
}

void RequestBoard::getRequests() const {
	for (const Request req : requests) {
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