#include "Battleship.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

Battleship::Battleship(QWidget* parent)     //constructor
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setGeometry(0, 0, 1100, 550);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Tile* button = new Tile(this);
			button->setText(".");
			button->setGeometry(50 * i, 10 + 50 * j, 55, 55);
			playerBoard[i][j] = button;
			Tile* button2 = new Tile(this);
			button2->setText("-");
			button2->setGeometry(550 + 50 * i, 10 + 50 * j, 55, 55);
			enemyBoard[i][j] = button2;
		}
	}
}

Battleship::~Battleship()       //destructor
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			delete playerBoard[i][j];
			delete enemyBoard[i][j];
		}
	}
}

// Fire at tile
void Battleship::fire(Tile* board[10][10], int x, int y) {
    if (board[x][y]->shipexist()) {
        board[x][y]->setText("X"); // Hit
    }
    else {
        board[x][y]->setText("O"); // Miss
    }
}

// Check game over
bool Battleship::isGameOver(Tile* board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j]->shipexist() && board[i][j]->text() != "X") {
                return false;
            }
        }
    }
    return true;

}
