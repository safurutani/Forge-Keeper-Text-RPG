#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

extern vector<pair<string, int>> woodSword;
extern vector<pair<string, int>> ironSword;
extern vector<pair<string, int>> steelSword;
extern vector<pair<string, int>> souluriteSword;
extern vector<pair<string, int>> ironCutlass;
extern vector<pair<string, int>> steelCutlass;
extern vector<pair<string, int>> ironKatana;
extern vector<pair<string, int>> steelKatana;
extern vector<pair<string, int>> woodSpear;
extern vector<pair<string, int>> ironSpear;
extern vector<pair<string, int>> steelSpear;
extern vector<pair<string, int>> souluriteSpear;
extern vector<pair<string, int>> woodBow;
extern vector<pair<string, int>> steelBow;
extern vector<pair<string, int>> woodArrow;
extern vector<pair<string, int>> ironArrow;
extern vector<pair<string, int>> steelArrow;
extern vector<pair<string, int>> souluriteArrow;
extern vector<pair<string, int>> ironMace;
extern vector<pair<string, int>> steelMace;
extern vector<pair<string, int>> souluriteMace;
extern vector<pair<string, int>> woodBoomerang;
extern vector<pair<string, int>> ironBoomerang;
extern vector<pair<string, int>> steelBoomerang;
extern vector<pair<string, int>> souluriteBoomerang;
extern vector<pair<string, int>> woodStaff;
extern vector<pair<string, int>> ironStaff;
extern vector<pair<string, int>> steelStaff;
extern vector<pair<string, int>> souluriteStaff;
extern vector<pair<string, int>> ironShuriken;
extern vector<pair<string, int>> steelShuriken;
extern vector<pair<string, int>> souluriteShuriken;
extern vector<pair<string, int>> smeltIron;
extern vector<pair<string, int>> smeltSteel;
extern vector<pair<string, int>> smeltSoulurite;
extern vector<pair<string, int>> woodAxe;
extern vector<pair<string, int>> ironAxe;
extern vector<pair<string, int>> steelAxe;
extern vector<pair<string, int>> souluriteAxe;

extern vector<vector<pair<string, int>>> swordRecipes;
extern vector<vector<pair<string, int>>> spearRecipes;
extern vector<vector<pair<string, int>>> bowArrowRecipes;
extern vector<vector<pair<string, int>>> axeRecipes;
extern vector<vector<pair<string, int>>> maceRecipes;
extern vector<vector<pair<string, int>>> boomerangRecipes;
extern vector<vector<pair<string, int>>> staffRecipes;
extern vector<vector<pair<string, int>>> shurikenRecipes;
extern vector<vector<pair<string, int>>> smeltRecipes;

extern vector<vector<pair<string, int>>> getShurikenRecipes();
extern vector<vector<pair<string, int>>> getStaffRecipes();
extern vector<vector<pair<string, int>>> getBoomerangRecipes();
extern vector<vector<pair<string, int>>> getMaceRecipes();
extern vector<vector<pair<string, int>>> getAxeRecipes();
extern vector<vector<pair<string, int>>> getBowArrowRecipes();
extern vector<vector<pair<string, int>>> getSpearRecipes();
extern vector<vector<pair<string, int>>> getSwordRecipes();
extern vector<vector<pair<string, int>>> getSmeltRecipes();

void displayRecipes(vector<vector<pair<string, int>>>); 
