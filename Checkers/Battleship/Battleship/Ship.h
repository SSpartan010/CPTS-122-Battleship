#pragma once
#include <string>
#include <QString>

enum class ShipType {
	Carrier,	//5
	Battleship,	//4
	Destroyer,	//3
	Submarine,	//3
	PatrolBoat,	//2
};


class Ship {
	public:
		Ship();
		Ship(int newLength, int newX, int newY, bool direction, bool isPlayerShip, QString text);
		int getLength();
		int getX();
		int getY();
		void setLength(int newLength);
		void setX(int newX);
		void setY(int newY);
		bool getDirection();
		void setDirection(bool newDirection);
		int getHealth();
		void setHealth(int newHealth);
		QString getText();
		void setText(QString newText);
	private:
		int length;
		int xCoord;
		int yCoord;
		bool horizontal; // true if points right, false if points down
		int health;
		QString text; // the character that the ship will be named (e.g. D for Destroyer)
};

