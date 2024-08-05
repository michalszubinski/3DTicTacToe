#pragma once

#include "Libraries.h"
#include "Game.h"
#include "Map.h"
#include "Position.h"

class Utilities
{
public: 

	static void printConsoleBoard(std::shared_ptr<Map> argMap);
	static Position inputCoordinatesConsole();
};

