#pragma once

#include "Ship.h"
#include <QPushButton>
#include <QWidget>

class Tile : public QPushButton {
	public:
		Tile();
		Tile(QWidget* parent);
		Ship* getShip();
		void setShip(Ship* ship);
		bool shipexist(); //check if there is ship at that place

	private:
		Ship* ship;

};