#pragma once

#include "Ship.h"
#include <QPushButton>
#include <QWidget>

class Tile : public QPushButton { // inheritance, inherits button to send signal
	public:
		Tile();
		Tile(QWidget* parent, bool isPlayerShip, int x, int y);
		Ship* getShip();
		void setShip(Ship* ship);
		bool shipexist(); //check if there is ship at that place
		bool isPlayer();
		void validate();
		int getX();
		int getY();
		bool beenHit();
		void setHit(bool hit);
	protected:
		Ship* ship;
		bool isPlayerShip;
		int x;
		int y;
		bool isHit;
};

class PlayerTile : public Tile {
public:
	PlayerTile();
	PlayerTile(QWidget* parent, int x, int y);
};

class EnemyTile : public Tile {
public:
	EnemyTile();
	EnemyTile(QWidget* parent, int x, int y);
};