#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

// Initializes reference from header with singleton instances of player and requestBoard
GameManager::GameManager() : player(Player::getInstance()), requestBoard(RequestBoard::getInstance()) {
	checkpoints = {
		{"Note #1", false},
		{"Unknown object blueprint", false},
		{"Stone hammer", false},
		{"Mines visited", false},
		{"Forest visited", false},
		{"General store visited", false},
		{"Code #1", false},
		{"Bat defeated", false},
		{"Mine chest failed", false},
		{"Firewood taken", false},
		{"Nomad request refused", false},
	};

	setMasterRequests();
	addRequestById(1);
	// Stock the general store
	ironSword = new Weapon("Iron Sword", 4);
	potion = new HealingItem("Health Potion", 30);
	leather = new Item("Leather");
	ironSword->setDescription("sturdy, deals 4 dmg");
	ironSword->addQuantity(2);

	
	potion->setDescription("heals 30hp");
	potion->addQuantity(9);

	
	leather->setDescription("used for handles/grips");
	leather->addQuantity(9);

	stockGeneralStore();
}

GameManager& GameManager::getInstance() {
	if (instance == nullptr) {
		instance = new GameManager();
	}
	return *instance;
}

void GameManager::displayGameState() const{

}

GameManager::~GameManager() {
	delete ironSword;
	delete potion;
	delete leather;
}

void GameManager::updateCheckpoint(const string checkpoint, bool reached) {
	checkpoints[checkpoint] = reached;
}

void GameManager::addRequestById(int id) {
	// Search for matching id
	auto req = find_if(masterRequests.begin(), masterRequests.end(),
		[&](const Request& req) {return req.getId() == id; });
	// Request found - add to board
	if (req != masterRequests.end()) {
		RequestBoard::getInstance().addRequest(*req);
	}
	else {
		cout << "No request found with id: " << id << endl;
	}
}

void GameManager::setMasterRequests() {
	masterRequests.push_back(Request(1, "Sir Henry of the Terra Guard",
		"I have shattered my previous blade in a duel and need to restore my honor.\nI need a blade much stronger than the copper one I once wielded.\n", 100));
	Item thorns("Thorns", 8);
	masterRequests.push_back(Request(2, "Thornweave Tribesman",
		"There's a group of sand serpents that I haven't been able to get past.\nIf I get too close, they start spitting venom at me.\nCould you make me a weapon that I could use to take them out?\n", { &thorns }, 50));
}

void GameManager::stockGeneralStore() {
	
	generalStoreItems = {
		{ironSword, 100},
		{potion, 40},
		{leather, 10}
	};
}

void GameManager::displayGeneralStore() {
	int count = 1;
	cout << "Item                                            Price    Qty" << endl
		<< "------------------------------------------------------------" << endl;
	for (auto it = generalStoreItems.begin(); it != generalStoreItems.end(); ++it) {
		Item* item = it->first;
		int price = it->second;
		cout << left << setw(2) << count << ") " 
			<< left << setw(16) << item->getName() << " - " 
			<< left << setw(24) << item->getDescription() 
			<< right << setw(5) << price << "g" 
			<< right << setw(6) << item->getQuantity() << endl;
		count++;
	}
	cout << "Enter 0 to exit" << endl << endl;
}

void GameManager::completeAristocratRequest() {

}

void GameManager::completeKightRequest() {
	Weapon* weapChoice = nullptr;
	cout << "Select a weapon to give to Sir Henry" << endl
		<< "------------------------------------" << endl;
	weapChoice = player.chooseWeapon();
	string weap = weapChoice->getName();

	// Worst outcome
	if (weapChoice == nullptr) {
		return;
	}
	else if (weap == "Wood Sword" ||
		weap == "Wood Spear" ||
		weap == "Wood Battle Axe" ||
		weap == "Wood Boomerang" ||
		weap == "Wood Bow" ||
		weap == "Wood Arrow" ||
		weap == "Wood Staff" ) {
		cout << "I would be mocked and ridiculed if I showed up with a weapon this poor in quality!" << endl;
		if (weap == "Wood Bow" ||
			weap == "Wood Arrow" ||
			weap == "Wood Staff") {
			cout << "How would this help me in a melee duel?" << endl
				<< "Fighting barehanded would be better than wielding such an atrocity." << endl
				<< "I cannot accept this sad excuse of a weapon." << endl;
			player.updateReputation("Knights", -40);
		}
		else {
			cout << "Fighting barehanded would be better than wielding such an atrocity." << endl
				<< "I cannot accept this sad excuse of a weapon." << endl;
			player.updateReputation("Knights", -30);
		}
		
	}
	// Below Average Outcome
	else if (weap == "Bronze Sword" ||
		weap == "Iron Spear" ||
		weap == "Iron Shuriken" ||
		weap == "Iron Boomerang" ||
		weap == "Steel Bow" ||
		weap == "Iron Arrow" ||
		weap == "Steel Arrow" ||
		weap == "Iron Staff") {
		cout << "I suppose this weapon is serviceable... however this is not what I had in mind." << endl;
		if (weap == "Steel Bow" ||
			weap == "Iron Arrow" ||
			weap == "Steel Arrow" ||
			weap == "Iron Staff" ||
			weap == "Iron Shuriken") {
			cout << "I am unfamiliar with how to use this, but the craftsmanship is up to my standards." << endl
				<< "I will accept this weapon, but God give me a miracle to win with it." << endl;
			player.updateReputation("Knights", -20);
		}
		else {
			cout << "The quality is a bit better than my copper sword, yet it isn't the most suitable weapon." << endl\
				<< "I will accept this weapon, but God give me a miracle to win with it." << endl;
			player.updateReputation("Knights", -10);
		}
	}
	// Average Outcome
	else if (
		weap == "Iron Sword" ||
		weap == "Iron Cutlass" ||
		weap == "Iron Katana" ||
		weap == "Steel Spear" ||
		weap == "Iron Mace" ||
		weap == "Iron Battle Axe" ||
		weap == "Steel Staff" ||
		weap == "Steel Boomerang" ||
		weap == "Soulurite Shuriken" ||
		weap == "Soulurite Boomerang" ||
		weap == "Steel Shuriken" ||
		weap == "Soulurite Arrow") {
		if (
			weap == "Steel Staff" ||
			weap == "Steel Boomerang" ||
			weap == "Steel Shuriken" ||
			weap == "Soulurite Shuriken" ||
			weap == "Soulurite Boomerang" ||
			weap == "Soulurite Arrow") {
			cout << "I'm not sure I can wield this properly, but the quality is very nice." << endl
				<< "This will suffice, I am sure I can make it work to my advantage." << endl
				<< "Thank you." << endl;
			player.updateReputation("Knights", 20);
		}
		else {
			cout << "This is exactly what I was hoping to receive!" << endl
				<< "I am happy to wield this weapon instead of my old copper sword." << endl
				<< "Thank you, Forge Keeper" << endl;
			player.updateReputation("Knights", 30);
		}
	}
	// Above Average Outcome
	else if (
		weap == "Steel Sword" ||
		weap == "Steel Cutlass" ||
		weap == "Steel Katana" ||
		weap == "Steel Battle Axe" ||
		weap == "Steel Mace" ||
		weap == "Soulurite Staff" ){
		cout << "Now this is a weapon worthy of a knight!" << endl
			<< "With this in hand, I shall be an unstoppable force." << endl
			<< "All will tremble before it. Thank you " << player.getName() << endl;
		player.updateReputation("Knights", 50);
	}
	// Best Outcome
	else if (
		weap == "Soulurite Sword" ||
		weap == "Soulurite Spear" ||
		weap == "Soulurite Battle Axe" ||
		weap == "Soulurite Mace") {
		cout << "This weapon is a divine masterpiece!!" << endl
			<< "A weapon of this caliber will restore my honor and make me a legend for ages!" << endl
			<< "I am eternally grateful, " << player.getName() << endl;
		player.updateReputation("Knights", 100);
	}
	// Unknown Weapon Outcome
	else {
		cout << "Is this a joke? I'm not sure you understand the situation I am in." << endl
			<< "This is no weapon for a knight." << endl;
		player.updateReputation("Knights", -50);
	}
}

void GameManager::completeNomadRequest() {

}

void GameManager::completePirateRequest() {


}
void GameManager::completeSamuraiRequest() {

}

void GameManager::completeWizardRequest() {

}
