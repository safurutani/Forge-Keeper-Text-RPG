#include "Request.h"
#include <iostream>
using namespace std;
Request::Request() {}
Request::Request(int id, const string& person, const string& info, int gold)
	: id(id), person(person), info(info), gold(gold), completed(false) {}
Request::Request(int id, const string& person, const string& info, vector<Item*> reward)
	: id(id), person(person), info(info), reward(reward), gold(0), completed(false) {}
Request::Request(int id, const string& person, const string& info, vector<Item*> reward, int gold)
	: id(id), person(person), info(info), reward(reward), gold(gold), completed(false) {}

void Request::displayRequest() const {
	int lines = info.length() / 50;
	cout << person << endl << endl;
	cout << info << endl;
	cout << endl << "Reward: ";
	for (Item* r : reward) {
		cout << "        " << r->getQuantity() << " " << r->getName() << endl;
	}
	cout << gold << " gold" << endl;

	cout << endl << boolalpha << "Completed: " << completed << endl;

}

void Request::markComplete() {
	completed = true;
}

int Request::getId() const {
	return id;
}

string Request::getInfo() const {
	return info;
}