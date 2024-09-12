#pragma once
#include "Item.h"

class Request
{
private:
	int id;
	string person;
	string info;
	vector<Item*> reward;
	int gold;
	bool completed;
public:
	Request();
	Request(int, const string&, const string&, int);
	Request(int,  const string&, const string&, vector<Item*>, int);
	Request(int, const string&, const string&, vector<Item*>);
	void displayRequest() const;
	void markComplete();
	int getId() const;
	string getInfo() const;
};

