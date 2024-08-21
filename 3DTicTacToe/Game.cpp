#include "Game.h"

void Game::StartGame()
{
	// Todo: Validate dimensions
	while (!this->_isGameEnded)
	{
		if (_consoleMode)
		{
			Utilities::ClearScreen();
			Utilities::PrintConsoleBoard(_map);
		}
		PlayerTurn();
		CheckForGameEnd();
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
}

Position Game::PlayerDecideMove()
{
	return Utilities::InputCoordinatesConsole();
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

	_map->_symbols[move] = symbol;
}

void Game::ChangePlayer()
{
	if (_currentPlayer == 0) _currentPlayer = 1;
	else					 _currentPlayer = 0;
}

void Game::CheckForGameEnd()
{
	char symbol = (_currentPlayer == 0) ? 'X' : 'O';
	std::vector<Position> positions = _map->GetAllOccupiedPositionsByPlayer(symbol);
	std::vector<GameWinConditionPath> gameWinConditionPaths;
	GameWinConditionPathSearcher winConditionPathSearcher(positions);

	// Checking for a draw
	if (_map->CountAllSymbols() == _volume)
		GameEndedDraw();

	// Checking for a win
	for (auto& position : positions)
		winConditionPathSearcher.GeneratePaths(position);
	
	for (auto path : winConditionPathSearcher._allPaths)
		if (path.CheckIfPathWins(_xDim, _yDim, _zDim, _lowerBound, _winLength) == true)
			GameEndedWin(_currentPlayer);

	return;
}

void Game::GameEndedWin(int currentPlayer)
{
	_gameWinner = currentPlayer;
	_isGameEnded = true;
	std::cout << "Game ended; Winner: " << currentPlayer << std::endl;
	// Todo: set the enum
}

void Game::GameEndedDraw()
{
	_isGameEnded = true;
	std::cout << "Game ended - draw" << std::endl;
	// Todo: set the enum
}
