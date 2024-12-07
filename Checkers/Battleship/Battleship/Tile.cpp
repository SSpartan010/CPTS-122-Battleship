#pragma once

#include "Tile.h"

Tile::Tile() {	//default constructor
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

// gets ship at tile, returns null ptr if doesn't exist
Ship* Tile::getShip() {	
	return ship;
}

// Sets ship at tile to inputted ship
void Tile::setShip(Ship* Ship) {
	this->ship = Ship;
}

// Checks if it is player ship
bool Tile::isPlayer() {
	return isPlayerShip;
}


// gets x coord
int Tile::getX() {
	return x;
}

// gets y coord
int Tile::getY() {
	return y;
}

// Checks if been hit
bool Tile::beenHit() {
	return isHit;
}

// Sets whether hit or not
void Tile::setHit(bool hit) {
	isHit = hit;
}

// Initializes player tile
PlayerTile::PlayerTile() : Tile() {
	isPlayerShip = true;
}

// Initializes player tile based on inputs
PlayerTile::PlayerTile(QWidget* parent, int x, int y) : Tile(parent, true, x, y) {

}

// Initializes enemy tile
EnemyTile::EnemyTile() : Tile() {
	isPlayerShip = false;
}

// Initializes enemy tile based on inputs
EnemyTile::EnemyTile(QWidget* parent, int x, int y) : Tile(parent, false, x, y) {

}
