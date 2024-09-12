#include "RequestBoard.h"
RequestBoard* RequestBoard::instance = nullptr;

RequestBoard::RequestBoard() {
}
RequestBoard& RequestBoard::getInstance() {
	static RequestBoard instance;
	return instance;
}

Request RequestBoard::getRequest(int id) {
	for (const auto& request : requests) {
		if (request.getId() == id) {
			return request;
		}
	}
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