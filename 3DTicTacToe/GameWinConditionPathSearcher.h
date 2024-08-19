#pragma once

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

public:
	// Methods
	int GetMaxId();
	std::vector<PointData> GetNearbyPositions(Position centralPosition, std::vector<Position> positions);
	std::vector<PointData> GetNearbyPositionsNoRepetition(Position centralPosition, std::vector<Position> positions, std::vector<Position> notAllowedPositions);
	bool IsPossitionInVector(Position argPosition, std::vector<Position> positions);
	void GenerateSinglePathRecursive(PointData currentPointData, std::vector<PointData> pathPointData, std::vector<Position> pathPositions);
	void GeneratePaths(Position position);
};

