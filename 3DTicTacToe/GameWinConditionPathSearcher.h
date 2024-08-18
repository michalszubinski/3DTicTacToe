#pragma once

#include "Game.h"
#include "GameWinConditionPath.h"

class GameWinConditionPathSearcher
{
public:
	// Fields
	std::vector<Position> _allPositions;
	std::set<GameWinConditionPath> _allPaths;
	int _maxId = 0;

	// Constructor
	GameWinConditionPathSearcher(std::vector<Position> positions) : _allPositions(positions) {};

	// Methods
	void GeneratePaths(Position position);
	int GetMaxId();
	std::vector<PointData> GetNearbyPositions(Position centralPosition ,std::vector<Position> positions);
	std::vector<PointData> GetNearbyPositions(Position centralPosition ,std::vector<Position> positions), std::vector<Position> notAllowedPositions;
	bool IsPossitionInVector(Position argPosition, std::vector<Position> positions);
};

