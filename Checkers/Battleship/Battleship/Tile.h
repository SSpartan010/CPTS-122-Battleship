#pragma once

#include "Ship.h"
#include <QPushButton>


class Tile : public QPushButton {
	public:
		Tile();
		Ship* getShip();

	private:
		Ship* ship;
};