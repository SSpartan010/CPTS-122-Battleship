#include "Battleship.h"

Battleship::Battleship(QWidget* parent)     //constructor
	: QMainWindow(parent)
{
	std::srand(std::time(nullptr));
	ui.setupUi(this);
	this->setGeometry(0, 0, 1100, 650);
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
	text = new QLineEdit(this);
	text->setText("Player Turn");
	text->setReadOnly(true);
	text->move(550, 550);
	text->setFixedWidth(300);
	text->setFont(QFont("Arial", 20));
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
	if (tile->isPlayer() && !isPlayerTurn) {
		tile->setText("P");

	}
	else if (!tile->isPlayer() && isPlayerTurn) {
		tile->setText("E");
		isPlayerTurn = !isPlayerTurn;
		text->setText("Enemy Turn");
	}
}

void Battleship::placeEnemyShips() {
	for (int i = 0; i < 5; i++) {
		Ship* ship = new Ship();
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
			int x = rand() % 10;
			int y = rand() % 10;
			bool horizontal = (rand() % 2 == 0);
			bool isValid = true;
			if (horizontal) {
				if (x + ship->getLength() - 1 < 10) { // REPLACE 3 WITH SHIP LENGTH
					for (int j = 0; j < ship->getLength(); j++) {
						if (enemyBoard[x + j][y]->getShip() != nullptr) {
							isValid = false;
						}
					}
					if (isValid) {
						enemyShips[i] = ship;
						for (int j = 0; j < ship->getLength(); j++) {
							enemyBoard[x + j][y]->setText(ship->getText());
							enemyBoard[x + j][y]->setShip(ship);
						}
						break;
					}
				}
			}
			else {
				if (y + ship->getLength() - 1 < 10) { // REPLACE 3 WITH SHIP LENGTH
					for (int j = 0; j < ship->getLength(); j++) {
						if (enemyBoard[x][y + j]->getShip() != nullptr) {
							isValid = false;
						}
					}
					if (isValid) {
						for (int j = 0; j < ship->getLength(); j++) {
							enemyBoard[x][y + j]->setText(ship->getText());
							enemyBoard[x][y + j]->setShip(ship);
						}
						break;
					}
				}
			}
		}
	}
}