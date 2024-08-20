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
	requestBoard.addRequest(Request(1, "Sir Henry of the Terra Guard",
		"We also have a resident merchant who can sell you finished goods at the General Store, but the raw materials you'll have to source yourself.\n", 100));
	setMasterRequests();

	// Stock the general store
	ironSword = new Weapon("Iron Sword", 5);
	potion = new HealingItem("Health Potion", 30);
	leather = new Item("Leather");
	ironSword->setDescription("sturdy, deals 5 dmg");
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
		"We also have a resident merchant who can sell you finished goods at the General Store, but the raw materials you'll have to source yourself.\n", 100));
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