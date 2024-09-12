#include "Weapon.h"
#include "Recipes.h"
#include "Player.h"
#include "Story.h"

Weapon::Weapon() : Item(""), damage(0) {}
Weapon::Weapon(const string& name, int damage) 
	: Item(name), damage(damage) {}
Weapon::Weapon(const string& name, int damage, vector<pair<string, int>> recipe)
	: Item(name), damage(damage), recipe(recipe) {}
int Weapon::getDamage() const {
	return damage;
}

// Weapons
Weapon Weapon::woodSwordW = Weapon("Wood Sword", 2, woodSword);
Weapon Weapon::ironSwordW = Weapon("Iron Sword", 4, ironSword);
Weapon Weapon::steelSwordW = Weapon("Steel Sword", 6, steelSword);
Weapon Weapon::souluriteSwordW = Weapon("Soulurite Sword", 12, souluriteSword);
Weapon Weapon::ironCutlassW = Weapon("Iron Cutlass", 4, ironCutlass);
Weapon Weapon::steelCutlassW = Weapon("Steel Cutlass", 6, steelCutlass);
Weapon Weapon::ironKatanaW = Weapon("Iron Katana", 4, ironKatana);
Weapon Weapon::steelKatanaW = Weapon("Steel Katana", 6, steelKatana);
Weapon Weapon::woodSpearW = Weapon("Wood Spear", 2, woodSpear);
Weapon Weapon::ironSpearW = Weapon("Iron Spear", 3, ironSpear);
Weapon Weapon::steelSpearW = Weapon("Steel Spear", 5, steelSpear);
Weapon Weapon::souluriteSpearW = Weapon("Soulurite Spear", 10, souluriteSpear);
Weapon Weapon::woodBowW = Weapon("Wood Bow", 1, woodBow);
Weapon Weapon::steelBowW = Weapon("Steel Bow", 2, steelBow);
Weapon Weapon::woodArrowW = Weapon("Wood Arrow", 1, woodArrow);
Weapon Weapon::ironArrowW = Weapon("Iron Arrow", 3, ironArrow);
Weapon Weapon::steelArrowW = Weapon("Steel Arrow", 5, steelArrow);
Weapon Weapon::souluriteArrowW = Weapon("Soulurite Arrow", 9, souluriteArrow);
Weapon Weapon::ironMaceW = Weapon("Iron Mace", 3, ironMace);
Weapon Weapon::steelMaceW = Weapon("Steel Mace", 5, steelMace);
Weapon Weapon::souluriteMaceW = Weapon("Soulurite Mace", 10, souluriteMace);
Weapon Weapon::woodBoomerangW = Weapon("Wood Boomerang", 1, woodBoomerang);
Weapon Weapon::ironBoomerangW = Weapon("Iron Boomerang", 3, ironBoomerang);
Weapon Weapon::steelBoomerangW = Weapon("Steel Boomerang", 5, steelBoomerang);
Weapon Weapon::souluriteBoomerangW = Weapon("Soulurite Boomerang", 10, souluriteBoomerang);
Weapon Weapon::woodStaffW = Weapon("Wood Staff", 2, woodStaff);
Weapon Weapon::ironStaffW = Weapon("Iron Staff", 4, ironStaff);
Weapon Weapon::steelStaffW = Weapon("Steel Staff", 6, steelStaff);
Weapon Weapon::souluriteStaffW = Weapon("Soulurite Staff", 12, souluriteStaff);
Weapon Weapon::ironShurikenW = Weapon("Iron Shuriken", 3, ironShuriken);
Weapon Weapon::steelShurikenW = Weapon("Steel Shuriken", 5, steelShuriken);
Weapon Weapon::souluriteShurikenW = Weapon("Soulurite Shuriken", 9, souluriteShuriken);
Weapon Weapon::woodAxeW = Weapon("Wood Battle Axe", 2, woodAxe);
Weapon Weapon::ironAxeW = Weapon("Iron Battle Axe", 4, ironAxe);
Weapon Weapon::steelAxeW = Weapon("Steel Battle Axe", 6, steelAxe);
Weapon Weapon::souluriteAxeW = Weapon("Soulurite Battle Axe", 12, souluriteAxe);

void Weapon::getRecipe() const {
	for (auto& pair : recipe) {
		string item = pair.first;
		int quantity = pair.second;
		cout << item << ": " << quantity << endl;
	}
}

void Weapon::forge() {
	Player& player = Player::getInstance();
	// Materials
	Item iron("Iron", 1, smeltIron);
	Item steel("Steel", 1, smeltSteel);
	Item soulurite("Soulurite", 1, smeltSoulurite);
	

	cout << "Welcome to your forge" << endl
		<< "---------------------" << endl;
	int selection;
	do {
		cout << "1) Smelt ore" << endl
			<< "2) Forge a sword" << endl
			<< "3) Forge a spear" << endl
			<< "4) Forge a bow and arrows" << endl
			<< "5) Forge a battleaxe" << endl
			<< "6) Forge a mace" << endl
			<< "7) Forge a boomerang" << endl
			<< "8) Forge a staff" << endl
			<< "9) Forge shurikens" << endl 
			<< "0) QUIT" << endl << endl
			<< "Choice: ";
		cin >> selection;
		int craftChoice;
		switch (selection) {
		case 1:
			clearConsole();
			player.displayInventory();
			displayRecipes(smeltRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.smeltItem("Iron", &iron, smeltIron);
			}
			else if (craftChoice == 2) {
				player.smeltItem("Steel", &steel, smeltSteel);
			}
			else if (craftChoice == 3) {
				player.smeltItem("Soulurite", &soulurite, smeltSoulurite);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			
			break;
		case 2:
			clearConsole();
			player.displayInventory();
			displayRecipes(swordRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Sword", &woodSwordW, woodSword);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Iron Sword", &ironSwordW, ironSword);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Steel Sword", &steelSwordW, steelSword);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Soulurite Sword", &souluriteSwordW, souluriteSword);
			}
			else if (craftChoice == 5) {
				player.craftWeapon("Iron Cutlass", &ironCutlassW, ironCutlass);
			}
			else if (craftChoice == 6) {
				player.craftWeapon("Steel Cutlass", &steelCutlassW, steelCutlass);
			}
			else if (craftChoice == 7) {
				player.craftWeapon("Iron Katana", &ironKatanaW, ironKatana);
			}
			else if (craftChoice == 8) {
				player.craftWeapon("Steel Katana", &steelKatanaW, steelKatana);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 3:
			clearConsole();
			player.displayInventory();
			displayRecipes(spearRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Spear", &woodSpearW, woodSpear);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Iron Spear", &ironSpearW, ironSpear);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Steel Spear", &steelSpearW, steelSpear);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Soulurite Spear", &souluriteSpearW, souluriteSpear);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 4:
			clearConsole();
			player.displayInventory();
			displayRecipes(bowArrowRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Bow", &woodBowW, woodBow);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Steel Bow", &steelBowW, steelBow);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Wood Arrow", &woodArrowW, woodArrow);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Iron Arrow", &ironArrowW, ironArrow);
			}
			else if (craftChoice == 5) {
				player.craftWeapon("Steel Arrow", &steelArrowW, steelArrow);
			}
			else if (craftChoice == 6) {
				player.craftWeapon("Soulurite Arrow", &souluriteArrowW, souluriteArrow);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 5:
			clearConsole();
			player.displayInventory();
			displayRecipes(axeRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Battle Axe", &woodAxeW, woodAxe);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Iron Battle Axe", &ironAxeW, ironAxe);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Steel Battle Axe", &steelAxeW, steelAxe);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Soulurite Battle Axe", &souluriteAxeW, souluriteAxe);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 6:
			clearConsole();
			player.displayInventory();
			displayRecipes(maceRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Iron Mace", &ironMaceW, ironMace);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Steel Mace", &steelMaceW, steelMace);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Soulurite Mace", &souluriteMaceW, souluriteMace);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 7:
			clearConsole();
			player.displayInventory();
			displayRecipes(boomerangRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Boomerang", &woodBoomerangW, woodBoomerang);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Iron Boomerang", &ironBoomerangW, ironBoomerang);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Steel Boomerang", &steelBoomerangW, steelBoomerang);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Soulurite Boomerang", &souluriteBoomerangW, souluriteBoomerang);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 8:
			clearConsole();
			player.displayInventory();
			displayRecipes(staffRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Wood Staff", &woodStaffW, woodStaff);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Iron Staff", &ironStaffW, ironStaff);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Steel Staff", &steelStaffW, steelStaff);
			}
			else if (craftChoice == 4) {
				player.craftWeapon("Soulurite Staff", &souluriteStaffW, souluriteStaff);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		case 9:
			clearConsole();
			player.displayInventory();
			displayRecipes(shurikenRecipes);
			cin >> craftChoice;
			if (craftChoice == 1) {
				player.craftWeapon("Iron Shuriken", &ironShurikenW, ironShuriken);
			}
			else if (craftChoice == 2) {
				player.craftWeapon("Steel Shuriken", &steelShurikenW, steelShuriken);
			}
			else if (craftChoice == 3) {
				player.craftWeapon("Soulurite Shuriken", &souluriteShurikenW, souluriteShuriken);
			}
			else if (craftChoice == 0) {
				break;
			}
			else {
				cout << "Invalid Choice" << endl;
			}
			break;
		default:
			break;
		}
	} while (selection != 0);
}

