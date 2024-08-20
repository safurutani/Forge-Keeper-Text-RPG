#include "Story.h"
using namespace std;
GameManager& gameManager = GameManager::getInstance();
Player& player = Player::getInstance();

void clearConsole() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwSize;
	DWORD dwWritten;
	COORD coord = { 0, 0 };

	// Get the current console screen buffer info
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the line with spaces
	FillConsoleOutputCharacter(hConsole, ' ', dwSize, coord, &dwWritten);

	// Reset cursor to given coordinates
	SetConsoleCursorPosition(hConsole, coord);
}

// Let's user hit enter to print next part of story 
// ALlow specific action too if only one choice
void clickToContinue(string singleOption) {
	cout << endl << "Press [ENTER] to " << singleOption << endl;
	cin.ignore();
	cin.ignore(999, '\n');
}

void introduction(Player& player) {
	int choice;
	cout << endl << "Hello, " << player.getName() << ". I'm Steven Hawthorne, mayor of Embertown." << endl << endl
		<< "I'm so glad that you've arrived! We've been anticipating a new forge keeper for some time now." << endl
		<< "Embertown was the pinnacle of high end tools and weapons for all walks of life." << endl
		<< "Now that you're here, we can restore our reputation!" << endl
		<< "The forge has been collecting cobwebs for so long, and the people are in need of new weapons." << endl
		<< "There's rising tensions... something is surely brewing, but nobody knows quite what." << endl << endl
		<< "Let's head over to the forge." << endl;
	clickToContinue();

	cout << "Here she is in all her glory. I know you'll put her to good use." << endl
		<< "Now before I let you get acquainted with your forge, do you have any questions?" << endl;
	do {
		cout << endl
			<< "1) What happened to the last forge keeper?" << endl
			<< "2) How much do I get paid?" << endl
			<< "3) Why do I have to be the new forge keeper?" << endl
			<< "4) No questions, I'm okay." << endl << endl
			<< "Choice: ";
		cin >> choice;
		cout << endl << "-----------------------------------------------------------------------" << endl;
		switch (choice) {
		case 1:
			cout << endl << "The previous forge keeper was revered and loved by the town." << endl
				<< "One day she simply disappeared. Nobody heard or saw anything." << endl
				<< "There were search parties and everything, but she never turned up." << endl
				<< "While truly unfortunate, we've had to move on." << endl << endl
				<< "Anyway, I'm sure that won't happen to you." << endl;
			clickToContinue();
			break;
		case 2:
			cout << endl << "Straight to business I see. No shame in that." << endl
				<< "Well it is on a per customer basis, so it really depends on you." << endl
				<< "I'm sure you'll be able to negotiate a deal that suits you." << endl;
			clickToContinue();
			break;
		case 3:
			cout << endl << "Look, someone's got to and who better than you?" << endl
				<< "You already have a hammer right there." << endl << endl
				<< "*You take inventory of your backpack*" << endl << endl;
			player.displayInventory();
			cout << endl << "*You pull out a wood hammer poking out of your backpack*" << endl
				<< "*After briefly inspecting it, you give the mayor an unsure look*" << endl
				<< endl << "Just know this is your fate, kid. You'll be great." << endl
				<< "*He pats you on the back with a big grin*" << endl;
			clickToContinue();
			break;
		default:
			break;
		}
	} while (choice != 4);
	cout << endl << "Alright well I'll leave you to it." << endl
		<< "Familiarize yourself with this place then meet me in the town square." << endl;
	clickToContinue();
}

void learnForge() {
	// Acquirable Items
	Item note1("Note #1", "...BEEN SUSPICIOUS OF THEM FOR SOME TIME...\nMOST POWERFUL WEAPON...FRAGMENTED...LOST\nMOON, WIND, E...\n...DREAM... COULD BE CATASTROPHIC");
	Item blueprint("Object Blueprint", "Sandstorm Glass\nIntangible Vine\n3 Falcon Talons\nIce Mirror\nThe One Pearl\n2 Prism Shards\nSoulurite core");
	Weapon woodHammer("Wood Hammer", 1);
	Weapon newHammer("Stone Hammer", 2);

	int choice;
	bool allowNextScene = false;
	cout << endl << "*Dust sits on every flat surface. Cobwebs stretch across each corner*" << endl;
	do {
		cout << endl;
		cout << "1) Examine the forge" << endl
			<< "2) Go to desk" << endl
			<< "3) Look at tool rack" << endl
			<< "4) Check supply cabinet" << endl
			<< "5) Go to town square" << endl << endl
			<< "Choice: ";
		cin >> choice;
		cout << endl << "-----------------------------------------------------------------------" << endl;
		switch (choice) {
		case 1:
			cout << "*An ample supply of charcoal remained in the forge*" << endl
				<< "*The bellows to the left, ready to stoke the fire*" << endl
				<< "*The anvil resided on the right, waiting to be used*" << endl
				<< "\"Looks like I'll need some metal to work with.\"" << endl;
			clickToContinue();
			break;
		case 2:
			int deskOption;
			do {
				cout << "1) Open the drawers" << endl
					<< "2) Check beneath the desk" << endl
					<< "3) Go Back" << endl << endl
					<< "Choice: ";
				cin >> deskOption;
				cout << endl << "-----------------------------------------------------------------------" << endl;
				switch (deskOption) {
				case 1:
					if (!gameManager.checkpoints["Note #1"]) {
						cout << "*Papers were sprawled across the desk - previous commissions perhaps*" << endl
							<< "*You rummage through the various drawers finding various odds and ends*" << endl
							<< "*The bottom of the 3rd drawer seemed to bend downward*" << endl
							<< "*A false bottom lifts up. You reach in and grab the single note hiding*" << endl << endl
							<< "*You try to make sense of the scribbles as best you can*" << endl
							<< endl
							<< "...BEEN SUSPICIOUS OF THEM FOR SOME TIME..." << endl
							<< "MOST POWERFUL WEAPON...FRAGMENTED...LOST" << endl
							<< "MOON, WIND, E..." << endl
							<< "...DREAM... COULD BE CATASTROPHIC" << endl << endl;
						player.addItem(&note1, 1);
						gameManager.updateCheckpoint("Note #1", true);
					}
					else {
						cout << "*Nothing of importance stands out to you*" << endl;
					}
					break;
				case 2:
					if (!gameManager.checkpoints["Unknown object blueprint"]) {
						cout << "*You crouch down and see a cardboard box*" << endl
							<< "*Upon opening it, you find a scroll*" << endl
							<< "*You unravel it to reveal a diagram of an intricate object*" << endl;
						blueprint.getDescription();
						cout << "\"Perhaps this will be important to make.\"" << endl << endl;
						player.addItem(&blueprint, 1);
						gameManager.updateCheckpoint("Unknown object blueprint", true);
					}
					else {
						cout << "*Nothing of importance stands out to you*" << endl;
					}
					break;
				default:
					break;
				}
			} while (deskOption != 3);
			break;
		case 3:
			cout << "*The tool rack looks pretty sparse*" << endl;
			if (!gameManager.checkpoints["Stone Hammer"]) {
				cout << "*All that remained was a stone hammer and some tongs*" << endl
					<< "\"I don't know what I could've done with my wooden hammer.\"" << endl
					<< "\"I suppose I could put this to use.\"" << endl;
				clickToContinue("swap hammers");
				gameManager.updateCheckpoint("Stone hammer", true);

				// Adjust inventory and display new inventory
				player.addItem(&newHammer, 1);
				player.removeItem(&woodHammer, 1);
				player.displayInventory();
			}
			else {
				cout << "*All that remained was a wood hammer and some tongs*" << endl;
			}
			break;
		case 4:
			cout << "*Inside the cabinet there were a couple weapon molds, some nails, and protective gear*" << endl
				<< "*You continue digging around in the back and see several coins laying around*" << endl;
			clickToContinue("pick up the coins");
			player.increaseGold(40);
			cout << endl;
			break;
		case 5:
			if (gameManager.checkpoints["Note #1"] &&
				gameManager.checkpoints["Unknown object blueprint"] &&
				gameManager.checkpoints["Stone hammer"]) {
				allowNextScene = true;
				cout << "\"Alright time to meet Mayor Steven in the town square.\"" << endl;
			}
			else {
				cout << "\"There must be something else I need to do here before leaving.\"" << endl;
			}
			break;
		default:
			break;
		}
	} while (!allowNextScene);
	clickToContinue();
}

void introTownSquare() {
	
	int choice;
	bool allowNextChapter = false;
	cout << "I hope the forge was up to your standards." << endl << endl 
		<< "Now I want to introduce you to the Request Board." << endl 
		<< "The townsfolk will post their ads here and anyone can fulfill them to obtain the listed reward" << endl
		<< "Seems like there's only one at the moment. All sorts of people pass through here during their travels." << endl
		<< "Perhaps now that the forge is up and running again, they'll stay longer and give you their patronage." << endl;
	clickToContinue("look at Request Board");
	RequestBoard& requestBoard = RequestBoard::getInstance();
	requestBoard.getRequests();
	clickToContinue();
	cout << "We also have a resident merchant who can sell you finished goods at the General Store" << endl
		<< "but the raw materials you'll have to source yourself." << endl << endl
		<< "Now I know the materials in the forge are sparse." << endl
		<< "So why don't you head over to either the mines or forest." << endl
		<< "There's bound to be some leftover gear you could use to get started." << endl;
	do {
		cout << endl << "1) Go to mines" << endl
			<< "2) Go to forest" << endl
			<< "3) Visit General Store" << endl 
			<< "4) Return to forge" << endl << endl
			<< "Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			firstMines();
			break;
		case 2:
			firstForest();
			break;
		case 3:
			firstGeneralStore();
			break;
		case 4:
			// need frost mirror
			break;
		default:
			break;
		}
	} while (!allowNextChapter);
		
	
}

void firstMines() {
	Weapon pick("Stone pickaxe", 2);
	int choice;
	cout << "*An uneven path led to a stony opening propped up by wood beams*" << endl
		<< endl << "* Lanterns were hung at intervals *" << endl
		<< endl << "*There was a stone pickaxe propped up against the side of the wall * " << endl;
	clickToContinue("grab pickaxe");
	player.addItem(&pick, 1);
	cout << "\"Only one way to go.\"" << endl
		<< "*You proceed through the mineshaft*" << endl
		<< endl << "*The paths divered up ahead*" << endl;
	do {
		cout << endl << "1) Go left" << endl
			<< "2) Keep going straight" << endl
			<< "3) Go Right" << endl
			<< "4) Leave the mines" << endl << endl
			<< "Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			leftMines();
			break;
		case 2:
			straightMines();
			break;
		case 3:
			rightMines();
			break;
		default:
			break;
		}
	} while (choice != 4);
	cout << "\"That's all I need to do here for now\"" << endl;
}

void leftMines() {
	gameManager.updateCheckpoint("Mines visited", true);
	Item fossils("Fossilized creatures", "These creatures lived long before the mine was ever created");
	int choice1;
	do {
		cout << "*You walk for a good stretch then find a tunnel to the left*" << endl << endl
			<< "1) Keep going straight" << endl
			<< "2) Go left into the tunnel" << endl
			<< "3) Go back" << endl << endl
			<< "Choice: ";
		cin >> choice1;
		switch (choice1) {
		case 1:
			int choice2;
			cout << "*There seems to be a ledge over here*" << endl
				<< "*There is a ladder that could get you down*" << endl
				<< "*You peer over the side and the lanters seem to be very dim at the bottom*" << endl << endl;
			do {
				cout << "1) Go down the ladder" << endl
					<< "2) Go back" << endl << endl
					<< "Choice: ";
				cin >> choice2;
			} while (choice2 != 2);
			switch (choice2) {
			case 1:
				int choice3;
				cout << "*It's dusty and gray*" << endl
					<< "*Off to the side you notice a cluster of fossilized remains embedded in rock*" << endl
					<< "*These creatures lived long before the mine was ever created*" << endl << endl
					<< "1) Take the fossils" << endl
					<< "2) Leave them and continue on" << endl << endl
					<< "Choice: ";
				cin >> choice3;
				if (choice3 == 1) {
					player.addItem(&fossils, 3);
				}
				cout << "*Not wanting to linger, you hurry back up the ladder*" << endl;
				break;
			default:
				break;
			}
			break;
		case 2: 
			int choice4;
			cout << "*The space gets narrower and you see less and less of the wooden support beams" << endl
				<< "*There's the narrowest of openings ahead*" << endl << endl
				<< "1) Keep going straight" << endl
				<< "2) Go Back" << endl << endl
				<< "Choice: ";
			cin >> choice4;
			if (choice4 == 1) {
				cout << "*As you shimmy through the narrowest of openings, you end up in a spacious cavern*" << endl
					<< "*The floor has giant crystal formations with an ethereal glow to them*" << endl
					<< "*The stone pickaxe is no match for them, so all you could do was admire them*" << endl;
				clickToContinue("head back");
			}
			break;
		default: 
			break;
		}
	} while (choice1 != 3);
	

}

void straightMines() {
	gameManager.updateCheckpoint("Mines visited", true);
	int choice5;
	Item code("Code #1", "2-5-7");
	Item batwing("Bat wing");
	Item iron("Iron ore");
	Weapon bronzeSword = Weapon("Bronze sword", 3);
	cout << "*You continue on for some time and are met with another junction*" << endl;
	do {
		cout << endl << "1) Go left" << endl
			<< "2) Keep going straight" << endl
			<< "3) Go Right" << endl << endl
			<< "Choice: ";
		cin >> choice5;
		switch (choice5) {
		case 1:
			cout << "*Ran into a dead end*" << endl
				<< "*As you turn to go back you notice a paper pinned to the wood beam overhead*" << endl;
			clickToContinue("take the paper");
			player.addItem(&code, 1);
			cout << endl << "*It reads*: ";
			code.getDescription();
			cout << endl;
			break;
		case 2:
			int choice6;
			cout << "*There doesn't seem to be any lanters up ahead*" << endl
				<< "*You stare into the darkness*" << endl
				<< "1) Keep going straight" << endl
				<< "2) Turn back" << endl << endl
				<< "Choice: ";
			cin >> choice6;
			if (choice6 == 1) {
				cout << "*Out of nowhere, a frost bat whizzes at you*" << endl;
				// enemy combat minigame
				if (enemyCombat) {
					int choice7;
					cout << "*The bat lay lifeless on the floor*" << endl
						<< "1) Take the bat's wings and continue" << endl
						<< "2) Leave the bat and continue" << endl << endl
						<< "Choice: ";
					cin >> choice7;
					if (choice7 == 1) {
						player.addItem(&batwing, 2);
					}
					cout << "*Reaching out your hands in the dark, you feel the edge of the cave*" << endl
						<< "*You crouch down and pat the ground when you feel something cold and smooth*" << endl;
					clickToContinue("pick up the item");
					player.addItem(&bronzeSword, 1);
				}
			}
			break;
		case 3:
			cout << "*It didn't take long for you to spot a glint in the walls*" << endl
				<< "\"Ah it looks like some iron ore!\"" << endl;
			clickToContinue("mine the ore");
			miningGame(12, 3, 600, iron, 12);
			clickToContinue();
			break;
		default:
			break;
		}
	} while (choice5);
}

void rightMines() {
	gameManager.updateCheckpoint("Mines visited", true);
	Item code("Code #1", "2-5-7");
	int choice8;
	cout << "*There's not much to see so far. That is until...*" << endl
		<< "*You look up and see gold ore sparkling*" << endl
		<< "1) Mine the gold" << endl
		<< "2) Keep going straight" << endl
		<< "3) Go back" << endl << endl
		<< "Choice: ";
	cin >> choice8;
	switch (choice8) {
	case 1:
		miningGame(14, 4, 600, Item("Gold ore"), 6);
		cout << "~Rumble~ ~Rumble~" << endl
			<< "*Gravel rushes down and hits you on the head*" << endl
			<< "*You quickly run back towards the entrance*" << endl;
		player.decreaseHealth(15);
		cout << "*There's only one way to go, now that the gravel has blocked the rest of the tunnel*";
		clickToContinue();
		break;
	case 2:
		int choice9;
		// Check if already failed to open chest - don't allow to reattempt
		if (!gameManager.checkpoints["Mine chest failed"]) {
			cout << "*There is a small box barely peeking out of the dirt*" << endl
				<< "*You uncover it and see that there's a combo lock*" << endl;
			// Give option to refer to code if already obtained
			if (gameManager.checkpoints["Code #1"]) {
				do {
					cout << "1) Consult Clue #1" << endl
						<< "2) Attempt to unlock" << endl
						<< "3) Go back" << endl << endl
						<< "Choice: ";
					cin >> choice9;
					switch (choice9) {
					case 1:
						code.getDescription();
						break;
					case 2:
						unlockChest(257, {}, 75, 3);
						break;
					case 3:
						break;
					default:
						break;
					}
				} while (choice9 != 3);
			}
			else {
				cout << "1) Attempt to unlock" << endl
					<< "2) Go back" << endl << endl
					<< "Choice: ";
				cin >> choice9;
				if (choice9 == 1) {
					unlockChest(257, {}, 75, 3);
				}
			}
		}
		
		break;
	case 3:
		break;
	default:
		break;
	}
}

void firstForest() {
	Weapon axe("Stone axe", 2);
	
	int choice10;
	int treesChopped = 0;
	cout << "*You head over to the forest thick with trees*" << endl
		<< "*A stone axe is lodged into the trunk of an oak tree*" << endl;
	clickToContinue("take the axe");
	player.addItem(&axe, 1);
	do {
		cout << "\"That was lucky find. I'm going to need some wood to make weapons.\"" << endl
			<< "1) Chop tree" << endl
			<< "2) Explore" << endl
			<< "3) Leave the forest" << endl << endl
			<< "Choice: ";
		cin >> choice10;
		switch (choice10) {
		case 1:
			if (treesChopped >= 6) {
				cout << "\"That's enough wood for now, I'll leave the rest of the trees to grow.\"" << endl;
			}
			else {
				chopTreeGame(12, 400, Item("Wood"), 10);
			}
			break;
		case 2:
			int choice11;
			do {
				cout << "1) Follow the path" << endl
					<< "2) Go off the path" << endl
					<< "3) Go back" << endl << endl
					<< "Choice: ";
				cin >> choice11;
				switch (choice11) {
				case 1:
					followPath();
					break;
				case 2:	
					goOffPath();
					break;
				default:
					break;
				}
			} while (choice11 != 3);
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (choice10 != 3);
}

void followPath() {
	gameManager.updateCheckpoint("Forest visited", true);
	int choice13;
	Item wood("Wood");
	Item mirror("Ice Mirror");
	Item leather("Leather");
	Item mushroom("Mushroom");
	Item rope("Rope");
	gnomeInteraction();
	do {
		cout << "*You continue to weave your way through the densely packed forest*" << endl
			<< "*In the distance you spot a dilapidated hut*" << endl
			<< "1) Enter the hut" << endl
			<< "2) Look around the outside of the hut" << endl
			<< "3) Go Back" << endl << endl
			<< "Choice: ";
		cin >> choice13;
		switch (choice13) {
		case 1:
			int choice14;
			int choice15;
			cout << "*You are drawn to the sad looking fireplace*" << endl
				<< "*You put your hands up to it - there's a faint warmth still there*" << endl
				<< "*Off to the side there's a stack of wood*" << endl
				<< "1) Take wood" << endl
				<< "2) Leave wood" << endl << endl
				<< "Choice: ";
			cin >> choice14;
			if (choice14 == 1) {
				player.addItem(&wood, 6);
			}
			cout << "*You turn your gaze towards the table*" << endl
				<< "*There is a piece of paper with a few lines of writing*" << endl;
			clickToContinue("read the paper");
			riddle("I reveal no past, and hold no future,\nYet in the present, I'm your tutor.\nWhat am I, who shows what is real,\nBut never more than what you reveal?", "mirror", "a mirror");
			cout << "*A sparkly sound emits from the oval mirror hanging above the fireplace*" << endl
				<< "*It swings open on its left hinges to reveal something inside*" << endl;
			clickToContinue("get closer");
			cout << "*As you inch closer, you can see a bright, light blue glow*" << endl
				<< "*In the hidden compartment was a frosted handheld mirror*" << endl
				<< "*The icy frame encases the glass but does not overtake it*" << endl
				<< "\"This is definitely the ice mirror from that blueprint!\"" << endl;
			clickToContinue("store the mirror");
			player.addItem(&mirror, 1);

			cout << "*As soon as you stash the mirror, you turn to find someone standing at the door*" << endl << endl
				<< "What are you doing here? I thought only I knew of this little place." << endl;
			clickToContinue("answer");
			cout << "\"I'm the new forge keeper, I was just looking for materials.\"" << endl << endl
				<< "It didn't seem like you were from here. But a forge keeper you say? Do you think you can help me?" << endl;
			clickToContinue("keep listening");
			cout << "You see, I'm from the Thornweave Tribe, but I got left behind." << endl
				<< "I've tried following the direction we were already headed but" << endl
				<< "there's a group of sand serpents that I haven't been able to get past." << endl
				<< "If I get too close, they start spitting venom at me." << endl
				<< "Could you make me a weapon that I could use to take them out?" << endl
				<< "1) Accept" << endl
				<< "2) Ignore" << endl
				<< "3) Refuse" << endl << endl
				<< "Choice: ";
			cin >> choice15;
			switch (choice15) {
			case 1:
				cout << "Thank you! I would be most grateful." << endl;
				if (!gameManager.checkpoints["Firewood taken"]) {
					cout << "I've got some extra wood by the fireplace if you need it." << endl;
					clickToContinue("accept");
					player.addItem(&wood, 6);
					cout << "Oh and I've got some leather on me that you could probably use too!" << endl;
					clickToContinue("accept");
					player.addItem(&leather, 4);
				}
				break;
			case 2:
				cout << "Well I'll put up a request in town in case you change your mind." << endl;
				gameManager.addRequestById(2);
				break;
			case 3:
				cout << "I understand. I wouldn't help some random stranger either." << endl;
				gameManager.updateCheckpoint("Nomad request refused", true);
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "*You scout the perimeter for anything useful*" << endl
				<< "*A couple of pieces of rope were left hanging around a post*" << endl
				<< "*The quality wasn't anything spectacular but it is free*" << endl;
			clickToContinue("take the rope");
			player.addItem(&rope, 2);
			cout << "*Rounding the corner, it was a bit muddy and quite grassy*" << endl
				<< "*Next to a puddle sprouts a cluster of mushrooms*" << endl;
			clickToContinue("take the mushrooms");
			player.addItem(&mushroom, 5);
			cout << "*There didn't seem to be much left around the hut*" << endl;
			break;
		default:
			break;
		}
	} while (choice13 != 3);
}

void goOffPath() {
	gameManager.updateCheckpoint("Forest visited", true);
	bool inCursedClearing = true;
	int choice16;
	int offering;
	Item teeth("Hound Teeth");
	Item steel("Steel");
	cout << "*You meander in what feels like a good direction away from the path*" << endl
		<< "*As you head deeper into the forest, the foliage blocks out more of the sun*" << endl
		<< "*There is an opening ahead, yet it is still dark*" << endl
		<< "*The blackened bark of the circle of dead trees stretch over to form a canopy of dead branches*" << endl;
	clickToContinue();
	do {
		cout << "*In the center there is a stone altar that used to have a rune but has been scratched out*" << endl
			<< "1) Touch the altar" << endl
			<< "2) Make an offering" << endl
			<< "3) Keep exploring" << endl << endl
			<< "Choice: ";
		cin >> choice16;
		switch (choice16) {
		case 1:
			cout << "*You reach out your hand and feel the smooth, cold stone*" << endl
				<< "*You are overtaken by a vision*" << endl
				<< "*You reach out your hand and feel the smooth, cold stone*" << endl
				<< "*You are overtaken by a vision*" << endl;
			clickToContinue();
			cout << "*There is a sharp sound of metal being unsheathed*" << endl
				<< "*The weapon lay dripping in blood with the fiery glow of the forge in the background*" << endl;
			clickToContinue();
			cout << "*Metallic clinking rings in your ears as gold coins fall*" << endl
				<< "*They melt into a singular mass forming some unknown shape*" << endl;
			clickToContinue();
			cout << "*A pulse of bright light emanates from something you can't quite tell what it is*" << endl
				<< "*Hushed chants repeatedly play in your ears *" << endl;
			clickToContinue();
			cout << "*All of the images blur together at once before getting pulled into darkness*" << endl;
			break;
		case 2:
			cout << "What will you offer?" << endl
				<< "1) Health (30hp)" << endl
				<< "2) Gold" << endl
				<< "3) An Item" << endl << endl
				<< "Choice: ";
			cin >> offering;
			altarOffering(offering);
			break;
		case 3:
			inCursedClearing = false;
			break;
		default:
			break;
		}
	} while (inCursedClearing);
	cout << "*You keep going in what you think is the original direction*" << endl
		<< "*A snarl stops you in your tracks*" << endl;
	enemyCombat("SHADOW HOUND", 10, 30);
	player.addItem(&teeth, 6);
	cout << "\"That could've been bad.\"" << endl
		<< "The hound seemed to be guarding something inside this tree." << endl;
	clickToContinue("look in the tree");
	cout << "*A modest pile of gold and 5 steel bars were left*" << endl;
	clickToContinue("take the items");
	player.increaseGold(50);
	player.addItem(&steel, 5);
}

void altarOffering(int offering) {
	Weapon tome("Magical Tome", 6);
	HealingItem potion("Health Potion", 30);
	Item iron("Iron");
	Item steel("Steel");

	int gold;
	bool goldOffered = false;
	int itemSacrifice;
	switch (offering) {
	case 1:
		cout << "*You grab your axe and slash your hand, dripping the blood over the altar*" << endl
			<< "*A path reveals itself and leads you to a hidden cache*" << endl
			<< "*Inside you find a magical tome*" << endl;
		player.addItem(&tome, 1);
		break;
	case 2:
		while (!goldOffered) {
			cout << "How much gold will you offer?" << endl
				<< "You have " << player.getGold() << " gold." << endl << endl
				<< "Gold to sacrifice: ";
			cin >> gold;
			if (gold < 1 || gold > player.getGold()) {
				cout << "Invalid amount";
			}
			else {
				cout << "*You neatly stack the coins on the altar*" << endl
					<< "*Your offer is accepted and the coins vanish before your eyes*" << endl;
				player.decreaseGold(gold);
				if (gold <= 10) {
					player.addItem(&potion, 1);
				}
				else if (gold <= 20) {
					player.addItem(&iron, 4);
				}
				else {
					player.addItem(&steel, 4);
				}
				goldOffered = true;
			}
			
		}
		break;
	case 3:
		player.displayInventory();
		cout << "Choose an item to sacrifice: ";
		cin >> itemSacrifice;
		cout << "*You put the " << player.getInventory()[itemSacrifice - 1]->getName() << " on the stone*" << endl
			<< "*After a moment the item levitates and shakes violently*" << endl
			<< "*You start to see after images of it until it settles*" << endl << endl
			<< "*There are now double of the " << player.getInventory()[itemSacrifice - 1]->getName() << " lying in front of you*" << endl;
		player.addItem(player.getInventory()[itemSacrifice - 1], player.getInventory()[itemSacrifice - 1]->getQuantity());
		player.displayInventory();
		break;
	default:
		break;
	}
}

void gnomeInteraction() {
	int choice12;
	cout << "*You don't get too far down the path until you hear someone repeating, \"Someone? Please? Help!\"*" << endl
		<< "*As the call gets louder you eventually see a gnome trapped in a hole*" << endl
		<< "1) Free the gnome" << endl
		<< "2) Bury the gnome" << endl
		<< "3) Continue on your way" << endl << endl
		<< "Choice: ";
	cin >> choice12;
	switch (choice12) {
	case 1:
		cout << "*You reach into the hole and scoop out the gnome*" << endl
			<< "*He thanks you kindly and slips you a few coins before scurrying away*" << endl;
		player.increaseGold(10);
		clickToContinue();
		break;
	case 2:
		cout << "*A lump of dirt sits off to the side*" << endl
			<< "*You wrap your arms around it and slide it over the hole*" << endl
			<< "*The gnome cries out. Packing the dirt down, the cries became muffled*" << endl;
		clickToContinue();
		break;
	default:
		break;
	}

}

void firstGeneralStore() {
	cout << "*You walk past several townsfolk and into the General Store*" << endl
		<< "It's a pleasure to see a new face in town!" << endl
		<< "My name is Bart and if you play your part, you'll win my heart." << endl
		<< "Just kidding. I'm married, to the mart." << endl
		<< "Take a look at what I sell, when you're ready, ring the bell." << endl;
	clickToContinue("look at the items for sale");
	generalStore();
}

void generalStore() {
	int itemChoice;
	do {
		gameManager.displayGeneralStore();
		cout << "Gold: " << player.getGold() << endl << endl
			<< "What item would you like to purchase?" << endl << endl
			<< "Choice: ";
		cin >> itemChoice;
		purchase(itemChoice - 1);

	} while (itemChoice != 0);
	

}

void purchase(int index) {
	if (index >= gameManager.generalStoreItems.size()) {
		cerr << "Invalid index" << endl;
	}
	auto it = gameManager.generalStoreItems.begin();
	// Moves iterator to given index
	advance(it, index);
	Item* item = it->first;
	int price = it->second;

	// Check store inventory
	if (item->getQuantity() <= 0){
		cout << "Out of stock" << endl;
		gameManager.generalStoreItems.erase(it);
	}
	// Check player's gold
	else if (player.getGold() < price) {
		cout << "Not enough gold" << endl;
	}
	// Go through with purchase
	else {
		player.decreaseGold(price);
		player.addItem(item, 1);
		player.displayInventory();
		item->subtractQuantity(1);
	}
}