#pragma once
#include "Request.h"
#include "Player.h"
class RequestBoard
{
private:
	RequestBoard();
	~RequestBoard() = default;
	static RequestBoard* instance;
	vector<Request> requests;
public:
	static RequestBoard& getInstance();
	RequestBoard(const RequestBoard&) = delete;
	RequestBoard& operator=(const RequestBoard&) = delete;
	void getRequests() const;
	void addRequest(Request);
	void removeRequest(int);
};

