#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity {
protected:
	int Fullness; // сытость
	int Score;

public:
	Player(std::string name, int H, int W, float PosX, float PosY, int Health);
	void SetFullness(int value);
	int GetFullness();
	void SetScore(int value);
	int GetScore();

	//float GetPositionX();
	//float GetPositionY();

};
