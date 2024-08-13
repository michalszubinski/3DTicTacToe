#pragma once

#include "Position.h"
#include "Vector3d.h"

struct PointData
{
    PointData() = default;
    PointData(Position pos, Vector3d vector) : pos(pos), vector(vector) {}

    Position pos;
    Vector3d vector;
};

class GameWinConditionPath
{
public:
	// Paths
	std::vector<PointData> _positions;
	int _pathId;

	// Constructor
    GameWinConditionPath() = default;
	GameWinConditionPath(int id) : _pathId(id) {};

	// Methods
	bool CheckIfPathWins(int xDim, int yDim, int zDim, int lowerBound, int winLength);

	// Operator overloads
    bool operator<(const GameWinConditionPath& rhs) const noexcept
    {
        return this->_pathId < rhs._pathId;
    }

    bool operator>(const GameWinConditionPath& rhs) const noexcept
    {
        return this->_pathId > rhs._pathId;
    }

    bool operator==(const GameWinConditionPath& rhs) const noexcept
    {
        return this->_pathId == rhs._pathId;
    }
};

