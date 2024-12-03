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
	private:
		Ship* ship;
};