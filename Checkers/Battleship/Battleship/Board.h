#pragma once
#include "Tile.h"
#include <qstring.h>
#include <qobject.h>

class Board {
public:
	Board();
	virtual QString fire(int x, int y) = 0;
	virtual Tile* get(int x, int y) = 0;
	virtual void set(int x, int y, Tile* tile) = 0;
	virtual bool isGameOver() = 0;
protected:
	QWidget* parent;
};

class PlayerBoard : public Board {
public:
	PlayerBoard(QWidget* parent);
	virtual QString fire(int x, int y);
	virtual Tile* get(int x, int y);
	virtual void set(int x, int y, Tile* tile);
	virtual bool isGameOver();
private:
	PlayerTile* array[10][10];
};

class EnemyBoard : public Board {
public:
	EnemyBoard(QWidget* parent);
	virtual QString fire(int x, int y);
	virtual Tile* get(int x, int y);
	virtual void set(int x, int y, Tile* tile);
	virtual bool isGameOver();
private:
	EnemyTile* array[10][10];
};