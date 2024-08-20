#pragma once

#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "MiniGames.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

void clearConsole();
void clickToContinue(string singleOption = "continue");

void introduction(Player& player);
void learnForge();
void introTownSquare();
void firstMines();
void leftMines();
void straightMines();
void rightMines();
void firstForest();
void followPath();
void goOffPath();
void gnomeInteraction();
void altarOffering(int);
void firstGeneralStore();
void generalStore();
void purchase(int);