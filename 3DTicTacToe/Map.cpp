#include "Map.h"

bool Map::CheckIfPositionExists(Position pos)
{
	// If position exists returns true
	return (_symbols.find(pos) != _symbols.end());
}

std::vector<Position> Map::GetAllOccupiedPositionsByPlayer(char playerSymbol)
{
	std::vector<Position> positions;

	for (auto symbol : _symbols)
		if (symbol.second._symbol = playerSymbol)
			positions.push_back(symbol.first);

	return positions;
}

int Map::CountAllSymbols()
{
	return _symbols.size();
}
