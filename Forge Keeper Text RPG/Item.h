#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

class Item
{
private:
	string name;
	int quantity;
public:
	Item();
	Item(const string& name);

	string getName() const;
	int getQuantity() const;
	void addQuantity(int num);
	void subtractQuantity(int num);

	bool isEqualToItem(Item& item) const;
};
