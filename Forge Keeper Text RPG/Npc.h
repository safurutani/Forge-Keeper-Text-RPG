#pragma once

#include <string>
#include <vector>
using namespace std;

class Npc
{
private:
	string name;
	vector<string> questList;

public:
	Npc(string name);
};
