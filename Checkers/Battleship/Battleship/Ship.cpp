#pragma once

#include "Ship.h"

Ship::Ship() {
	length = 0;
	xCoord = 0;
	yCoord = 0;
	pointRight = false;
}

Ship::Ship(int newLength, int newX, int newY, bool direction, bool isPlayerShip) {
	length = newLength;
	xCoord = newX;
	yCoord = newY;
	pointRight = direction;
}

int Ship::getLength() {
	return length;
}

int Ship::getX() {
	return xCoord;
}

int Ship::getY() {
	return yCoord;
}

bool Ship::getDirection() {
	return pointRight;
}