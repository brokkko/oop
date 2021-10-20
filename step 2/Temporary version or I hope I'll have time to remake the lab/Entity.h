#pragma once
#include <iostream>

class Entity {
protected:
	double dx, dy, speed;
	float PositionX, PositionY;
	int EntityWidth, EntityHeight;

	int Health;
	bool Life;

	std::string Name;
	std::string Direction;

public:

	Entity(std::string name, int H, int W, float PosX, float PosY, int Health);

	Entity GetEntity();
	bool GetLife();
};