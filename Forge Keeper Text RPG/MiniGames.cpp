#include "MiniGames.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include <atomic>
#include <cstdlib>
#include <ctime>

using namespace std;

void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwSize;
    DWORD dwWritten;
    COORD coord = { 0, 0 };

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', dwSize, coord, &dwWritten);
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
    vector<char> miningBar(barLength, '-');

    for (int i = 0; i < hitSpots; ++i) {
        int hitspot = rand() % barLength;
        miningBar[hitspot] = '#';
    }

    clearConsole();
    cout << "Press Enter to strike with your pickaxe when ^ is on the # spot." << endl;

    int pointerPos = 0;
    atomic<bool> stopPointer(false);
    atomic<bool> inputReceived(false);

    while (hitsLeft > 0) {
        stopPointer = false;
        pointerPos = 0;

        // Thread to move the pointer automatically
        thread pointerThread([&]() {
            while (!stopPointer) {
                clearConsole();
                setCursorPosition(0, 2);

                for (int i = 0; i < barLength; ++i) {
                    cout << miningBar[i];
                }
                cout << endl;
                for (int i = 0; i < barLength; ++i) {
                    if (i == pointerPos) {
                        cout << "^";
                    }
                    else {
                        cout << " ";
                    }
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
            miningBar[lockedPointerPos] = '-';
            hitsLeft--;
        }
        else {
            cout << "Missed!" << endl;
        }

        // Print final state of the mining bar
        for (int i = 0; i < barLength; ++i) {
            cout << miningBar[i] << " ";
        }
        cout << endl;

        pointerPos = 0;
    }

    clearConsole();
    cout << "Mining finished." << endl;
}