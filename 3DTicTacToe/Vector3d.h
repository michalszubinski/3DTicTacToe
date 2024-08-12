#pragma once

#include "Position.h"

class Vector3d
{
public:
	// Fields
	int x;
	int y;
	int z;
	double length = 0;

public:
	// Constructor
	Vector3d() = default;
	Vector3d(int x, int y, int z) : x(x), y(y), z(z) { CalculateLength(); }
	Vector3d(Position pos2, Position pos1) { PositionDifference(pos2, pos1); }

	// Methods
	double PositionDifference(Position pos2, Position pos1)
	{
		this->x = pos2.GetX() - pos1.GetX();
		this->y = pos2.GetY() - pos1.GetY();
		this->z = pos2.GetZ() - pos1.GetZ();

		return CalculateLength();
	}

	double CalculateLength() { return sqrt((x ^ 2) + (y ^ 2) + (z ^ 2)); }

	// Operators

	bool operator==(const Vector3d& rhs) const noexcept
	{
		return (this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z);
	}

	bool operator!=(const Vector3d& rhs) const noexcept
	{
		return (this->x != rhs.x) || (this->y != rhs.y) || (this->z != rhs.z);
	}
};