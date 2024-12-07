#pragma once

#include "Ship.h"
#include <QPushButton>
#include <QWidget>

//base class for tile on board
class Tile : public QPushButton { // inheritance, inherits button to send signal
	public:
		Tile();//constructor
		Tile(QWidget* parent, bool isPlayerShip, int x, int y);	//cosntructor
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

//derived class of tile for player board's tile
class PlayerTile : public Tile {
public:
	PlayerTile();
	PlayerTile(QWidget* parent, int x, int y);
};

//dervied class of tile for enemy board
class EnemyTile : public Tile {
public:
	EnemyTile();
	EnemyTile(QWidget* parent, int x, int y);
};