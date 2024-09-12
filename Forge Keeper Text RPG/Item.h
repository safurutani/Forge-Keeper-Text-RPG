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
	string description;
	vector<pair<string, int>> recipe;
public:
	Item();
	Item(const string& name);
	Item(const string& name, int qty);
	Item(const string& name, int qty, vector<pair<string, int>> recipe);
	Item(const string& name, const string& description);
	Item(const string& name, const string& description, int qty);
	virtual ~Item() = default;

	virtual string getName() const;
	string getDescription() const;
	void setDescription(string);
	int getQuantity() const;
	void addQuantity(int num);
	void setQuantity(int newQuantity);
	void subtractQuantity(int num);

	bool isEqualToItem(Item& item) const;
};
