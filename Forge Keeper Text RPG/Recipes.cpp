#include "Recipes.h"


using namespace std;

// SWORDS
map<string, int> woodSword = {
	{"Wood", 4},
	{"Leather", 1}
};
map<string, int> ironSword = {
	{"Iron", 4},
	{"Leather", 1}
};
map<string, int> steelSword = {
	{"Steel", 4},
	{"Leather", 1}
};
map<string, int> souluriteSword = {
	{"Soulurite", 4},
	{"Leather", 1}
};
map<string, int> ironCutlass = {
	{"Iron", 3},
	{"Leather", 1}
};
map<string, int> ironScythe = {
	{"Wood", 2},
	{"Iron", 2},
	{"Leather", 1}
};
map<string, int> steelCutlass = {
	{"Steel", 3},
	{"Leather", 1}
};
map<string, int> steelScythe = {
	{"Wood", 2},
	{"Steel", 2},
	{"Leather", 1}
};

// SHURIKEN RECIPES
map<string, int> ironShuriken = {
	{"Iron", 1}
};
map<string, int> steelShuriken = {
	{"Steel", 1}
};
map<string, int> souluriteShuriken = {
	{"Soulurite", 1}
};

// STAFF RECIPES
map<string, int> woodStaff = {
	{"Wood", 5},
	{"Leather", 1}
};
map<string, int> ironStaff = {
	{"Iron", 5},
	{"Leather", 1}
};
map<string, int> steelStaff = {
	{"Steel", 5},
	{"Leather", 1}
};
map<string, int> souluriteStaff = {
	{"Soulurite", 5},
	{"Leather", 1}
};

// BOOMERANG RECIPES
map<string, int> woodBoomerang = {
	{"Wood", 2}
};
map<string, int> ironBoomerang = {
	{"Iron", 2}
};
map<string, int> steelBoomerang = {
	{"Steel", 2}
};
map<string, int> souluriteBoomerang = {
	{"Soulurite", 2}
};


// MACE RECIPES
map<string, int> ironMace = {
	{"Iron", 2},
	{"Wood", 2},
	{"Leather", 2}
};
map<string, int> steelMace = {
	{"Steel", 2},
	{"Wood", 2},
	{"Leather", 2}
};
map<string, int> souluriteMace = {
	{"Soulurite", 2},
	{"Wood", 2},
	{"Leather", 2}
};


// AXE RECIPES
map<string, int> woodAxe = {
	{"Wood", 4},
	{"Leather", 1}
};
map<string, int> ironAxe = {
	{"Iron", 2},
	{"Wood", 2},
	{"Leather", 1}
};
map<string, int> steelAxe = {
	{"Steel", 2},
	{"Wood", 3},
	{"Leather", 1}
};
map<string, int> souluriteAxe = {
	{"Soulurite", 2},
	{"Wood", 2},
	{"Leather", 1}
};

// BOW RECIPES
map<string, int> woodBow = {
	{"Wood", 3},
	{"Leather", 1},
	{"Rope", 2}
};
map<string, int> steelBow = {
	{"Steel", 3},
	{"Leather", 1},
	{"Rope", 2}
};

// ARROW RECIPES MAKES 2
map<string, int> woodArrow = {
   {"Wood", 2},
   {"Leather", 1}
};
map<string, int> ironArrow = {
	{"Wood", 1},
	{"Iron", 1},
	{"Leather", 1}
};
map<string, int> steelArrow = {
	{"Wood", 1},
	{"Steel", 1},
	{"Leather", 1}
};
map<string, int> souluriteArrow = {
	{"Wood", 1},
	{"Soulurite", 1},
	{"Leather", 1}
};

// SPEAR RECIPES
map<string, int> woodSpear = {
   {"Wood", 4},
   {"Leather", 1}
};
map<string, int> ironSpear = {
	{"Wood", 3},
	{"Iron", 1},
	{"Leather", 1}
};
map<string, int> steelSpear = {
	{"Wood", 3},
	{"Steel", 1},
	{"Leather", 1}
};
map<string, int> souluriteSpear = {
	{"Wood", 3},
	{"Soulurite", 1},
	{"Leather", 1}
};

//RECIPE VECTORS
vector<map<string, int>> swordRecipes({ woodSword, ironSword, steelSword, souluriteSword, ironCutlass, steelCutlass, ironScythe, steelScythe });
vector<map<string, int>> spearRecipes({ woodSpear, ironSpear, steelSpear, souluriteSpear });
vector<map<string, int>> bowRecipes({ woodBow, steelBow });
vector<map<string, int>> arrowRecipes({ woodArrow, ironArrow, steelArrow, souluriteArrow });
vector<map<string, int>> axeRecipes({ woodAxe, ironAxe, steelAxe, souluriteAxe });
vector<map<string, int>> maceRecipes({ ironMace, steelMace, souluriteMace });
vector<map<string, int>> boomerangRecipes({ woodBoomerang, ironBoomerang, steelBoomerang, souluriteBoomerang });
vector<map<string, int>> staffRecipes({ woodStaff, ironStaff, steelStaff, souluriteStaff });
vector<map<string, int>> shurikenRecipes({ ironShuriken, steelShuriken, souluriteShuriken });

// GET RECIPES
vector<map<string, int>> getShurikenRecipes() {
	return shurikenRecipes;
}
vector<map<string, int>> getStaffRecipes() {
	return staffRecipes;
}
vector<map<string, int>> getBoomerangRecipes() {
	return boomerangRecipes;
}
vector<map<string, int>> getMaceRecipes() {
	return maceRecipes;
}
vector<map<string, int>> getAxeRecipes() {
	return axeRecipes;
}
vector<map<string, int>> getBowRecipes() {
	return bowRecipes;
}
vector<map<string, int>> getArrowRecipes() {
	return arrowRecipes;
}
vector<map<string, int>> getSpearRecipes() {
	return spearRecipes;
}
vector<map<string, int>> getSwordRecipes() {
	return swordRecipes;
}