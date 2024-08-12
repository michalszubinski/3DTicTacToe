#pragma once

#include "Libraries.h"
#include "Game.h"
#include "Map.h"
#include "Position.h"

class Utilities
{
public: 

	static void PrintConsoleBoard(std::shared_ptr<Map> argMap);
	static Position InputCoordinatesConsole();
	static void ClearScreen();
};

