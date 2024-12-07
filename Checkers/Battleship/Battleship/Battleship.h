#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Battleship.h"
#include "Ship.h"
#include <QPushButton>
#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QLineEdit>
#include <QLabel>
#include "Board.h"

class Battleship : public QMainWindow
{
	Q_OBJECT

public:
	Battleship(QWidget* parent = nullptr);	//constructor
	~Battleship();	//destructor

private slots:
	void handleButton();	//manually place ship on playerboard. After placement is finished, game starts. 
private:
	Ui::BattleshipClass ui;

	PlayerBoard* player;	//playerboard
	EnemyBoard* enemy;	//enemyboard
	Ship* playerShips[5];
	Ship* enemyShips[5];
	Tile* click1;	//first click for tile
	Tile* click2;	
	bool isPlayerTurn;	//will track who's turn
	int shipsAdded;

	//void fire(PlayerTile* board[10][10], int x, int y);	//fire opponent ship
	//void fire(EnemyTile* board[10][10], int x, int y);	//fire opponent ship
	bool isGameOver(Tile** board[10][10]);	//checks game over
	void placeEnemyShips();	//randomly generate ship placement for enemy(computer)
	void enemyTurn();	/*Called in handlebutton to take turns playing with player.
							make movement(fire and hit/miss) by random.(Strategy used so if hit, try button next to the button that was hit*/
	QLineEdit* text;
};
