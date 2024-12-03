#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Battleship.h"

class Battleship : public QMainWindow
{
    Q_OBJECT

public:
    Battleship(QWidget *parent = nullptr);
    ~Battleship();

private:
    Ui::BattleshipClass ui;
};
