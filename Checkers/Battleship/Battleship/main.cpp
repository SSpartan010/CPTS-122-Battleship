#pragma once

#include "Battleship.h"
#include "Test.h"
#include <QtWidgets/QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create player and enemy boards for testing
    PlayerBoard* player = new PlayerBoard(nullptr);
    EnemyBoard* enemy = new EnemyBoard(nullptr);

    // Run tests before launching the game
    Test testSuite;
    std::cout << "Running Tests...\n";
    testSuite.run(player, enemy);

    // Launch game
    Battleship w;
    w.show();

    // Clean up memory for test boards
    delete player;
    delete enemy;

    return a.exec();
}
