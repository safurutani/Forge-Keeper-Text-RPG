#include "Story.h"

using namespace std;

// Let's user hit enter to print next part of story 
void clickToContinue() {
	cout << endl << "Press [ENTER] to continue" << endl;
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void introduction(Player& player) {
	char choice;
	cout << endl << "Hello, " << player.getName() << ". I'm Steven Hawthorne, mayor of this wonderful town." << endl << endl
		<< "I'm so glad that you've arrived! We've been anticipating a new forge keeper for some time now." << endl
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
			<< "3) Why do I have to be forge keeper?" << endl
			<< "4) No questions, I'm okay." << endl << endl
			<< "Choice: ";
		cin >> choice;

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
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (choice != 4);
	cout << "implement forge acquaintance";
	
}