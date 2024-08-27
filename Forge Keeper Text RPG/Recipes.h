#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

vector<map<string, int>> swordRecipes;
vector<map<string, int>> spearRecipes;
vector<map<string, int>> bowRecipes;
vector<map<string, int>> arrowRecipes;
vector<map<string, int>> axeRecipes;
vector<map<string, int>> maceRecipes;
vector<map<string, int>> boomerangRecipes;
vector<map<string, int>> staffRecipes;
vector<map<string, int>> shurikenRecipes;

vector<map<string, int>> getShurikenRecipes();
vector<map<string, int>> getStaffRecipes();
vector<map<string, int>> getBoomerangRecipes();
vector<map<string, int>> getMaceRecipes();
vector<map<string, int>> getAxeRecipes();
vector<map<string, int>> getBowRecipes();
vector<map<string, int>> getArrowRecipes();
vector<map<string, int>> getSpearRecipes();
vector<map<string, int>> getSwordRecipes();