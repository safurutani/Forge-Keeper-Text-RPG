#include "MiniGames.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include <atomic>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

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

void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, coord);
}

void miningGame(const int barLength, Weapon pickaxe, int speed) {
    cin.ignore(999, '\n');
    srand(static_cast<unsigned>(time(0)));
    int hitSpots = 10 / pickaxe.getDamage();  // Ensure at least one hit spot
    int hitsLeft = hitSpots;
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
    cout << "Press Enter to strike with your pickaxe when ^ is under the # spot." << endl;

    int pointerPos = 0;
    atomic<bool> stopPointer(false);
    atomic<bool> inputReceived(false);

    while (hitsLeft > 0) {
        stopPointer = false;

        // Thread to move the pointer automatically
        thread pointerThread([&]() {
            while (!stopPointer) {
                clearConsole();
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
    cout << "Mining finished." << endl;
}