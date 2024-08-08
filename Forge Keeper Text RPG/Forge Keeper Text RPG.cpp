#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "Location.h"
#include "GameManager.h"
#include "Npc.h"
#include "Story.h"

using namespace std;

int main()
{
    int selection;
    string name;
    do {
        cout << "Welcome, Forge Keeper! \n\nIt is time to start your journey, but first what is your name: ";
        cin >> name;
        cout << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------" << endl;

        // Initialize player singleton with provided name
        Player&  player = Player::getInstance(name);

        introduction(player);

        cin >> selection;
        switch (selection) {
        case 1:
            forgeOptions();
            break;
        case 2:
            townSquareOptions();
            break;
        case 3:
            forestOptions();
            break;
        }
    } while (selection != '99');

    return 0;
}

