#pragma once
#include <string>

enum class ShipType {
	Carrier,	//5
	Battleship,	//4
	Cruiser,	//3
	Submarine,	//3
	Destroyer,	//2
};


class Ship {
	public:
		Ship();
		Ship(int newLength, int newX, int newY, bool direction, bool isPlayerShip);
		int getLength();
		int getX();
		int getY();
		bool getDirection();
	private:
		int length;
		int xCoord;
		int yCoord;
		bool pointRight; // true if points right, false if points down
		std::string name;
};

