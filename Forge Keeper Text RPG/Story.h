#pragma once

#include "Story.h"
#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "Location.h"
#include "GameManager.h"
#include "Npc.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

void clickToContinue(string singleOption = "continue");

void introduction(Player& player);
void learnForge();
void introTownSquare();