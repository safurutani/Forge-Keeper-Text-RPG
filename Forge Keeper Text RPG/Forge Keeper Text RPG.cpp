#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "GameManager.h"
#include "Story.h"
#include "MiniGames.h"
#include "Recipes.h"

using namespace std;

int main()
{

    string name;

    cout << "*Welcome, Forge Keeper!*\n\n*It is time to start your journey, but first what is your name*: ";
    cin >> name;
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl << endl;


    Player& player = Player::getInstance();
    player.setName(name);
    GameManager& gameManager = GameManager::getInstance();
    gameManager.completeKightRequest();
    //introduction(player);
    //learnForge();
    //introTownSquare();
    //Weapon::forge();

    return 0;
}

