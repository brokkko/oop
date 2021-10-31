#pragma once
#include "Enemy.h"

class EnemyVarg : public Enemy {
public:
	EnemyVarg(std::string name, int H, int W, int Health, Map& map);

	void Generation(Map& map) override;
};
