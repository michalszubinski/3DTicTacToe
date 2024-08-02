#pragma once

#include "Libraries.h"
#include "Symbol.h"
#include "Position.h"

class Map {
public:
	// Fields
	std::map<Position, Symbol> _symbols;
	int _currentPlayer;
	int _xDimensions;
	int _yDimensions;

	// Constructor
	Map(int xDim, int yDim) : _xDimensions(xDim), _yDimensions(yDim) {};

	// Methods
	void GameStart();
	std::vector<Position> GetAllOccupiedPositions();		// Returns all occupied positions
	bool ValidatePosition();								// Checks whether position within bounds
};