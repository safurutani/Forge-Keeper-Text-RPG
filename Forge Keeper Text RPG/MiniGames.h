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

using namespace std;

// Number combo guess
int unlockChest(Player& player);

// Guess scrambled word
bool wordUnscramble(Player& player);

// Riddle
bool riddle(Player& player);

// Rock paper scissors
int rockPaperScissors(Player& player);

// Quiz game (like how many times a letter appeared or like names or smth idk