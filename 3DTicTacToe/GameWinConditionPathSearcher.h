#pragma once

#include "Game.h"
#include "GameWinConditionPath.h"

class GameWinConditionPathSearcher
{
public:
	// Fields
	Position _startingPosition;
	std::vector<Position> _allPositions;
	std::set<GameWinConditionPath> _allPaths;
	int _maxId = 0;

	// Constructor
	GameWinConditionPathSearcher(std::vector<Position> positions) : _allPositions(positions) {};

	// Methods
	void GeneratePaths(Position position);
	int GetMaxId();
};

