#pragma once

#include "Tile.h"

Tile::Tile() {
	ship = nullptr;
}

Tile::Tile(QWidget* parent) : QPushButton(parent) {
	ship = nullptr;
}
