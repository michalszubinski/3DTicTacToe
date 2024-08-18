#include "GameWinConditionPathSearcher.h"

void GameWinConditionPathSearcher::GeneratePaths(Position position)
{
    std::vector<PointData> nearbyPositions = GetNearbyPositions(position, _allPositions);

    // Starting a path
    for (auto& nearbyPosition : nearbyPositions)
    {
        // Todo
    }
}

int GameWinConditionPathSearcher::GetMaxId()
{
    return ++_maxId;
}

std::vector<PointData> GameWinConditionPathSearcher::GetNearbyPositions(Position centralPosition, std::vector<Position> positions)
{
    std::vector<PointData> nearbyPositions;

    for (auto& position : _allPositions)
        if (abs(position.DiffX(centralPosition)) == 1 ||
            abs(position.DiffY(centralPosition)) == 1 ||
            abs(position.DiffZ(centralPosition)) == 1)
            nearbyPositions.push_back( PointData(position, Vector3d(position, centralPosition) ) );
        
    return nearbyPositions;
}

std::vector<PointData> GameWinConditionPathSearcher::GetNearbyPositions(Position centralPosition, std::vector<Position> positions, std::vector<Position> notAllowedPositions)
{
    std::vector<PointData> nearbyPositions;

    for (auto& position : _allPositions)
        if ((abs(position.DiffX(centralPosition)) == 1  ||
             abs(position.DiffY(centralPosition)) == 1  ||
             abs(position.DiffZ(centralPosition)) == 1) &&
             !IsPossitionInVector(position, notAllowedPositions))
            nearbyPositions.push_back( PointData(position, Vector3d(position, centralPosition) ) );
        
    return nearbyPositions;
}

bool GameWinConditionPathSearcher::IsPossitionInVector(Position argPosition, std::vector<Position> positions)
{
    for(auto& position : positions)
        if (argPosition == position) return true;
    
    return false;
}
