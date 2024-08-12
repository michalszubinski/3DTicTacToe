#include "GameWinConditionPathSearcher.h"

void GameWinConditionPathSearcher::GeneratePaths(Position position)
{
    // Todo
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
