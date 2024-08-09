#include "Story.h"

using namespace std;

// Let's user hit enter to print next part of story 
// ALlow specific action too if only one choice
void clickToContinue(string singleOption) {
	cout << endl << "Press [ENTER] to " << singleOption << endl;
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	GameManager& gameManager = GameManager::getInstance();
	Player& player = Player::getInstance();

	// Acquirable Items
	Item note1 = Item("Note #1", "...BEEN SUSPICIOUS OF THEM FOR SOME TIME...\nMOST POWERFUL WEAPON...FRAGMENTED...LOST\nMOON, WIND, E...\n...DREAM... COULD BE CATASTROPHIC");
	Item blueprint = Item("Object Blueprint", "Sandstorm Glass\nIntangible Vine\n3 Falcon Talons\nIce Mirror\nThe One Pearl\n2 Prism Shards\nSoulurite core");
	Item woodHammer = Item("Wood Hammer");
	Item newHammer = Item("Stone Hammer");

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

}