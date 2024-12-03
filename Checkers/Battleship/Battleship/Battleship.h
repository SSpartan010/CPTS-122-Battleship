#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Battleship.h"
#include "Ship.h"
#include <QPushButton>
#include "Tile.h"

class Battleship : public QMainWindow
{
    Q_OBJECT

public:
    Battleship(QWidget *parent = nullptr);
    ~Battleship();

private:
    Ui::BattleshipClass ui;
    Tile* playerBoard[10][10];
    Tile* enemyBoard[10][10];
};
