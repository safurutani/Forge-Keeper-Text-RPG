#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "Location.h"
#include "GameManager.h"
#include "Npc.h"
#include "Story.h"
#include "MiniGames.h"

using namespace std;

int main()
{
    string name;

    cout << "*Welcome, Forge Keeper!*\n\n*It is time to start your journey, but first what is your name*: ";
    cin >> name;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    // Initialize player singleton with provided name
    Player&  player = Player::getInstance(name);
    miningGame(12, Weapon("Stone pickaxe", 3, 100), 600);
    /*
        introduction(player);
        learnForge();
        introTownSquare();
    */
    
    return 0;
}

