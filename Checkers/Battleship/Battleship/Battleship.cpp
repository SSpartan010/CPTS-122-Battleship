#include "Battleship.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

Battleship::Battleship(QWidget* parent)     //constructor
	: QMainWindow(parent)
{
	std::srand(std::time(nullptr));
	ui.setupUi(this);
	this->setGeometry(0, 0, 1100, 550);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Tile* button = new Tile(this, true);
			button->setText(".");
			button->setGeometry(50 * i, 10 + 50 * j, 55, 55);
			connect(button, &QPushButton::released, this, &Battleship::handleButton);
			playerBoard[i][j] = button;
			Tile* button2 = new Tile(this, false);
			button2->setText("-");
			button2->setGeometry(550 + 50 * i, 10 + 50 * j, 55, 55);
			connect(button2, &QPushButton::released, this, &Battleship::handleButton);
			enemyBoard[i][j] = button2;
		}
	}
	placeEnemyShips();
	isPlayerTurn = true;
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

void Battleship::handleButton() {
	//QObject* obj = QObject::sender();
	Tile* tile = dynamic_cast<Tile*>(QObject::sender());
	if (tile->isPlayer()) {
		tile->setText("P");
	}
	else {
		tile->setText("E");
	}
}

void Battleship::placeEnemyShips() {
	int shipLength[5] = { 5,4,3,3,2 };
	for (int i = 0; i < 5; i++) {
		Ship* ship = new Ship();
		while (true) {
			int x = rand() % 10;
			int y = rand() % 10;
			bool horizontal = (rand() % 2 == 0);
			int length = shipLength[i];
			bool isValid = true;
			if (horizontal) {
				if (x + length <= 10) {
					for (int j = 0; j < length; j++) {
						if (enemyBoard[x + j][y]->getShip() != nullptr) {
							isValid = false;
							break;
						}
					}
				}
				else {
					isValid = false;
				}
			}
			else {
				if (y + length <= 10) { //for vertical check
					for (int j = 0; j < length; j++) {
						if (enemyBoard[x][y + j]->getShip() != nullptr) {
							isValid = false;
							break;
						}
					}
				}
				else {
					isValid = false;
				}
			}
			if (isValid) {
				if (horizontal) {
					for (int j = 0; j < length; j++) {
						enemyBoard[x + j][y]->setText("S");
						enemyBoard[x + j][y]->setShip(ship);
					}
				}
				else {
					for (int j = 0;j < length;j++) {
						enemyBoard[x][y + j]->setText("S");
						enemyBoard[x][y + j]->setShip(ship);
					}
				}
				break;
			}
		}
	}

}


void Battleship::placePlayerShipsManually() {

}