#pragma once

#include "Libraries.h"

class Position
{
private:
    // Fields
    int x;
    int y;
    int z;
    std::string comparison;
public:
	// Constructor
	Position()
	{
		x = 0;
		y = 0;
		z = 0;
        this->updateComparison();
	};

	Position(int x, int y, int z) : x(x), y(y), z(z) 
    {
        this->updateComparison();
    };

	void updateComparison();

    // Getters
    int GetX() const
    {
        return x;
    }

    int GetY() const
    {
        return y;
    }

    int GetZ() const
    {
        return z;
    }

    // Setters
    void SetX(int x)
    {
        this->x = x;
        this->updateComparison();
    }

    void SetY(int y)
    {
        this->y = y;
        this->updateComparison();
    }

    void SetZ(int z)
    {
        this->z = z;
        this->updateComparison();
    }

    // Utility methods

    int DiffX(int argX)
    {
        return this->x - argX;
    }

    int DiffY(int argY)
    {
        return this->y - argY;
    }

    int DiffZ(int argZ)
    {
        return this->z - argZ;
    }

    int DiffX(Position pos)
    {
        return this->x - pos.GetX();
    }

    int DiffY(Position pos)
    {
        return this->y - pos.GetY();
    }

    int DiffZ(Position pos)
    {
        return this->z - pos.GetZ();
    }

    // Operators overload

    bool operator<(const Position& rhs) const noexcept
    {
        return this->comparison < rhs.comparison;
    }

    bool operator>(const Position& rhs) const noexcept
    {
        return this->comparison > rhs.comparison;
    }

    bool operator==(const Position& rhs) const noexcept
    {
        return this->comparison == rhs.comparison; 
    }

    bool operator!=(const Position& rhs) const noexcept
    {
        return this->comparison != rhs.comparison;
    }
};

