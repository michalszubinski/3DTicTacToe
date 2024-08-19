#include "GameWinConditionPathSearcher.h"

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

std::vector<PointData> GameWinConditionPathSearcher::GetNearbyPositionsNoRepetition(Position centralPosition, std::vector<Position> positions, std::vector<Position> notAllowedPositions)
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


void GameWinConditionPathSearcher::GenerateSinglePathRecursive(PointData currentPointData, std::vector<PointData> pathPointData, std::vector<Position> pathPositions)
{
    std::vector<PointData> tmpPointDataVector = GetNearbyPositionsNoRepetition(currentPointData.pos, _allPositions, pathPositions);
    if (tmpPointDataVector.size() == 0) 
    {
        // add path
        _allPaths.insert( GameWinConditionPath(this->GetMaxId(), pathPointData));
    }
    else
    {
        for(auto& pointData : tmpPointDataVector)
        {
            pathPointData.push_back(pointData);
            pathPositions.push_back(pointData.pos);
            this->GenerateSinglePathRecursive(pointData, pathPointData, pathPositions); // call recursive
        }
    }
}

void GameWinConditionPathSearcher::GeneratePaths(Position position)
{
    std::vector<PointData> nearbyPointData = GetNearbyPositions(position, _allPositions);

    // Starting a path
    for (auto& nearbyPointData : nearbyPointData)
    {
        std::vector<PointData> pathPointData;
        std::vector<Position> pathPositions;
        pathPointData.push_back(PointData(position, Vector3d() ));
        pathPointData.push_back(nearbyPointData);
        pathPositions.push_back(position);
        pathPositions.push_back(nearbyPointData.pos);

        this->GenerateSinglePathRecursive(nearbyPointData, pathPointData, pathPositions);
    }
}