#pragma once
#include "Battleship.h"
#include "Tile.h"
#include "Ship.h"
#include "Board.h"
#include "iostream"
//test case 1

class Test {
private:

	bool testValidShipPlacement(PlayerBoard* player) {
		bool validPlacement = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (player->get(i, j)->getShip() != nullptr) {
					Ship* ship = player->get(i, j)->getShip();
					if (ship->getLength() <= 0) {
						validPlacement = false;
						break;
					}
				}
			}
		}
		if (validPlacement) {
			return true;
		}
		else {
			return false;
		}
	}

	//test case 2

	bool testFireOnEnemyBoard(EnemyBoard* enemy) {
		int x = 0, y = 0;
		QString result = enemy->fire(x, y);
		if (enemy->get(x, y)->beenHit() && (result == "X" || result == "O" || !result.isEmpty())) {
			return true;
		}
		else {
			return false;
		}
	}

	//test case 3

	bool testGameOver(EnemyBoard* enemy) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (enemy->get(i, j)->getShip() != nullptr) {
					enemy->get(i, j)->setHit(true);
				}
			}
		}
		if (enemy->isGameOver()) {
			return true;
		}
		else {
			return false;
		}
	}
	//test case 4

	bool testAITargetSelection(PlayerBoard* player) {
		player->get(0, 0)->setHit(true);
		QString result = player->fire(1, 1);
		if (!player->get(0, 0)->beenHit() && (result == "X" || result == "O" || !result.isEmpty())) {
			return true;
		}
		else {
			return false;
		}
	}

	//test case 5

	bool testShipHealthUpdates(PlayerBoard* player) {
		int x = 0, y = 0;
		if (player->get(x, y)->getShip() != nullptr) {
			Ship* ship = player->get(x, y)->getShip();
			int initialHealth = ship->getHealth();
			player->fire(x, y);
			if (ship->getHealth() == initialHealth - 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
public:
	void run(PlayerBoard* player, EnemyBoard* enemy) {
		testValidShipPlacement(player);
		testFireOnEnemyBoard(enemy);
		testGameOver(enemy);
		testAITargetSelection(player);
		testShipHealthUpdates(player);
	}
};

