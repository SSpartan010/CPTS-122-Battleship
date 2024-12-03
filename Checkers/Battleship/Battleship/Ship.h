#pragma once
#include <string>

class Ship {
	public:
		Ship();
		Ship(int newLength, int newX, int newY, bool direction);
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