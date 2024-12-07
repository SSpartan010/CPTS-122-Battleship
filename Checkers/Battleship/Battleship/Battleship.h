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

class Battleship : public QMainWindow
{
	Q_OBJECT

public:
	Battleship(QWidget* parent = nullptr);
	~Battleship();

private slots:
	void handleButton();
private:
	Ui::BattleshipClass ui;


	PlayerTile* playerBoard[10][10];
	EnemyTile* enemyBoard[10][10];
	Ship* playerShips[5];
	Ship* enemyShips[5];
	Tile* click1;
	Tile* click2;
	bool isPlayerTurn;
	int shipsAdded;

	void fire(PlayerTile* board[10][10], int x, int y);	//fire opponent ship
	void fire(EnemyTile* board[10][10], int x, int y);	//fire opponent ship
	bool isGameOver(PlayerTile* board[10][10]);	//checks game over
	bool isGameOver(EnemyTile* board[10][10]);
	void placeEnemyShips();
	void enemyTurn();
	QLineEdit* text;
};
