#pragma once

#include "Position.h"

class Symbol {
public:
	// Fields
	char _symbol;
	int _playerId = 0;
	int _moveHistoryId = 0;

	// Constructor
	Symbol() = default;
	Symbol(int playerId, int moveHistoryId) : _playerId(playerId), _moveHistoryId(moveHistoryId)
	{
		if (playerId == 0) _symbol = 'X';
		else			   _symbol = 'O';
	}

	// Methods

};