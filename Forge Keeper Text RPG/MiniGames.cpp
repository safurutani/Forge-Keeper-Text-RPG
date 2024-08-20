#include "MiniGames.h"

using namespace std;
extern Player& player;
extern GameManager& gameManager;
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, coord);
}

string lowercase(string str) {
    string newstr;
    for (char c : str) {
        newstr += tolower(c);
    }
    return newstr;
}

void miningGame(const int barLength, int spots, int speed, Item ore, int amount ) {
    cin.ignore(999, '\n');
    srand(static_cast<unsigned>(time(0)));
    int hitSpots = spots;
    int hitsLeft = spots;
    int hitSpot;
    vector<char> miningBar(barLength, '-');

    // Use unordered set for storing unique values only
    unordered_set<int> uniqueHitSpots;

    // Keep generating random numbers until the set is full
    while(uniqueHitSpots.size() < hitSpots) {
        hitSpot = rand() % barLength;
        uniqueHitSpots.insert(hitSpot);
    }

    // Fill the mining bar with the hit spots (#)
    for (int pos : uniqueHitSpots) {
        miningBar[pos] = '#';
    }
    clearConsole();

    int pointerPos = 0;
    atomic<bool> stopPointer(false);
    atomic<bool> inputReceived(false);

    while (hitsLeft > 0) {
        stopPointer = false;

        // Thread to move the pointer automatically
        thread pointerThread([&]() {
            while (!stopPointer) {
                clearConsole();
                cout << "Press [Enter] to strike with your \npickaxe when V is over the # spot." << endl;
                setCursorPosition(0, 2);

                for (int i = 0; i < barLength; ++i) {
                    if (i == pointerPos) {
                        cout << "V";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
                for (int i = 0; i < barLength; ++i) {
                    cout << miningBar[i];
                }
                
                
                cout.flush();

                this_thread::sleep_for(chrono::milliseconds(speed));
                pointerPos = (pointerPos + 1) % barLength;
                if (inputReceived) {
                    stopPointer = true;
                    break;
                }
            }
            });

        // Wait for user's input
        cin.ignore();

        stopPointer = true; // Stop the pointer movement

        // Stores exact pos of pointer when use hit enter
        int lockedPointerPos = pointerPos;

        // Wait for the pointer thread to finish
        if (pointerThread.joinable()) {
            pointerThread.join();
        }

        // Check if the pointer is on a hit spot
        if (miningBar[lockedPointerPos] == '#') {
            cout << "Perfect strike!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            miningBar[lockedPointerPos] = '-';
            hitsLeft--;
        }
        else {
            cout << "Missed!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        // Print final state of the mining bar
        for (int i = 0; i < barLength; ++i) {
            cout << miningBar[i] << " ";
        }
        cout << endl;
    }
    
    clearConsole();
    cout << "Mining finished." << endl << endl;
    player.addItem(&ore, amount);
}
void chopTreeGame(int height, int speed, Item wood, int amount) {
    cin.ignore(999, '\n');
    srand(static_cast<unsigned>(time(0)));
    int hitSpots = 1;
    int hitsLeft = 5;
    int hitSpot;

    vector<char> choppingBar(height, '|');
    hitSpot = rand() % 4;
    choppingBar[hitSpot] = 'C';

    clearConsole();

    int pointerPos = 0;
    atomic<bool> stopPointer(false);
    atomic<bool> inputReceived(false);

    while (hitsLeft > 0) {
        stopPointer = false;

        // Thread to move the pointer automatically
        thread pointerThread([&]() {
            while (!stopPointer) {
                clearConsole();
                cout << "Press [Enter] to strike with your \naxe when < is at the C." << endl;
                setCursorPosition(0, 2);

                for (int i = height - 1; i >= 0; --i) {
                    if (i == pointerPos) {
                        cout << choppingBar[i] << "<" << endl;
                    }
                    else {
                        cout << choppingBar[i] << endl;
                    }
                }


                cout.flush();

                this_thread::sleep_for(chrono::milliseconds(speed));
                pointerPos = (pointerPos + 1) % height;
                if (inputReceived) {
                    stopPointer = true;
                    break;
                }
            }
            });

        // Wait for user's input
        cin.ignore();

        stopPointer = true; // Stop the pointer movement

        // Stores exact pos of pointer when use hit enter
        int lockedPointerPos = pointerPos;

        // Wait for the pointer thread to finish
        if (pointerThread.joinable()) {
            pointerThread.join();
        }
        
        // Check if the pointer is on a hit spot
        if (choppingBar[lockedPointerPos] == 'C') {
            cout << "Perfect strike!" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            hitsLeft--;
        }
        else {
            cout << "Missed!" << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
        }

        // Print final state of the mining bar
        for (int i = height - 1; i >= 0; --i) {
            cout << choppingBar[i] << endl;
        }
        cout << endl;
    }

    clearConsole();
    cout << "Chopping finished." << endl << endl;
    int bonus = rand() % 3;
    player.addItem(&wood, amount + bonus);
}
bool unlockChest(int code, vector<Item*> reward, int gold, int attempts) {
    int tries = attempts;
    int digits;
    do {
        cout << "Attempts: " << tries << endl;
        cout << "Enter 3 digits: ";
        cin >> digits;
        if (digits == code) {
            cout << "Chest unlocked!" << endl;
            for (Item* i : reward) {
                player.addItem(i, 1);
            }
            player.increaseGold(75);
            return true;
        }
        else {
            cout << "Wrong combo" << endl;
        }
    } while (digits != code && attempts != 0);

    gameManager.updateCheckpoint("Mine chest failed", true);
    return false;
}

void riddle(string riddle, string answer, string answer2) {
    string userInput;
    string prompt = "Answer: ";
    cout << riddle << endl << endl;
    do {
        cout << '\r' << prompt;
        cout.flush();
        
        getline(cin, userInput);

        if (lowercase(userInput) != answer && lowercase(userInput) != answer2 && userInput != "") {
            
            cout << userInput << " is incorrect. Please try again." << endl;
            cout << '\r' << string(100, ' ') << '\r' << prompt;
            
        }
    } while (lowercase(userInput) != answer && lowercase(userInput) != answer2);
    cout << "Riddle successfully solved!" << endl;
}

bool enemyCombat(string name, int dmg, int hp) {
    int enemyHealth = hp;
    int num = 1;
    int choice;
    int healChoice;
    vector<Weapon*> weapList;

    Weapon* weapChoice;
    cout << endl << name << " ENCOUNTER" << endl
        << string(name.size() + 10, '-') << endl;

    // List weapons to choose from
    for (Item* item : player.getInventory()) {
        // Attempt dynamic cast of item into a weapon
        Weapon* weap = dynamic_cast<Weapon*>(item);
        // Weap will be non null
        if (weap) {
            cout << num << ") " << left << setw(20) << weap->getName() 
                << "    " << "Dmg: " << weap->getDamage() << endl;
            weapList.push_back(weap);
            num++;
        }
    }
    cout << "Choose a weapon: ";
    cin >> choice;
    weapChoice = weapList.at(choice - 1);
    do {
        int action;
        bool turnOver = false;
        clearConsole();
        // Display enemy and player names/health
        cout << left << setw(20) << name << setw(20) << player.getName() << endl
            << "Health: " << enemyHealth << "/" << hp << "       "
            << "Health: " << player.getHealth() << "/100" << endl << endl;
        // Waits for player to either attack or flee - healing does not use up a turn
        do {
            cout << "1) Attack" << endl
                << "2) Heal" << endl
                << "3) Flee" << endl << endl
                << "Choice: ";
            cin >> action;
            switch (action) {
            case 1:
                cout << "*Your " << weapChoice->getName() << " does " << weapChoice->getDamage()
                    << " damage to the " << name << "*" << endl;
                enemyHealth -= weapChoice->getDamage();
                turnOver = true;
                break;
            case 2: {
                vector<HealingItem*> healingItems;
                if (player.getHealth() == 100) {
                    cout << "*Your health is already full*" << endl;
                }
                else {
                    // Reset from when choosing weapon
                    num = 1;
                    // Check for healing items in inventory
                    for (Item* item : player.getInventory()) {
                        // Attempt dynamic cast of item into a healing item - success means hItem will be non null
                        HealingItem* hItem = dynamic_cast<HealingItem*>(item);
                        if (hItem) {
                            cout << num << ") " << left << setw(20) << hItem->getName() 
                                << "    " << "Recovers: " << hItem->getHeal() << " hp" 
                                << "    " << "Qty: " << hItem->getQuantity() << endl;
                            healingItems.push_back(hItem);
                            num++;
                        }
                    }
                    if (healingItems.size() == 0) {
                        cout << endl << "*You do not have any healing items*" << endl;
                    }
                    else {
                        HealingItem* hItem;
                        cout << endl << "Choice: ";
                        cin >> healChoice;
                        hItem = healingItems.at(healChoice - 1);

                        // Heal the designated amount and remove from inventory
                        player.increaseHealth(hItem->getHeal());
                        player.removeItem(hItem, 1);

                        // Reset the list of healing items
                        healingItems.clear();
                    }
                }
                
                break;
            }
            case 3:
                cout << "*You retreat in a cowardly fashion and get away before any more harm could befall you*" << endl;
                return false;
            default:
                break;
            }
        } while (!turnOver);
        
        // Enemy still alive, continue loop
        if (enemyHealth > 0) {
            cout << endl << "*" << name << " attacks and does " << dmg << " damage to you*" << endl;
            player.decreaseHealth(dmg);
            clickToContinue();
        }
        else {
            cout << "*" << name << " lost all its health*" << endl
                << "*You sucessfully defeated the " << name << "!*" << endl;
            return true;
        }
    } while (player.getHealth() > 0 && enemyHealth > 0);
    // Player died, failed the combat
    ////////////////////////////////////////
    // Add inventory loss or gold penalty //
    ////////////////////////////////////////
    cout << "*The " << name << " has bested you. You died*" << endl;
    return false;
}

