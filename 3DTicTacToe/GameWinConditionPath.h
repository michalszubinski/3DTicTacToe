#pragma once

#include "Game.h"

class GameWinConditionPath
{
public:
	// Paths
	std::set<Position> _positions;
	int _pathId;

	// Constructor
    GameWinConditionPath() = default;
	GameWinConditionPath(int id) : _pathId(id) {};

	// Methods
	bool checkIfPathWins(int xDim, int yDim, int zDim, int lowerBound, int winLength);

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

