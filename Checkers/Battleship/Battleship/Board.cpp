#pragma once

// initializes board
#include "Board.h"
Board::Board() {
	parent = nullptr;
}

// initializes player board
PlayerBoard::PlayerBoard(QWidget* parent) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			PlayerTile* button = new PlayerTile(parent, i, j);
			button->setText("-");
			button->setGeometry(50 * i, 10 + 50 * j, 55, 55);
			array[i][j] = button;
		}
	}
	this->parent = parent;
}

// enemy fires at the player board
QString PlayerBoard::fire(int x, int y) {
	if (array[x][y]->shipexist()) {
		array[x][y]->setText("O"); // Hit
		array[x][y]->getShip()->setHealth(array[x][y]->getShip()->getHealth() - 1);
		if (array[x][y]->getShip()->getHealth() == 0) {
			return array[x][y]->getShip()->getText();
		}
	}
	else {
		array[x][y]->setText("X"); // Miss
	}
	return "Miss";
}

// player fires at the enemy board
QString EnemyBoard::fire(int x, int y) {
	if (array[x][y]->shipexist()) {
		Ship* hitShip = array[x][y]->getShip(); // Hit
		array[x][y]->setText(hitShip->getText());
		array[x][y]->getShip()->setHealth(array[x][y]->getShip()->getHealth() - 1);
		if (array[x][y]->getShip()->getHealth() == 0) {
			return array[x][y]->getShip()->getText();
		}
	}
	else {
		array[x][y]->setText("X"); // Miss
	}
	return "Miss";
}

// gets tile at the specified location on player board
Tile* PlayerBoard::get(int x, int y) {
	return array[x][y];
}

// gets tile at the specified location on enemy board
Tile* EnemyBoard::get(int x, int y) {
	return array[x][y];
}

// sets tile at specified location to set tile on player board
void PlayerBoard::set(int x, int y, Tile* tile) {
	array[x][y] = dynamic_cast<PlayerTile*>(tile);
}

// sets tile at specified location to set tile on enemy board
void EnemyBoard::set(int x, int y, Tile* tile) {
	array[x][y] = dynamic_cast<EnemyTile*>(tile);
}

// checks if player has lost
bool PlayerBoard::isGameOver() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (array[i][j]->shipexist() && !array[i][j]->beenHit()) {
				return false;
			}
		}
	}
	return true;
}

// checks if enemy has lost
bool EnemyBoard::isGameOver() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (array[i][j]->shipexist() && !array[i][j]->beenHit()) {
				return false;
			}
		}
	}
	return true;
}

// initializes enemy board
EnemyBoard::EnemyBoard(QWidget* parent) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			EnemyTile* button = new EnemyTile(parent, i, j);
			button->setText("-");
			button->setGeometry(550 + 50 * i, 10 + 50 * j, 55, 55);
			array[i][j] = button;
		}
	}
	this->parent = parent;
}