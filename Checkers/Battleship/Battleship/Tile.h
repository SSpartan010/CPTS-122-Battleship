#pragma once

#include "Ship.h"
#include <QPushButton>
#include <QWidget>

class Tile : public QPushButton {
	public:
		Tile();
		Tile(QWidget* parent, bool isPlayerShip);
		Ship* getShip();
		void setShip(Ship* ship);
		bool shipexist(); //check if there is ship at that place
		bool isPlayer();
		void keyPressEvent();
		void validate();
	private:
		Ship* ship;
		bool isPlayerShip;

};