#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity {
private:
	float SpeedControl;

public:
	Player(std::string name, int H, int W, float PosX, float PosY, int Health);

	float GetSpeedControl();
	void SetSpeedControl(float val);

};
