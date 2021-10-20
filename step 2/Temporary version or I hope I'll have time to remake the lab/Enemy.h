#pragma once
#include "Entity.h"

class Enemy : public Entity {

public:
	Enemy(std::string name, int H, int W, int PosX, int PosY, int health);
};