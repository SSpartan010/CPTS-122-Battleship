#pragma once

#include "Tile.h"

Tile::Tile() {
	ship = nullptr;
}

Tile::Tile(QWidget* parent) : QPushButton(parent) {
	ship = nullptr;
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