#pragma once

#include "Battleship.h"

// initializes battleship
Battleship::Battleship(QWidget* parent)     //constructor
	: QMainWindow(parent)
{
	std::srand(std::time(nullptr));
	ui.setupUi(this);
	this->setGeometry(0, 0, 1100, 650);	//set window size
	//make board
	enemy = new EnemyBoard(this);
	player = new PlayerBoard(this);
	
	//connect tile and with handle button
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			connect(player->get(i, j), &QPushButton::released, this, &Battleship::handleButton);
			connect(enemy->get(i, j), &QPushButton::released, this, &Battleship::handleButton);
		}
	}
	placeEnemyShips();
	isPlayerTurn = true;
	//making text section to show instruction and information 
	text = new QLineEdit(this);
	text->setText("Choose a player square");
	text->setReadOnly(true);
	text->move(550, 550);
	text->setFixedWidth(500);
	text->setFont(QFont("Arial", 20));
	//make player's ship
	shipsAdded = 0;
	playerShips[0] = new Ship(5, 0, 0, true, true, "C");	//carrier
	playerShips[1] = new Ship(4, 0, 0, true, true, "B");	//battleship
	playerShips[2] = new Ship(3, 0, 0, true, true, "D");	//Crusier
	playerShips[3] = new Ship(3, 0, 0, true, true, "S");	//submarine
	playerShips[4] = new Ship(2, 0, 0, true, true, "P");	//destroyer
}

// destructor
Battleship::~Battleship()       //destructor
{
	delete player;
	delete enemy;
}

// handles button signal
void Battleship::handleButton() {
	if (shipsAdded < 5) {	//if all ship wasn't placed
		if (dynamic_cast<Tile*>(QObject::sender())->isPlayer()) {//if tile is clicked
			if (click1 == nullptr) {	//if first click is null
				click1 = dynamic_cast<Tile*>(QObject::sender());
				text->setText("Ship starting at " + QString::number(click1->getX()) + ", " + QString::number(click1->getY()));
			}
			else {//second click will determine the direction and end
				click2 = dynamic_cast<Tile*>(QObject::sender());
				//ship placement vertical 
				//up
				if (click1->getX() == click2->getX() && click1->getY() > click2->getY()) {
					if (click1->getY() - playerShips[shipsAdded]->getLength() >= -1) {
						bool validPlace = true;
						//check fo validspace(No ship in selected area)
						for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
							if (player->get(click1->getX(), click1->getY() - i)->getShip() != nullptr) {
								validPlace = false;
							}
						}
						//if so, place	
						if (validPlace) {
							for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
								player->get(click1->getX(),click1->getY() - i)->setShip(playerShips[shipsAdded]);
								player->get(click1->getX(),click1->getY() - i)->setText(playerShips[shipsAdded]->getText());
							}
							shipsAdded++;
							text->setText("Ship placed");
							if (shipsAdded >= 5) {
								text->setText("All ships placed, player turn");
							}
						}
						else {
							text->setText("Invalid placement, try again");
						}
					}
					else {
						text->setText("Invalid placement, try again");
					}
				}
				//down
				else if (click1->getX() == click2->getX() && click1->getY() < click2->getY()) {
					if (click1->getY() + playerShips[shipsAdded]->getLength() < 11) {
						bool validPlace = true;
						for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
							if (player->get(click1->getX(),click1->getY() + i)->getShip() != nullptr) {
								validPlace = false;
							}
						}
						if (validPlace) {
							for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
								player->get(click1->getX(),click1->getY() + i)->setShip(playerShips[shipsAdded]);
								player->get(click1->getX(),click1->getY() + i)->setText(playerShips[shipsAdded]->getText());
							}
							shipsAdded++;
							text->setText("Ship placed");
							if (shipsAdded >= 5) {
								text->setText("All ships placed, player turn");
							}
						}
						else {
							text->setText("Invalid placement, try again");
						}
					}
					else {
						text->setText("Invalid placement, try again");
					}
				}
				//Ship Placement Horizontal
				//left
				else if (click1->getY() == click2->getY() && click1->getX() > click2->getX()) {
					if (click1->getX() - playerShips[shipsAdded]->getLength() >= -1) {
						bool validPlace = true;
						for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
							if (player->get(click1->getX() - i,click1->getY())->getShip() != nullptr) {
								validPlace = false;
							}
						}
						if (validPlace) {
							for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
								player->get(click1->getX() - i,click1->getY())->setShip(playerShips[shipsAdded]);
								player->get(click1->getX() - i,click1->getY())->setText(playerShips[shipsAdded]->getText());
							}
							shipsAdded++;
							text->setText("Ship placed");
							if (shipsAdded >= 5) {
								text->setText("All ships placed, player turn");
							}
						}
						else {
							text->setText("Invalid placement, try again");
						}
					}
					else {
						text->setText("Invalid placement, try again");
					}
				}
				//right
				else if (click1->getY() == click2->getY() && click1->getX() < click2->getX()) {
					if (click1->getX() + playerShips[shipsAdded]->getLength() < 11) {
						bool validPlace = true;
						for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
							if (player->get(click1->getX() + i,click1->getY())->getShip() != nullptr) {
								validPlace = false;
							}
						}
						if (validPlace) {
							for (int i = 0; i < playerShips[shipsAdded]->getLength(); i++) {
								player->get(click1->getX() + i,click1->getY())->setShip(playerShips[shipsAdded]);
								player->get(click1->getX() + i,click1->getY())->setText(playerShips[shipsAdded]->getText());
							}
							shipsAdded++;
							text->setText("Ship placed");
							if (shipsAdded >= 5) {
								text->setText("All ships placed, player turn");
							}
						}
						else {
							text->setText("Invalid placement, try again");
						}
					}
					else {
						text->setText("Invalid placement, try again");
					}
				}
				else {
					text->setText("Invalid placement, try again");
				}
				click1 = nullptr;//reset click for other ship
				click2 = nullptr;
			}
		}
		else {
			text->setText("Choose your own tile");
		}

	}
	//handle turns
	else {
		//QObject* obj = QObject::sender();
		Tile* tile = dynamic_cast<Tile*>(QObject::sender());
		if (!tile->isPlayer() && isPlayerTurn) {
			int x = tile->getX();
			int y = tile->getY();

			if (tile->beenHit()) {//check if it was hit already
				text->setText("Already hit. Choose another.");
				return;
			}
			QString temp = enemy->fire(x, y);//fire enemy
			if (temp == "C") {
				text->setText("Enemy Carrier destroyed");
			}
			else if (temp == "B") {
				text->setText("Enemy Battleship destroyed");
			}
			else if (temp == "D") {
				text->setText("Enemy Destroyer destroyed");
			}
			else if (temp == "S") {
				text->setText("Enemy Submarine destroyed");
			}
			else if (temp == "P"){
				text->setText("Enemy Patrol Boat destroyed");
			}
			//fire(enemyBoard, x, y);
			tile->setHit(true);//mark tile as hit
			if (enemy->isGameOver()) {	//check it game is over
				text->setText("Player Wins!");
				return;
			}

			isPlayerTurn = false;
			//text->setText("Enemy Turn");
			enemyTurn();//if not done, enemy turn
		}
	}


}

// enemy turn
void Battleship::enemyTurn() {
	int x = 0;
	int y = 0;
	/*
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (playerBoard[x][y]->beenHit());
	*/
	
	//check adjacent tile for smart ai movement
	bool adjacent = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (player->get(i,j)->beenHit() && player->get(i, j)->getShip() != nullptr && player->get(i, j)->getShip()->getHealth() > 0 && !adjacent) {
				if (i - 1 >= 0 && !player->get(i - 1,j)->beenHit()) {
					x = i - 1;
					y = j;
					adjacent = true;
				}
				else if (i + 1 < 10 && !player->get(i + 1, j)->beenHit()) {
					x = i + 1;
					y = j;
					adjacent = true;
				}
				else if (j - 1 >= 0 && !player->get(i, j - 1)->beenHit()) {
					x = i;
					y = j - 1;
					adjacent = true;
				}
				else if (j + 1 < 10 && !player->get(i, j + 1)->beenHit()) {
					x = i;
					y = j + 1;
					adjacent = true;
				}
			}
		}
	}
	//if not, random choose
	if (!adjacent) {
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (player->get(x, y)->beenHit());
	}
	
	QString temp = player->fire(x, y);
	if (temp == "C") {
		text->setText("Player Carrier destroyed");
	}
	else if (temp == "B") {
		text->setText("Player Battleship destroyed");
	}
	else if (temp == "D") {
		text->setText("Player Destroyer destroyed");
	}
	else if (temp == "S") {
		text->setText("Player Submarine destroyed");
	}
	else if (temp == "P") {
		text->setText("Player Patrol Boat destroyed");
	}
	//fire(playerBoard, x, y);
	player->get(x, y)->setHit(true);
	//playerBoard[x][y]->setHit(true);

	if (player->isGameOver()) {
		text->setText("You Lose");
		return;
	}
	isPlayerTurn = true;
	//text->setText("Player Turn");
	
}


// places enemy ships
void Battleship::placeEnemyShips() {//ranodomly generate enemy ship
	for (int i = 0; i < 5; i++) {//5ships in total
		Ship* ship = new Ship();
		enemyShips[i] = ship;
		if (i == 0) {
			ship->setLength(5);
			ship->setHealth(5);
			ship->setText("C");
		}
		else if (i == 1) {
			ship->setLength(4);
			ship->setHealth(4);
			ship->setText("B");

		}
		else if (i == 2) {
			ship->setLength(3);
			ship->setHealth(3);
			ship->setText("D");

		}
		else if (i == 3) {
			ship->setLength(3);
			ship->setHealth(3);
			ship->setText("S");

		}
		else {
			ship->setLength(2);
			ship->setHealth(2);
			ship->setText("P");

		}
		while (true) {
			//generate random number
			int x = rand() % 10;
			int y = rand() % 10;
			bool horizontal = (rand() % 2 == 0);
			bool isValid = true;
			//generate random direcntion
			if (horizontal) {
				if (x + ship->getLength() - 1 < 10) {
					for (int j = 0; j < ship->getLength(); j++) {
						if (enemy->get(x + j, y)->getShip() != nullptr) {
							isValid = false;
						}
					}
					if (isValid) {
						enemyShips[i] = ship;
						for (int j = 0; j < ship->getLength(); j++) {
							enemy->get(x + j, y)->setText("-");
							enemy->get(x + j, y)->setShip(ship);
						}
						break;
					}
				}
			}
			else {
				if (y + ship->getLength() - 1 < 10) {
					for (int j = 0; j < ship->getLength(); j++) {
						if (enemy->get(x, y + j)->getShip() != nullptr) {
							isValid = false;
						}
					}
					if (isValid) {
						for (int j = 0; j < ship->getLength(); j++) {
							enemy->get(x, y + j)->setText("-");
							enemy->get(x, y + j)->setShip(ship);
						}
						break;
					}
				}
			}
		}
	}
}

