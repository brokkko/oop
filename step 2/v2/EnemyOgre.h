#pragma once
#include "Enemy.h"

class EnemyOgre : public Enemy {
public:
	EnemyOgre(std::string name, int H, int W, int Health, Map& map);

	void Generation(Map& map) override;
};
