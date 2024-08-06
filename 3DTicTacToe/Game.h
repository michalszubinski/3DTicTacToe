#pragma once

#include "Libraries.h"
#include "Utilities.h"
#include "Map.h"
#include "GameWinConditionPath.h"
#include "GameWinConditionPathSearcher.h"

enum class GameState { IN_GAME, WIN, DRAW };

class Game
{
public:
	// Fields
	const int _lowerBound = 1;
	const int _xDim = 3;
	const int _yDim = 3;
	const int _zDim = 3;
	const int _winLength = 3;
	std::shared_ptr<Map> _map;
	bool _testing;
	bool _consoleMode;
	bool _isGameEnded;
	int _currentPlayer = 0;
	int _currentMove = 0;
	int _gameWinner = 0;
	

	// Constructor
	Game(bool testing = false, bool consoleMode = true) : _testing(testing), _consoleMode(consoleMode)
	{
		// Todo: insert game dimensions
		// Todo: variable win length
		_map = std::make_shared<Map>(Map(_xDim, _yDim, _zDim));
		_isGameEnded = false;
	}

	// Methods
	void StartGame();
	void PlayerTurn();
	Position PlayerDecideMove();					// In PlayerTurn
	bool ValidateMove(Position move);				// In PlayerTurn
	bool ValidateMoveWithinRange(Position move) const;
	bool ValidateMoveAlreadyExists(Position move);
	void ApplyMove(Position move);					// In PlayerTurn
	void ChangePlayer();							// In PlayerTurn
	void CheckForGameEnd();
};

