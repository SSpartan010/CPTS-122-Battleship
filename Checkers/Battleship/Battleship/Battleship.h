#pragma once

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include "ui_Battleship.h"
#include "Ship.h"
#include <QPushButton>
#include "Tile.h"

class Battleship : public QMainWindow
{
	Q_OBJECT

public:
	Battleship(QWidget* parent = nullptr);
	~Battleship();

private:
	Ui::BattleshipClass ui;
	Tile* playerBoard[10][10];
	Tile* enemyBoard[10][10];

	void fire(Tile* board[10][10], int x, int y);	//fire opponent ship
	bool isGameOver(Tile* board[10][10]);	//checks game over
	void placeship(Tile* board[10][10], Ship* ship); //place ship



};
