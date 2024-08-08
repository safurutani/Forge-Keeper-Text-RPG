#include "Location.h"

void gnomeInteraction();
void forestOptions() {
	int choice;
	cout << "1) Explore \n2) Go mining\n3) Gather wood\n4) Go Back" << endl;
	cin >> choice;
	switch (choice) {
		case 1:
			cout << "You trail off the path and see a gnome trapped in a hole." << endl
				<< "What would you like to do?" << endl 
				<< "1) Free the gnome" << endl
				<< "2) Continue on your way" << endl
				<< "3) Bury the gnome" << endl;
			gnomeInteraction();
			break;
		case 2:
			cout << "A well lit cave stands off to the side enshrouded in the dense foliage." << endl
				<< "You enter the cave with pickaxe in hand." << endl;
			mining();
			break;
		case 3:
			cout << "Surrounded by trees, there's limitless options to choose from." << endl
				<< "It's time to get chopping." << endl;
			woodGathering();
			break;
		default:
			break;
	}
}
void mining() {

}
void woodGathering() {

}
void forgeOptions() {

}
void townSquareOptions() {

}
void finalWar() {

}
bool validateInput(string input) {
	return false;
}

void gnomeInteraction() {
	int choice;
	cout << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "You reach into the hole and scoop out the gnome." << endl
			<< "He thanks you kindly and slips you a few coins before scurrying away" << endl;
		break;
	case 2:
		cout << "Continuing down the path, you see a little hut in the clearing.\n1) Enter the hut\n2) Look around the outside of the hut\n3) Keep exploring" << endl;
		break;
	case 3:
		cout << "A lump of dirt sits off to the side." << endl
			<< "You wrap your arms around it and slide it over the hole." << endl
			<< "The gnome cries out.\nPacking the dirt down, the cries became muffled and you went on your way." << endl
			<< "Later down the path a wizard calls you over." << endl;
		break;
	default:
		break;
	}
	
}