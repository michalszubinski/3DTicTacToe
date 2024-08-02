#pragma once

#include "Libraries.h"
#include "Map.h"

class Game
{
	// Fields
	const int _xDim = 3;
	const int _yDim = 3;
	std::shared_ptr<Map> _map;
	

	// Constructor
	Game()
	{
		_map = std::make_shared<Map>(_xDim, _yDim);
	}

	// Methods
	void StartGame();
	void PlayerTurn();
	void PlayerDecideMove();		// In PlayerTurn
	void ValidateMove();			// In PlayerTurn
	void ApplyMove();				// In PlayerTurn
	void ChangePlayer();			// In PlayerTurn
	void CheckForGameEnd();
};

