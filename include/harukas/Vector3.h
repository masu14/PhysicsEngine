#pragma once

#include <cmath>

class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	constexpr Vector3() noexcept
		: x(0.0f), y(0.0f), z(0.0f)
	{
	}

	constexpr Vector3(float x, float y, float z) noexcept
		:x(x), y(y), z(z)
	{
	}

};