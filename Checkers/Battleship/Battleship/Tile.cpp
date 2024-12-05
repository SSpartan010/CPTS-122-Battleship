#pragma once

#include "Tile.h"

Tile::Tile() {
	ship = nullptr;
}

Tile::Tile(QWidget* parent, bool isPlayerShip) : QPushButton(parent) {
	ship = nullptr;
	this->isPlayerShip = isPlayerShip;
}

bool Tile::shipexist() {
	return ship != nullptr;
}

Ship* Tile::getShip() {
	return ship;
}
void Tile::setShip(Ship* Ship) {
	this->ship = Ship;
}

bool Tile::isPlayer() {
	return isPlayerShip;
}

void Tile::keyPressEvent() {

}
