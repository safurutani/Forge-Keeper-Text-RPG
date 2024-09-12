#include "Recipes.h"

using namespace std;

// SWORDS
vector<pair<string, int>> woodSword = {
	{"Wood Sword", 1},
	{"Wood", 4},
	{"Leather", 1}
};
vector<pair<string, int>> ironSword = {
	{"Iron Sword", 1},
	{"Iron", 4},
	{"Leather", 1}
};
vector<pair<string, int>> steelSword = {
	{"Steel Sword", 1},
	{"Steel", 4},
	{"Leather", 1}
};
vector<pair<string, int>> souluriteSword = {
	{"Soulurite Sword", 1},
	{"Soulurite", 4},
	{"Leather", 1}
};
vector<pair<string, int>> ironCutlass = {
	{"Iron Cutlass", 1},
	{"Iron", 3},
	{"Leather", 1}
};
vector<pair<string, int>> ironKatana = {
	{"Iron Katana", 1},
	{"Wood", 1},
	{"Iron", 3},
	{"Leather", 1}
};
vector<pair<string, int>> steelCutlass = {
	{"Steel Cutlass", 1},
	{"Steel", 3},
	{"Leather", 1}
};
vector<pair<string, int>> steelKatana = {
	{"Steel Katana", 1},
	{"Wood", 1},
	{"Steel", 3},
	{"Leather", 1}
};

// SHURIKEN RECIPES
vector<pair<string, int>> ironShuriken = {
	{"Iron Shuriken", 2},
	{"Iron", 1}
};
vector<pair<string, int>> steelShuriken = {
	{"Steel Shuriken", 2},
	{"Steel", 1}
};
vector<pair<string, int>> souluriteShuriken = {
	{"Soulurite Shuriken", 2},
	{"Soulurite", 1}
};

// STAFF RECIPES
vector<pair<string, int>> woodStaff = {
	{"Wood Staff", 1},
	{"Wood", 5},
	{"Leather", 1}
};
vector<pair<string, int>> ironStaff = {
	{"Iron Staff", 1},
	{"Iron", 5},
	{"Leather", 1}
};
vector<pair<string, int>> steelStaff = {
	{"Steel Staff", 1},
	{"Steel", 5},
	{"Leather", 1}
};
vector<pair<string, int>> souluriteStaff = {
	{"Soulurite Staff", 1},
	{"Soulurite", 5},
	{"Leather", 1}
};

// BOOMERANG RECIPES
vector<pair<string, int>> woodBoomerang = {
	{"Wood Boomerang", 1},
	{"Wood", 2}
};
vector<pair<string, int>> ironBoomerang = {
	{"Iron Boomerang", 1},
	{"Iron", 2}
};
vector<pair<string, int>> steelBoomerang = {
	{"Steel Boomerang", 1},
	{"Steel", 2}
};
vector<pair<string, int>> souluriteBoomerang = {
	{"Soulurite Boomerang", 1},
	{"Soulurite", 2}
};


// MACE RECIPES
vector<pair<string, int>> ironMace = {
	{"Iron Mace", 1},
	{"Iron", 2},
	{"Wood", 2},
	{"Leather", 2}
};
vector<pair<string, int>> steelMace = {
	{"Steel Mace", 1},
	{"Steel", 2},
	{"Wood", 2},
	{"Leather", 2}
};
vector<pair<string, int>> souluriteMace = {
	{"Soulurite Mace", 1},
	{"Soulurite", 2},
	{"Wood", 2},
	{"Leather", 2}
};


// AXE RECIPES
vector<pair<string, int>> woodAxe = {
	{"Wood Battle Axe", 1},
	{"Wood", 4},
	{"Leather", 1}
};
vector<pair<string, int>> ironAxe = {
	{"Steel Battle Axe", 1},
	{"Iron", 2},
	{"Wood", 2},
	{"Leather", 1}
};
vector<pair<string, int>> steelAxe = {
	{"Steel Battle Axe", 1},
	{"Steel", 2},
	{"Wood", 3},
	{"Leather", 1}
};
vector<pair<string, int>> souluriteAxe = {
	{"Soulurite Battle Axe", 1},
	{"Soulurite", 2},
	{"Wood", 2},
	{"Leather", 1}
};

// BOW RECIPES
vector<pair<string, int>> woodBow = {
	{"Wood Bow", 1},
	{"Wood", 3},
	{"Leather", 1},
	{"Rope", 2}
};
vector<pair<string, int>> steelBow = {
	{"Steel Bow", 1},
	{"Steel", 3},
	{"Leather", 1},
	{"Rope", 2}
};

// ARROW RECIPES MAKES 2
vector<pair<string, int>> woodArrow = {
	{"Wood Arrow", 2},
   {"Wood", 2},
   {"Leather", 1}
};
vector<pair<string, int>> ironArrow = {
	{"Iron Arrow", 2},
	{"Wood", 1},
	{"Iron", 1},
	{"Leather", 1}
};
vector<pair<string, int>> steelArrow = {
	{"Steel Arrow", 2},
	{"Wood", 1},
	{"Steel", 1},
	{"Leather", 1}
};
vector<pair<string, int>> souluriteArrow = {
	{"Soulurite Arrow", 2},
	{"Wood", 1},
	{"Soulurite", 1},
	{"Leather", 1}
};

// SPEAR RECIPES
vector<pair<string, int>> woodSpear = {
	{"Wood Spear", 1},
    {"Wood", 4},
    {"Leather", 1}
};
vector<pair<string, int>> ironSpear = {
	{"Iron Spear", 1},
	{"Wood", 3},
	{"Iron", 1},
	{"Leather", 1}
};
vector<pair<string, int>> steelSpear = {
	{"Steel Spear", 1},
	{"Wood", 3},
	{"Steel", 1},
	{"Leather", 1}
};
vector<pair<string, int>> souluriteSpear = {
	{"Soulurite Spear", 1},
	{"Wood", 3},
	{"Soulurite", 1},
	{"Leather", 1}
};

// SMELT RECIPES
vector<pair<string, int>> smeltIron = {
	{"Iron", 1},
	{"Iron Ore", 3}
};
vector<pair<string, int>> smeltSteel = {
	{"Steel", 1},
	{"Steel Ore", 3}
};
vector<pair<string, int>> smeltSoulurite = {
	{"Soulurite", 1},
	{"Soulurite Ore", 3}
};

//RECIPE VECTORS
vector<vector<pair<string, int>>> swordRecipes({ woodSword, ironSword, steelSword, souluriteSword, ironCutlass, steelCutlass, ironKatana, steelKatana });
vector<vector<pair<string, int>>> spearRecipes({ woodSpear, ironSpear, steelSpear, souluriteSpear });
vector<vector<pair<string, int>>> bowArrowRecipes({ woodBow, steelBow, woodArrow, ironArrow, steelArrow, souluriteArrow });
vector<vector<pair<string, int>>> axeRecipes({ woodAxe, ironAxe, steelAxe, souluriteAxe });
vector<vector<pair<string, int>>> maceRecipes({ ironMace, steelMace, souluriteMace });
vector<vector<pair<string, int>>> boomerangRecipes({ woodBoomerang, ironBoomerang, steelBoomerang, souluriteBoomerang });
vector<vector<pair<string, int>>> staffRecipes({ woodStaff, ironStaff, steelStaff, souluriteStaff });
vector<vector<pair<string, int>>> shurikenRecipes({ ironShuriken, steelShuriken, souluriteShuriken });
vector<vector<pair<string, int>>> smeltRecipes({smeltIron, smeltSteel, smeltSoulurite});
// GET RECIPES
vector<vector<pair<string, int>>> getShurikenRecipes() {
	return shurikenRecipes;
}
vector<vector<pair<string, int>>> getStaffRecipes() {
	return staffRecipes;
}
vector<vector<pair<string, int>>> getBoomerangRecipes() {
	return boomerangRecipes;
}
vector<vector<pair<string, int>>> getMaceRecipes() {
	return maceRecipes;
}
vector<vector<pair<string, int>>> getAxeRecipes() {
	return axeRecipes;
}
vector<vector<pair<string, int>>> getBowArrowRecipes() {
	return bowArrowRecipes;
}

vector<vector<pair<string, int>>> getSpearRecipes() {
	return spearRecipes;
}
vector<vector<pair<string, int>>> getSwordRecipes() {
	return swordRecipes;
}
vector<vector<pair<string, int>>> getSmeltRecipes() {
	return smeltRecipes;
}

// PRINT RECIPES
void displayRecipes(vector<vector<pair<string, int>>> recipeList) {
	int recipeCounter = 1;
	// Iterate through each recipe
	for (auto it = recipeList.begin(); it != recipeList.end(); it++) {
		int counter = 0;
		cout << recipeCounter << ") ";
		// Iterate through each item in recipe
		for (auto const& item : *it ) {
			
			if (counter == 0) {
				cout << item.second << " " << item.first << " - ";
			}
			else if (counter != it->size() -1) {
				cout << item.first << " (" << item.second << "), ";
			}
			else {
				cout << item.first << " (" << item.second << ") ";
			}
			counter++;
		}
		cout << endl;
		recipeCounter++;
	}
}