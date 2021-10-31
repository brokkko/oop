#pragma once
#include "Enemy.h"

class EnemyWizard : public Enemy {
public:
	EnemyWizard(std::string name, int H, int W, int Health, Map& map);

	void Generation(Map& map) override;
};