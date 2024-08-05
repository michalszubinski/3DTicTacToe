#include "Map.h"

bool Map::CheckIfPositionExists(Position pos)
{
	// If position exists returns true
	return (_symbols.find(pos) != _symbols.end());
}
