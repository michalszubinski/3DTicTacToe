#include "Game.h"

void Game::StartGame()
{
	// Todo: Validate dimensions
	while (!this->_isGameEnded)
	{
		if (_consoleMode) Utilities::printConsoleBoard(_map);
		PlayerTurn();
		ChangePlayer();
	}

}

void Game::PlayerTurn()
{
	Position proposedMove(0,0,0);

	while (true)
	{
		// Get position from player
		proposedMove = PlayerDecideMove();
		// If move is valid then apply and break from loop
		if (ValidateMove(proposedMove))
		{
			ApplyMove(proposedMove);
			break;
		}
	}
	CheckForGameEnd();
}

Position Game::PlayerDecideMove()
{
	return Utilities::inputCoordinatesConsole();
}

bool Game::ValidateMove(Position move)
{
	return ValidateMoveAlreadyExists(move) && ValidateMoveWithinRange(move);
}

bool Game::ValidateMoveWithinRange(Position move) const
{
	return (move.GetX() >= _lowerBound) && (move.GetX() <= _xDim)
		&& (move.GetY() >= _lowerBound) && (move.GetY() <= _yDim)
		&& (move.GetZ() >= _lowerBound) && (move.GetZ() <= _zDim);
}

bool Game::ValidateMoveAlreadyExists(Position move)
{
	// CheckIfPositionExists returns true if position does exist
	return !(_map->CheckIfPositionExists(move));
}

void Game::ApplyMove(Position move)
{
	++_currentMove;
	
	Symbol symbol(_currentPlayer, _currentMove);

	// DOES NOT COMPILE
	_map->_symbols[move] = symbol;
}

void Game::ChangePlayer()
{
	if (_currentPlayer == 0) _currentPlayer = 1;
	else					 _currentPlayer = 0;
}

void Game::CheckForGameEnd()
{
	// Todo
	return;
}
