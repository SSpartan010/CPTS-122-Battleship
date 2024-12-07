#pragma once

#include "Board.h"
Board::Board() {
	parent = nullptr;
}

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

Tile* PlayerBoard::get(int x, int y) {
	return array[x][y];
}

Tile* EnemyBoard::get(int x, int y) {
	return array[x][y];
}

void PlayerBoard::set(int x, int y, Tile* tile) {
	array[x][y] = dynamic_cast<PlayerTile*>(tile);
}

void EnemyBoard::set(int x, int y, Tile* tile) {
	array[x][y] = dynamic_cast<EnemyTile*>(tile);
}

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