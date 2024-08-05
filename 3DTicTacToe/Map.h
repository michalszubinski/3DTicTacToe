#pragma once

#include "Libraries.h"
#include "Symbol.h"
#include "Position.h"

class Map {
public:
	// Fields
	std::map<Position, Symbol> _symbols;
	int _currentPlayer = 0;
	int _xDimensions = 3;
	int _yDimensions = 3;
	int _zDimensions = 3;

	// Constructor
	Map() = default;
	Map(int xDim, int yDim, int zDim) : _xDimensions(xDim), _yDimensions(yDim), _zDimensions(zDim) {};

	// Methods
	void GameStart();
	std::vector<Position> GetAllOccupiedPositions();		// Returns all occupied positions
	bool ValidatePosition();								// Checks whether position within bounds
	bool CheckIfPositionExists(Position pos);
};