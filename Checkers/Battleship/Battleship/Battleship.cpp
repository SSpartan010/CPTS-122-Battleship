#include "Battleship.h"

Battleship::Battleship(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setGeometry(0, 0, 1100, 550);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QPushButton* button = new QPushButton("-", this);
            button->setText(".");
            button->setGeometry(50 * i, 10 + 50 * j, 55, 55);
            QPushButton* button2 = new QPushButton(".", this);
            button2->setText("-");
            button2->setGeometry(550 + 50 * i, 10 + 50 * j, 55, 55);
        }
    }
}

Battleship::~Battleship()
{}
