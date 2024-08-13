#pragma once
#include "Story.h"
#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "HealingItem.h"
#include "GameManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include <atomic>
#include <cstdlib>
#include <ctime>
#include <unordered_set>


using namespace std;

// Set cursor to specific coordinate
void setCursorPosition(int, int);

// Make user input lowercase
string lowercase(string);

// Number combo guess
bool unlockChest(int, vector<Item*> reward = {}, int g=0, int a=3);

// Guess scrambled word
bool wordUnscramble(Player& player);

// Riddle
void riddle(string riddle, string answer, string answer2);

// Rock paper scissors
int rockPaperScissors(Player& player);

// Quiz game (like how many times a letter appeared or like names or smth idk
int quiz();

// Mining mini game
void miningGame(int bar, int spots, int speed, Item ore, int amount);

// Enemy combat game
bool enemyCombat(string name, int dmg, int hp);

// Memory game with 3-5 tries
void memory();

// Chopping tree mini game
void chopTreeGame(int height, int speed, Item wood, int amount);