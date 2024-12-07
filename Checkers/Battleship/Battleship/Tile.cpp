#pragma once

#include "Tile.h"

Tile::Tile() {	//default cosntructor
	ship = nullptr;
	x = 0;
	y = 0;
	isHit = false;
	isPlayerShip = true;
}

Tile::Tile(QWidget* parent, bool isPlayerShip, int x, int y) : QPushButton(parent) {	//cosntructor with initialization
	ship = nullptr;
	this->isPlayerShip = isPlayerShip;
	this->x = x;
	this->y = y;
	isHit = false;
}

//check if ship exist already
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

int Tile::getX() {
	return x;
}

int Tile::getY() {
	return y;
}

bool Tile::beenHit() {
	return isHit;
}

void Tile::setHit(bool hit) {
	isHit = hit;
}

PlayerTile::PlayerTile() : Tile() {
	isPlayerShip = true;
}

PlayerTile::PlayerTile(QWidget* parent, int x, int y) : Tile(parent, true, x, y) {

}

EnemyTile::EnemyTile() : Tile() {
	isPlayerShip = false;
}

EnemyTile::EnemyTile(QWidget* parent, int x, int y) : Tile(parent, false, x, y) {

}
