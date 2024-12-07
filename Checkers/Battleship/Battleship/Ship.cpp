#pragma once
#include "Ship.h"
#include <qstring.h>
// default constructor
Ship::Ship() {
	length = 0;
	xCoord = 0;
	yCoord = 0;
	horizontal = false;
	health = 0;
	text = "-";
}

// initializes ship based on inputs
Ship::Ship(int newLength, int newX, int newY, bool direction, bool isPlayerShip, QString newText) {
	length = newLength;
	xCoord = newX;
	yCoord = newY;
	horizontal = direction;
	health = newLength;
	text = newText;
}

// gets ship length
int Ship::getLength() {
	return length;
}

// gets x coord
int Ship::getX() {
	return xCoord;
}

// gets y coord
int Ship::getY() {
	return yCoord;
}

// set ship length
void Ship::setLength(int newLength) {
	length = newLength;
}

// sets x coord
void Ship::setX(int newX) {
	xCoord = newX;
}

// sets y coord
void Ship::setY(int newY) {
	yCoord = newY;
}

// gets ship direction
bool Ship::getDirection() {
	return horizontal;
}

// sets ship direction
void Ship::setDirection(bool newDirection) {
	horizontal = newDirection;
}


// sets ship health
void Ship::setHealth(int newHealth) {
	health = newHealth;
}

// gets ship health
int Ship::getHealth() {
	return health;
}

// gets ship name
QString Ship::getText() {
	return text;
}

// sets ship name
void Ship::setText(QString newText) {
	text = newText;
}
