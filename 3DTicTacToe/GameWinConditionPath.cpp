#include "GameWinConditionPath.h"

bool GameWinConditionPath::CheckIfPathWins(int xDim, int yDim, int zDim, int lowerBound, int winLength)
{
    // If path is not long enough
    if (_positions.size() > winLength) 
        return false;

    bool firstPosition = true;
    bool secondPosition = false;
    Vector3d secondVector;
    for (auto& position : _positions)
    {
        if (firstPosition)
        {
            if (firstPosition) secondPosition = true;
            firstPosition = false;
            continue;
        }
        else if (secondPosition)
        {
            secondVector = position.vector;
            secondPosition = false;
            continue;
        }
        else
        {
            if (secondVector != position.vector)
                return false;
        }
    }
    return true;
}
